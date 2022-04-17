#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<string.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void toggleCase(char *buf, int cnt);

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};

union semun sem_union;

int main() {
    int semId, shmId;
    char *pShm;
    struct sembuf smop;

    semId = semget(MY_KEY, 1, 0644|IPC_CREAT);

    if(semId < 0) {
        printf("Could not create semaphore\n");
        return (1);
    }
    else 
    {
        printf("Opened a semaphore Id is %d\n", semId);
    }

    semctl(semId, 0, SETVAL, 0);

    shmId = shmget(MY_KEY, SHM_SIZE, 0660 | IPC_CREAT);

    if(shmId < 0) {
        printf("Could not create shared segment \n");
        return (2);
    }

    pShm = shmat(shmId, NULL, 0);
    if(!pShm) {
        printf("Could not attach shared memory segment,\n");
        return (3);
    }

    while(1) {
        smop.sem_num = 0;
        smop.sem_op = -1;
        smop.sem_flg = 0;

        semop(semId, &smop, 1);

        //printf("Got the semaphore\n");

        printf("Got the semaphore\n");
        strcpy(pShm+256, pShm);
        toggleCase(pShm+256, strlen(pShm+256));
        printf("Processed the request message and placed response\n");

        smop.sem_num = 0;
        smop.sem_op = 1;
        smop.sem_flg= 0;

        semop(semId, &smop, 1);
    }

    return 0;
}

void toggleCase(char *buf, int cnt) {
    int ii;
    for(ii = 0; ii < cnt; ii++) {
        if((buf[ii] >= 'A') && (buf[ii] <= 'Z'))
            buf[ii] += 0x20;
        else if((buf[ii] >= 'a') && (buf[ii] <= 'z'))
            buf[ii] -= 0x20;
    } 
}