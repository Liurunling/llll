/*************************************************************************
	> File Name: client1.c
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Fri 10 Jul 2020 05:32:54 AM CST
 ************************************************************************/

#include "head.h"

int server_port = 0;
char server_ip[20] = {0};
int team = -1;
char name[20] = {0};
char log_msg[512] = {0};
char *conf = "./football.conf";
int sockfd = -1;

int main(int argc, char **argv) {
        int opt;
        struct LogRequest request;
        struct LogResponse response;
    while ((opt = getopt(argc, argv, "h:p:t:m:n:")) != -1) {
        switch (opt) {
                        case 't':
                            request.team = atoi(optarg);
                            break;
                        case 'h':
                            strcpy(server_ip, optarg);
                            break;
                        case 'p':
                            server_port = atoi(optarg);
                            break;
                        case 'm':
                            strcpy(request.msg, optarg);
                            break;
                        case 'n':
                            strcpy(request.name, optarg);
                            break;
                        default:
                            fprintf(stderr, "Usage : %s [-hptmn]!\n", argv[0]);
                            exit(1);
                    
        }
            
    }
        

        if (!server_port) server_port = atoi(get_conf_value(conf, "SERVERPORT"));
        if (!team) team = atoi(get_conf_value(conf, "TEAM"));
        if (!strlen(server_ip)) strcpy(server_ip, get_conf_value(conf, "SERVERIP"));
        if (!strlen(name)) strcpy(request.name, get_conf_value(conf, "NAME"));
        if (!strlen(log_msg)) strcpy(request.msg, get_conf_value(conf, "LOGMSG"));


        DBG("<"GREEN"Conf Show"NONE"> : server_ip = %s, port = %d, team = %s, name = %s\n%s",\
                   server_ip, server_port, team ? "BLUE": "RED", request.name, request.msg);

        struct sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(server_port);
        server.sin_addr.s_addr = inet_addr(server_ip);

        socklen_t len = sizeof(server);

    if ((sockfd = socket_udp()) < 0) {
                perror("socket_udp()");
                exit(1);
            
    }
    
        sendto(sockfd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&server, len);
            fd_set rfds;
                FD_ZERO(&rfds);
                    FD_SET(sockfd, &rfds);
                        struct timeval tv;
                            tv.tv_sec = 5;
                                tv.tv_usec = 0;
                                    int ret = select(sockfd + 1, &rfds, NULL, NULL, &tv);
                                    if (ret < 0) {
                                                perror("select()");
                                                close(sockfd);
                                                exit(1);
                                            
                                    } else if (ret == 0){
                                                printf("time over\n");
                                                close(sockfd);
                                                exit(1);
                                            
                                    } else {
                                                ssize_t ret;
                                                ret = recvfrom(sockfd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&server, &len);
                                        if (ret <= 0) {
                                                        close(sockfd);
                                                        perror("recvform()");
                                                    
                                        } else if(response.type == 1) {
                                                        printf("%s", response.msg);
                                                        close(sockfd);
                                                    
                                        } else {
                                                        ret = connect(sockfd, (struct sockaddr *)&server, len);
                                            if (ret < 0) {
                                                                perror("connect()");
                                                                close(sockfd);
                                                                exit(1);
                                                            
                                            } else {
                                                                char send_msg[20] = "hello hxd";
                                                                send(sockfd, send_msg, strlen(send_msg), 0);
                                                            
                                            }
                                                    
                                        }
                                            
                                    }
                                        close(sockfd);
                                            return 0;

}
