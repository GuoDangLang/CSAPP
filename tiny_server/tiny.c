#include "csapp.h"

void doit(int fd);
void read_requesthdrs(rio_t *rp);
int parse_uri(char *uri, char *filename, char *cgiargs);
void serve_static(int fd, char *filename, int filesize, char* method); //i add method
void get_filetype(char *filename, char *filetype);
void serve_dynamic(int fd, char *filename, char *cgiargs, char* method);//i add method too
void clienterror(int fd, char *cause, char *errnum, char *shortmsg, 
		char *longmsg);

typedef struct sockaddr SA;

void unix_error(char *msg) {
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
}

void handler(int sig) {
	pid_t pid;
	while ((pid = waitpid(-1, NULL, 0)) > 0)
		;
	if (errno != ECHILD) 
		unix_error("waitpid error");
	return;
}

int main(int argc, char *argv[]) { int listenfd, connfd, port, clientlen;
	struct sockaddr_in clientaddr;
	if (signal(SIGCHLD, handler) == SIG_ERR)
		unix_error("signal error");

	if (argc != 2) {
		fprintf(stderr,"usage: %s <port>\n", argv[0]);
		exit(1);
	}
	port = atoi(argv[1]);

	listenfd = open_listenfd(port);
	while(1) {
		clientlen = sizeof(clientaddr);
		connfd = accept(listenfd, (SA *) &(clientaddr), (socklen_t *)&clientlen);
		doit(connfd);
		close(connfd);
	}
}

void doit(int fd)
{
	int is_static;
	struct stat sbuf;
	char buf[MAXLINE],method[MAXLINE], uri[MAXLINE], version[MAXLINE];
	char filename[MAXLINE], cgiargs[MAXLINE];
	rio_t rio;
	
	rio_readinitb(&rio, fd);
	rio_readlineb(&rio, buf, MAXLINE);
	sscanf(buf,"%s %s %s", method, uri, version);
	if ((strcasecmp(method,"GET")) && (strcasecmp(method, "HEAD")) && (strcasecmp(method, "POST"))) {
		clienterror(fd, method, "501", "not Implement", 
				"Tiny does not implement this method");
		return;
	}
	printf("%s", buf);
	read_requesthdrs(&rio);
	// I don't know if it is right;
	if(!(strcasecmp(method, "POST"))) {
		char temp[MAXLINE];
		rio_readlineb(&rio, temp, MAXLINE);
		strcat(uri, "?");
		strcat(uri, temp);
	}

	is_static = parse_uri(uri, filename, cgiargs);
	if(stat(filename,&sbuf)<0) {
		clienterror(fd, filename, "404", "Not found", 
				"Tiny couldn't find the file");
		return;
	}

	if(is_static) {
		if(!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
			clienterror(fd, filename, "403", "Fobidden", "Tiny conldn't read the file");
			return;
		}
		serve_static(fd, filename, sbuf.st_size, method);
	}
	else {
		if (!(S_ISREG(sbuf.st_mode)) || !(S_IXUSR & sbuf.st_mode)) {
			clienterror(fd, filename, "403", "Forbidden", "Tiny couldn't run the CGI program"					);
			return;
		}
		serve_dynamic(fd, filename, cgiargs, method);
	}
}

void clienterror(int fd, char *cause, char *errnum, char *shortmsg, char *longmsg)
{
	char buf[MAXLINE], body[MAXLINE];

	sprintf(body, "<html><title>Tiny Error</title>");
	sprintf(body, "%s<body bgcolor=""ffff"">\r\n",body);
	sprintf(body,"%s%s: %s\r\n", body, errnum, shortmsg);
	sprintf(body,"%s<p>%s: %s\r\n",body, longmsg, cause);
        sprintf(body, "%s<hr><em>The Tiny Web server</em>\r\n",body);

	sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum, shortmsg);
	rio_writen(fd, buf, strlen(buf));
	sprintf(buf, "Content-type: text/heml\r\n");
	rio_writen(fd, buf, strlen(buf));
	sprintf(buf, "Content-length: %d\r\n\r\n", (int)strlen(body));
	rio_writen(fd, buf,strlen(buf));
	rio_writen(fd, body, strlen(body));
}	

 void read_requesthdrs(rio_t *rp)
{
	char buf[MAXLINE];

	while(strcmp(buf, "\r\n")) {
		strcpy(buf, "");
		rio_readlineb(rp,buf,MAXLINE);
		printf("%s",buf);
	}
	return;
}
/* void print_request(rio_t *rp) {
	char request[MAXLINE];
	while (strcmp(request, "\r\n")) {
		rio_readlineb(rp, request, MAXLINE);
		printf("%s", request);
	}
	return;
}*/

int parse_uri(char *uri, char *filename, char *cgiargs)
{
	char *ptr;
	strcpy(filename, ""); // To clear filename every time parse same obj;
	if(!(strstr(uri,"cgi-bin"))) {
		strcpy(cgiargs,"");
		strcpy(filename,".");
		strcat(filename,uri);
		if(uri[strlen(uri)-1] == '/') 
			strcat(filename,"home.html");
		return 1;
	}
	else {
		ptr = index(uri,'?');
		if (ptr) {
			strcpy(cgiargs,ptr+1);
			*ptr = '\0';
		}
		strcpy(filename,".");
		strcat(filename, uri);
		return 0;
	}
}

void serve_static(int fd,char *filename, int filesize, char* method)
{
	int srcfd;
	char *srcp, filetype[MAXLINE], buf[MAXBUF];

	get_filetype(filename,filetype);
	sprintf(buf, "HTTP/1.0 200 OK\r\n");
	sprintf(buf, "%sServer: Tiny web Server\r\n", buf);
	sprintf(buf, "%sContent-length: %d\r\n", buf, filesize);
	sprintf(buf, "%sContent-type: %s\r\n\r\n", buf, filetype);
	rio_writen(fd, buf, strlen(buf));

	if(strcasecmp(method, "HEAD")) {
		char *srcp = malloc(MAXLINE * sizeof(char));
	       	srcfd = open(filename, O_RDONLY, 0);
		rio_readn(srcfd, srcp, filesize);
	       	//srcp = mmap(0, filesize, PROT_EXEC, MAP_PRIVATE, srcfd, 0);
		// PROT_READ (original)
	       	close(srcfd);
	       	rio_writen(fd, srcp, filesize);
	       	munmap(srcp, filesize);
       	}
}

void get_filetype(char *filename, char *filetype)
{
	if (strstr(filename, ".html"))
		strcpy(filetype,"text/heml");
	else if (strstr(filename,".gif"))
		strcpy(filetype,"image/gif");
	else if (strstr(filename,".jpg"))
		strcpy(filetype,"image/jpg");
	else if (strstr(filename,".mp4"))
		strcpy(filetype,"video/mp4");
	else if (strstr(filename,".mp3"))
		strcpy(filetype,"audio/mpeg");
	else 
		strcpy(filetype,"text/plain");
}

void serve_dynamic(int fd, char *filename, char *cgiargs, char *method)
{
	char buf[MAXLINE], *emptylist[] = {filename, method, NULL };

	sprintf(buf, "HTTP/1.0 200 OK\r\n");
	rio_writen(fd, buf, strlen(buf));
	sprintf(buf, "Server: Tiny Web Server\r\n");
	rio_writen(fd, buf, strlen(buf));

	if(fork() == 0) {
		setenv("QUERY_STRING",cgiargs,1);
		dup2(fd, STDOUT_FILENO);
		execve(filename, emptylist, environ);
	}
	//wait(NULL);
}
		
			


