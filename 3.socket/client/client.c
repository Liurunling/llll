/*************************************************************************
	> File Name: client.c
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Wed 08 Jul 2020 12:55:29 PM CST
 ************************************************************************/

#include "head.h"

int main( int argc, char *argv[] ){
    char ip[20] = {0};
    int port = 0, sockfd, value;
    char buff[512] = {0};
    struct sockaddr_in server;
    if(argc != 3){
        fprintf(stderr, "Usage : %s ip port!\n",argv[0]);
        exit(1);
    }
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket()");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);
    if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("connect");
        exit(1);
    }
    while(1){
        recv(sockfd, &value, sizeof(value),0);
        printf("Recv Msg: %d\n",value);
        if(value == 1) sprintf(buff, "2019302180193");
        if(value == 2) sprintf(buff,"刘润凌");
        if(value == 3) break;
        send(sockfd, buff, strlen(buff), 0);
    }
close(sockfd);
    return 0;

}
