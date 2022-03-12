//in output use -o glo -lpthread     ./glo

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


void *printHello(void *threadid) {
    
    printf("\nHeloo world\n");
}

int main(){

    pthread_t thread;
    int rc, t = 0;
    printf("Creating the thread\n");

    rc = pthread_create(&thread, NULL, printHello, NULL);

    printf("\nThread id : %u", thread);
    sleep(6);

    if(t==0) {
        printf("\nCanceled thread \n");
    }
    printf("\nThread id: %u\n", thread);

    return 0;
}