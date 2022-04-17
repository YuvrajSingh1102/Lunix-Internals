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
    int id;

    /* if(argc != 3)  {
        printf("usage.... .\mq_tx msg_type data \n");
        printf("Example: mq_tx 5 \ "hello\" \n");
        return 0;
    }*/

    id = msgget(49, IPC_CREAT|0644);
    /* if(id<0) {
        perror("msgget"); /// ./tx 12 linux \0
        return 0;
    }*/

    printf("id = %d\n", id);
    v.mtype = atoi(argv[1]); // "12"        //Argument 1 is type of message converting ascii to int

    strcpy(v.data, argv[2]); //Argument 2 is message
    msgsnd(id, &v, strlen(v.data)+1, 0);     //Flag IPC_NOWAIT
    //perror ("msgsnd");        // "./wrt" "type" "data"
    return 0;
}