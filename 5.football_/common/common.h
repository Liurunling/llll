/*************************************************************************
	> File Name: common.h
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Wed 08 Jul 2020 02:58:21 AM CST
 ************************************************************************/
#ifndef _COMMON_H
#define _COMMON_H
char *get_conf_value(const char* path, const char *key);
int socket_create(int port);
void make_non_block(int fd);
void make_block(int fd);
#ifdef _D
#define DBG(fmt, args...) printf(fmt, ##args)
#else
#define DBG(fmt, args...)
#endif

#endif
