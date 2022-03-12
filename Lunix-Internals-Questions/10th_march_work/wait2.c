#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(void) {
    pid_t pid1;
    pid1 = fork();
    
    if(pid1 == 0){
        
        execl("/bin/ls", "ls", "-lh", 0);
        
    } else{
        
        wait(0);

        printf("Child process");
        
    }
    exit(0);
}