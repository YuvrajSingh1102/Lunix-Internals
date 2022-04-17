#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main() {
    char *r;
    int id;

    id = shmget(48, 250, IPC_CREAT|0644); //id = shget(32, 15-, IPC_CREAT|0644);

    if(id<0){
        perror("shmget");   //stderr device pf()...........screen device
        return 0;
    }

    printf("id = %d\n", id);
    r = shmat(id, 0, 0);    //PAS---User Space
    printf("%s\n", r);
    //return 0;
    //while(1);
    return 0;

}