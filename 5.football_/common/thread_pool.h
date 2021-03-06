/*************************************************************************
	> File Name: thread_pool.h
	> Author:Lrl: 
	> Mail:nothing 
	> Created Time: Fri 10 Jul 2020 03:22:12 AM CST
 ************************************************************************/
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
struct task_queue{
    int sum;
    int spollfd;
    struct User **team;
        int head;
        int tail;
        pthread_mutex_t mutex;
        pthread_cond_t cond;
};

void task_queue_init(struct task_queue *taskQueue, int sum, int epollfd);
void task_queue_push(struct task_queue *taskQueue, struct User *user);
struct User *task_queue_pop(struct task_queue *taskQueue);
void *thread_run(void *arg);







#endif
