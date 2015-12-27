#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

using namespace std;

#define MAXLINE 4096
#define OPEN_MAX 100
#define LISTENQ 20
#define SERV_PORT 5000
#define INFTIM 1000

int main(int argc, char **argv)
{
    int                    sockfd;
    char                recvline[50000];
    struct sockaddr_in    servaddr;

    if (argc != 2){
        printf("usage: a.out <IPaddress>");
        exit(0);
    }

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("socket error");
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(5000);   
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("inet_pton error for %s", argv[1]);
        exit(0);
    }
    printf("ip:%u\n",servaddr.sin_addr.s_addr);
    printf("server ip:%s\n",inet_ntoa(servaddr.sin_addr));
    
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0){
        printf("connect error");
        exit(0);
    }

    char input[100];
    while (fgets(input, 100, stdin) != NULL)
    {
        write(sockfd, input, strlen(input));

        int n = 0;
        int count = 0;
        while (1)
        {
            n = read(sockfd, recvline + count, MAXLINE);
            printf("%d\n",n);
            if (n == MAXLINE)
            {
                count += n;
            }
            else 
                break;
        }
        printf("%s\n", recvline);
    }
    exit(0);
}
