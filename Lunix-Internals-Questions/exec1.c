#include<stdio.h>

#include <unistd.h>

int main() {
    printf("I am going to execute an'ls' program\n");

    execl("/bin/ls", "ls", "-lh", 0);

    printf("i executed is program");
    printf("i executed is program");
    printf("i executed is program");
    
    return 0;
}