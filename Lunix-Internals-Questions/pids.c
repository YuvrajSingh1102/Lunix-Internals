#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main() {
    printf("my process pid = %dd\n", getpid());
    printf("my parent pid = %dd\n", getppid());

    printf("linux krenel\n");
    while(1);


    return 0;
}