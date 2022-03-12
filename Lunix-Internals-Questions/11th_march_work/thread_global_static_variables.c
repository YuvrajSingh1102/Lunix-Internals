//in output use -o glo -lpthread     ./glo

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedVar = 5;


void *thread_inc(void *arg) {
    sharedVar++;
    printf(" after increment =%d\n", sharedVar);
}

void *thread_dec(void *arg) {
    sharedVar--;
    printf(" after decrement =%d\n", sharedVar);
}
int main(){

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_inc, NULL);
    pthread_create(&thread2, NULL, thread_dec, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("sharedvar = %d \n", sharedVar);
    return 0;
}