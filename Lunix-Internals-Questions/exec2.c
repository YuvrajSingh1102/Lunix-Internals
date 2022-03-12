#include<stdio.h>

#include <unistd.h>

int main() {
    printf("I am going to execute an'ls' program\n");

    execl("/home/einfochips/Desktop/lunix internl/dup", "./dup", 0);

    printf("i executed is program");
    printf("i executed is program");
    printf("i executed is program");
    
    return 0;
}