#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>
#include<unistd.h>
/* The semaphore key is an arbitary long interger which is serves as an external identifier by which the semaphore is known to any program that wishes to use it.*/
#define KEY (1492)

void main() {
    int id;

    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        //ushort * array
    } argument;

    argument.val = 1;
    //argument.val = 2;
    /* Create the semaphore with external key KEY if it doesn't already exists. Give permission to the world.*/

    id = semget(KEY, 1, 0666 | IPC_CREAT);

    if(id < 0) {
        printf(stderr, "Unable to obtain semaphore.\n");
        exit(0);
    }

    if(semctl(id, 0, SETVAL, argument) < 0) {
        fprintf(stderr, "Cannot set semaphore value.\n");
    }
    else {
        fprintf(stderr,"Semaphore %d initialized.\n", KEY);
    }
}