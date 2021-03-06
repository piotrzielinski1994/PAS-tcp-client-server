#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "operations.h"

int main(int argc, char** argv) {
	system("clear");
	if(argc != 2) {
		puts("Invalid number of arguments");
		exit(1);
	}

	int	sockfd;
	int	newsockfd;
	int	portno;
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	socklen_t clilen;
	char buffer[256];
	int n;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
         puts("socket() error");
         exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        puts("bind() error");
        exit(1);
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    int pid;
    while (1) {
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0) {
			puts("accept() error");
			exit(1);
		}

		printf("Opened socket: %d\n", newsockfd);

		pid = fork();
		if(pid < 0) {
			puts("fork() error");
			exit(1);
		} else if(pid == 0) {
			while(1) {
				bzero(buffer, 256);

				n = read(newsockfd, buffer, 255);
				if(n < 0) {
					puts("read() error");
					exit(1);
				}

				if(n == 0) {
					printf("Closing socket: %d\n", newsockfd);
					close(newsockfd);
					break;
				}

				char** tempString = str_split(buffer, '\n');
				char** splittedString = str_split(tempString[0], ' ');
				free(tempString);
				int size = getSize(splittedString);
				
				char* output=operation(splittedString, size);

				free(splittedString);

				n = write(newsockfd, output, strlen(output));
				if(n < 0) {
					puts("write() error");
					exit(1);
				}
			}
		} else {

		}
    }

	return 0;
}
