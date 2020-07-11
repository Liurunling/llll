/*************************************************************************
	> File Name: 1.multi_process.c
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Wed 08 Jul 2020 12:37:46 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    int opt,flag = 0;
    char msg[512]={0};
    while((opt = getopt(argc, argv, "m:"))!= -1){
        switch(opt){
            case 'm':
                flag = 1;
                strcpy(msg,optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -m msg\n",argv[0]);
                exit(1);//0-correct
        }
    }
    if(flag){
        printf("msg = %s\n",msg);
        exit(0);
    }
    pid_t pid;
    if((pid = fork()) < 0){
        printf("fork()");
    }
    if(pid == 0){
        printf("IN Child Process!\n");
    }else {
        printf("Waiting for Child exit.\n");
        wait(NULL);
        
    }
    return 0; 
}
