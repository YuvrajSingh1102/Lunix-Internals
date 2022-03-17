#include <stdio.h>
#include <pthread.h>

void *my(void *i) {
    printf("\n I am in %d thread \n", (int *)i);
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    struct sched_param param;
    int priority, policy,ret;

    ret = pthread_getschedparam(pthread_self(), &policy, &param);

    print("\n----------------Main thread--------------\n Ploicy : %d \tPrority : %d\n", policy, param.sched_prority);

    policy = SCHED_FIFO;
    param.sched_priority = 3;
    pthread_setschedparam(pthread_self(), policy, &param);

    pthread_getschedparam(pthread_self(), policy, &param);

    print("\n----------------Main thread--------------\n Ploicy : %d \tPrority : %d\n", policy, param.sched_prority);

    return (0);
}