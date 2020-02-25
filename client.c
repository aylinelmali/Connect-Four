#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv){
	int clientfd;
	int port;
	char *host;
	if(argc != 4){
 		fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
 		exit(0);
	}
	host = argv[3];
	port = atoi(argv[2]);
	char *email = argv[1];
	struct hostent *hp;
	struct sockaddr_in serveraddr;
	if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1;
	if((hp = gethostbyname(host)) == NULL) return -2;
	bzero((char *)&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char *)hp->h_addr_list[0], (char *)&serveraddr.sin_addr.s_addr,
		hp->h_length);
	serveraddr.sin_port = htons(port);
	if(connect(clientfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) return -1;
	char message[40]; 
	snprintf(message, 40, "cs230 HELLO %s\n", email);
	printf("%s", message);
	if(send(clientfd, message, strlen(message), 0) < 0) return -1;
	char reply[100];
	if(recv(clientfd, reply, 100, 0) < 0) return -1;
	printf("%s", reply);
	int flagFound = 0;
	int num1;
	int num2;
	int numAns;
	while(flagFound == 0){
		char *ptr = strtok(reply, " ");
		ptr = strtok(NULL, " ");
		if(strcmp(ptr, "STATUS") != 0){
			flagFound = 1;
			break;}
		ptr = strtok(NULL, " ");
		num1 = atoi(ptr);
		ptr = strtok(NULL, " ");
		char *op = ptr;
		ptr = strtok(NULL, "\n");
		num2 = atoi(ptr);
		if(strcmp(op, "+") == 0){numAns = num1 + num2;}
		else if(strcmp(op, "-") == 0){numAns = num1 - num2;}
		else if(strcmp(op, "*") == 0){numAns = num1 * num2;}
		else{numAns = num1 / num2;}
		snprintf(message, 40, "cs230 %i\n", numAns);
		printf("%s", message);
		if(send(clientfd, message, strlen(message), 0) < 0) return -1;
		if(recv(clientfd, reply, 100, 0) < 0) return -1;
		printf("%s", reply);
	}
	close(clientfd);
	exit(0);
}