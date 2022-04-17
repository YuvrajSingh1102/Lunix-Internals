#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

static void* threadFunc(void *arg)
{
    char *s = (char *) arg;
    printf("%s\n",s);
    sleep(5);
}
int main(int argc, char *argv[])
{
    pthread_t t1;
    void *res;
    int s;
    pthread_create(&t1,NULL,threadFunc,"Hello World");
    printf("Messages from main()\n");
    pthread_join(t1,&res);
    printf("thread returned %d",(long)res);
    exit(0);

    return 0;

}

