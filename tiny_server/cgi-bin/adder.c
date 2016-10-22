#include "csapp.h"

int main(int argc, char* argv[]) {
	char *buf, *p, *temp;
	char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
	int n1 = 0; 
	int n2 = 0;

	if ((buf = getenv("QUERY_STRING")) != NULL) {
		p = strchr(buf, '&');
		*p = '\0';
		strcpy(arg1, buf);
		strcpy(arg2, p+1);
		char a[MAXLINE], b[MAXLINE];
		if ((p = strchr(arg1, '=')) != NULL){
			strcpy(a, p + 1);
			n1 = atoi(a);
		}
		if ((p = strchr(arg2, '=')) != NULL) {
			strcpy(b, p + 1);
			n2 = atoi(b);
	       	}
		else {
		       	n1 = atoi(arg1);
		       	n2 = atoi(arg2);
		}
	}

	sprintf(content, "Welcome to add.com: ");
	sprintf(content, "%sThe Internet addition portal.\r\n<p>", content);
	sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>",
			content, n1, n2, n1 + n2);
	sprintf(content, "%sThanks for visitiong!\r\n", content);

	printf("Content-length: %d\r\n", (int)strlen(content));
	printf("Content-type: text/html\r\n\r\n");
	if (strcasecmp(argv[1], "HEAD")) {
	       	printf("%s", content);
	       	fflush(stdout);
	       	exit(0);
		}
}
