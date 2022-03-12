#include <stdio.h>
#include<fcntl.h>
#include <stdlib.h>


void callback1() {
    printf("callback1 func called\n");
}

void callback2() {
    printf("callback2 func called\n");
}

void callback3() {
    printf("callback3 func called\n");
}
int main() {
    printf("Resgistring call back1\n");
    atexit(callback1);

    printf("Resgistring call back2\n");
    atexit(callback2);

    printf("Resgistring call back3\n");
    atexit(callback3);

    exit(0);
    }