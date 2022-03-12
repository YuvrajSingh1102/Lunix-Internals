#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
    int pid_1;

    printf("Current process pid = %d\n", getpid());

    pid_1 = fork();
    fork();
    if(pid_1 == 0){
        
        printf("new child process pid = %d\n", getpid());
        //printf("new child parent process pid = %d\n", getppid());
    } else{
        //sleep(3);
        printf("parent process pid = %d\n", getpid());
        //printf("parents parent process pid = %d\n", getppid());
    }
    while(1);


    return 0;
}