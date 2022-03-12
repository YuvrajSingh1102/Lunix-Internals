#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main() {
    printf("Current process\n");
    fork();
    fork();
    fork();
    printf("lunix process22\n");
    printf("lunix process33\n");
    
    while(1);


    return 0;
}