/*************************************************************************
	> File Name: client.c
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Fri 10 Jul 2020 01:42:04 AM CST
 ************************************************************************/

#include "head.h"
#include "common.h"
#include "color.h"
int server_port = 0;
char server_ip[20] = {0};
int team = -1;
char name[20] = {0};
char log_msg[512]={0};
char *conf = "./football.conf";

int main(int argc, char **argv){
    int opt;
    while((opt = getopt(argc, argv, "h:p:t:m:n")) != -1){
        switch(opt){
            case 't':
                team = atoi(optarg);
                break;
            case 'h':
                strcpy(server_ip, optarg);
                break;
            case 'p':
                server_port=atoi(optarg);
                break;
            case 'm':
                strcpy(log_msg, optarg);
                break;
            case 'n':
                strcpy(name, optarg);
                break;
            default:
            exit(1);
        }
    }
    //add judge 
    if(!server_port)
    server_port = atoi(get_conf_value(conf, "SERVERPORT"));
    if(!team) 
    team=atoi(get_conf_value(conf,"TEAM"));
    if(!strlen(server_ip))
    strcpy(server_ip, get_conf_value(conf, "SERVERIP"));
    if(!strlen(name))
    strcpy(name, get_conf_value(conf, "NAME"));
    if(!strlen(log_msg)) 
    strcpy(server_ip, get_conf_value(conf, "LOGMSG"));

    DBG("<"GREEN"Conf Show"NONE">: server_ip = %s, port= %s, name = %s\n",server_ip,server_port,team?"BLUE":"RED");
    return 0;
}

