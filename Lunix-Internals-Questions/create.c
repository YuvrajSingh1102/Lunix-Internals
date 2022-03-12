#include<stdio.h>
#include <fcntl.h>

int main() {
    int fd1;

    fd1 = creat("main1.c", 777);
    printf("fd1 returns the value : %d\n", fd1);


    close(fd1);

    return 0;
}
