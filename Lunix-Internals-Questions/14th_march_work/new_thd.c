#include<stdio.h>
#include<pthread.h>

void * process(void *arg) {

    printf("Sleeping 2 sec\n");
    sleep(2);
    printf("slept 2 secs\n");

}
int main() {

        pthread_t t_id;
        pthread_create(&t_id, NULL,process,NULL);

        pthread_exit(NULL);

    return 0;
}