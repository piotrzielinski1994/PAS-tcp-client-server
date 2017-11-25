#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#include "operations.h"

int splitString(char* stringTab, char** returnTab);

int main(int argc, char** argv) {
	/*char** zxc = malloc(0);
	zxc[0] = "add";
	zxc[1] = "1";
	zxc[2] = "3";
	zxc[3] = "5";
	
	double temp[3];//] = malloc(0);;
	parseDouble(zxc, temp, 4);//asc_sorting(splittedArray, size);
	for(int i = 0; i<3; i++) {
		printf("%f\n", temp[i]);
	}
	return 0;*/
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

				//printf("\tMessage from socket %d: %s\n", newsockfd, buffer);
				char** splittedArray = malloc(0);
				int size = splitString(buffer, splittedArray);
				// for(int i = 0; i<size; i++) {
				// 	printf("%s\n", splittedArray[i]);
				// }
				char* output = operation(splittedArray, size);
				//puts(output);
				free(splittedArray);

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

int splitString(char* stringTab, char** returnTab){
	char* p = strtok(stringTab, " ");
	int n_spaces = 0;

	while(p) {
		returnTab = realloc(returnTab, sizeof(char*) *++n_spaces);

		if(returnTab == NULL) {
			exit(1);
		}
		
		returnTab[n_spaces-1] = p;

		p = strtok (NULL, " ");
	}

	return n_spaces;
}