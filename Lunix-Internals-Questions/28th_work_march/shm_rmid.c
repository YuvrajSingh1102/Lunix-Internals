#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

//#define KEY 8979

int main() {

    int shmid;
    struct shmid_ds buf;
    shmid = shmget(48, 250, IPC_CREAT|0644);
    printf(" qid = %d\n", shmid);
    shmctl(shmid, IPC_RMID, NULL);
    /*
    printf(" Here are the details of the queue\n");
    printf("No. of msg's in q %hi\n", buf.msg_qnum);
    //printf("No. of bytes in q %d\n", buf.msg_cbytes);
    printf("Max no of bytes in q %hi\n", buf.msg_qbytes);
    */
   return 0;
   
}