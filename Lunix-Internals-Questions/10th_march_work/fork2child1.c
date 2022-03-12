#include<stdio.h>
#include<unistd.h>


int main() {
    pid_t child_one, child_two;

    printf("Current/parent pid=%d\n", getpid());

    child_one = fork();

    if(child_one == 0) {
        printf("Child one pid =%d\n", getpid());
    } else {
        child_two = fork();

        if(child_two == 0) {
            printf("Child two pid =%d\n", getpid());
        }
        else 
        {
            wait();
            printf("Parent of one and two process pid %d\n", getpid());

        }
    }
}