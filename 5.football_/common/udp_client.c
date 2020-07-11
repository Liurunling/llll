/*************************************************************************
	> File Name: udp_client.c
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Fri 10 Jul 2020 03:25:47 AM CST
 ************************************************************************/

#include "head.h"

int socket_udp() {
        int fd;
        
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
                return -1;
            
    }
        return fd;

}
