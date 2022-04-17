#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<unistd.h>

int get_semaphore(void);
int release_semaphore(void);
int sem_id;

union semnum {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *_buf;
};

struct sembuf sem_op;
union semnum sem_union;

int main() {
    int i,j;

    sem_id = semget((key_t)1234, 1, 0666|IPC_CREAT);

    for(i = 0; i <= 5; i++) {
        get_semaphore();
        printf("\n SEM2:%d: got the semaforce\n", getpid());

        for(int j = 0; j <= 3;j++) {
            sleep(1);
            printf("\a");
        }
        
        printf("\nSEM2:%d: release the semaforce\n", getpid());
        release_semaphore();
        sleep(2);
    }

    if(semctl(sem_id, 0, IPC_RMID, sem_union) < 0)
    printf("Unable delete semaphore\n");
    else
    printf("Semaphore delted\n");

    return 0;
}

int get_semaphore(void) {
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sem_op, 1) < 0){
    printf("failed ot get semaphore\n");
    return -1;
    }
    return 0;
}

int release_semaphore(void) {
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sem_op, 1) < 0) {
        printf("failed\n");
        return -1;
    }
    return 0;
}

