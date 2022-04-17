#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf {
    long mtype;
    char data[512];
};

int main(int argc, char *argv[]) {
    struct msgbuf v;
    struct msqid_ds buf;
    int id;

    //if(argc != 3)  {
      //  printf("usage.... ./mq_tx msg_type data \n");
        //printf("Example: mq_tx 5\n");
        //return 0;
    //}

    id = msgget(49, IPC_CREAT | 0644); //msgget(key, perm);
    /*if(id<0) {
        perror("msgget"); 
        return 0;
    }
    */

   printf("id = %d\n", id);
   v.mtype = atoi(argv[1]);
   strcpy(v.data, argv[2]);
   msgsnd(id, &v, strlen(v.data)+1, 0);

    msgctl(id, IPC_STAT, &buf);
    printf(" Here are the details of the queue\n");
    printf("No. of msg's in q %hi\n", buf.msg_qnum);
    //printf("No. of bytes in q %d\n", buf.msg_cbytes);
    printf("Max no of bytes in q %hi\n", buf.msg_qbytes);
    
    return 0;
}