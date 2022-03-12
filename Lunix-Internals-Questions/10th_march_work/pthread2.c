#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void *start_one(void *arg) {
    int i;
    for(i = 0; i < 1000; i++)
    printf("thread of con 1\n");
}

void *start_two(void *arg) {
    int i;
    for(i = 0; i < 1000; i++)
    printf("**thread of con 1\n");
}
int main() {
    pthread_t pt1, pt2;
    getchar();
    pthread_create(&pt1, NULL, start_one, NULL);
    pthread_create(&pt2, NULL, start_two, NULL);
    getchar();
    printf("end of the main thread \n");

    return 0;                
    }