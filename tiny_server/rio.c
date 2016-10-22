#include "csapp.h"

/*typedef struct
{
	int rio_fd;
	int rio_cnt;
	char *rio_bufptr;
	char rio_buf[RIO_BUFSIZE];
}rio_t; */

int open_listenfd(int port)
{
	int listenfd, optval=1;
	struct sockaddr_in serveraddr;
	if ((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		return -1;
	if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR,
			(const void *)&optval, sizeof(int)) < 0)
		return -1;
	
	bzero((char *) &serveraddr, sizeof(serveraddr));
	//i add
	//printf("netword address: %u\n", htonl(INADDR_ANY));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons((unsigned short)port);
	if (bind(listenfd, (SA *)&serveraddr, sizeof(serveraddr)) < 0)
		return -1;
	if (listen(listenfd, LISTENQ) < 0)
		return -1;
	return listenfd;
}
	

void rio_readinitb(rio_t *rp,int fd)
{
	rp->rio_fd = fd;
	rp->rio_cnt = 0;
	rp->rio_bufptr = rp->rio_buf;
}

ssize_t rio_readn(int fd,void *usrbuf, size_t n)
{
	size_t nleft =n;
	ssize_t nread;
	char *bufp = usrbuf;

	while (nleft > 0) {
		if ((nread = read(fd, bufp, nleft)) < 0) {
			if (errno == EINTR) 
				nread = 0;
			else 
				return -1;
		}
		else if (nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}

ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nwritten;
	char *bufp = usrbuf;

	while (nleft > 0) {
		if ((nwritten = write(fd, bufp, nleft)) <= 0) {
			if (errno == EINTR)
				nwritten = 0;
			else 
				return -1;
		}
		nleft -= nwritten;
		bufp += nwritten;
	}
	return n;
}

static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n)
{
	int cnt;

	while (rp->rio_cnt <= 0) {
		rp->rio_cnt = read(rp->rio_fd, rp->rio_buf, sizeof(rp->rio_buf));
		if (rp->rio_cnt < 0) {
			if (errno != EINTR)
				return -1;
		}
	else if (rp->rio_cnt == 0)
		return 0;
	else 
		rp->rio_bufptr = rp->rio_buf;
	}

	cnt = n;
	if (rp->rio_cnt < n)
		cnt = rp->rio_cnt;
	memcpy(usrbuf, rp->rio_bufptr, cnt);
	rp->rio_bufptr += cnt;
	rp->rio_cnt -= cnt;
	return cnt;
}	

ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen)
{
	int n, rc;
	char c,*bufp = usrbuf;
	for (n=1; n < maxlen; n++) {
		if ((rc = rio_read(rp, &c, 1)) == 1) {
			*(bufp++) = c;
			if (c == '\n') 
				break;
		}
		else if ( rc ==0) {
			if (n == 1)
				return 0;
			else 
				break;
		}
		else 
			return -1;
	}
	*bufp = 0;
	return n;
}

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *bufp = usrbuf;

	while (nleft > 0) {
		if ((nread = rio_read(rp, bufp, nleft)) < 0) {
			if (errno == EINTR)
				nread = 0;
			else 
				return -1;
		}
		else if (nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}



			


