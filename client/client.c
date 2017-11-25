#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

int main(int argc, char** argv) {
	if(argc != 3) {
		puts("Invalid number of arguments");
		exit(1);
	}

	int	sockfd;
	int	portno;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		puts("socket() error");
	}
	
	server = gethostbyname(argv[1]);
	if(server == NULL) {
		puts("No such host");
		exit(1);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));

	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
	portno = atoi(argv[2]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
		puts("connect() error");
		exit(1);
	}

	while(1) {
		printf("Please enter the message: ");
		bzero(buffer,256);
		fgets(buffer,255,stdin);

		n = write(sockfd,buffer,strlen(buffer));
		if(n < 0) {
			puts("write() error");
			exit(1);
		}

		bzero(buffer,256);

		n = read(sockfd,buffer,255);
		if(n < 0) {
			puts("read() error");
			exit(1);
		}

		printf("%s",buffer);
	}

	return 0;
}
