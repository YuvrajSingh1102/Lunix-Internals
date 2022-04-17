#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *myinit()
{
    printf("\nI am in my thread: %d\n ");
    printf("\n Exit from mythread : %d\n",(int *)1);
}
int main()
{
    pthread_t thread,thread1,thread2;
    pthread_t pthread_self();
    printf("The thread id is:%d\n",pthread_self());
    printf("The pid of process is:%d\n",getpid());

return 0;
}



































