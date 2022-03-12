#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main() {

    int pid_1;

printf("I am going to execute an ls program\n");


if(pid_1 == 0){
        execl("/bin/ls", "ls", "-lh", 0);
        printf("new child process pid = %d\n", getpid());
        printf("new child parent process pid = %d\n", getppid());
    } else{
        printf("parent process pid = %d\n", getpid());
        printf("parents parent process pid = %d\n", getppid());
    }
    while(1);
}