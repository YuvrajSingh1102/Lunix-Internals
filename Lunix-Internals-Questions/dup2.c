#include<stdio.h>
#include<fcntl.h>

int main() {
    int fd1, fd2, fd3, fd4;

    fd1 = open("lunix.txt", O_WRONLY | O_CREAT | O_TRUNC,777);
    fd2 = open("lunixnew.txt", O_WRONLY | O_CREAT | O_TRUNC,777);

    printf("fd1=%d\n", fd1);
    printf("fd2=%d\n", fd2);

    fd3 = dup(fd1);
    fd4 = dup2(fd1, 4);

    printf("fd1_dup of fd1=%d\n", fd3);
    printf("fd1_dup of fd1=%d\n", fd4);

    close(fd4);
    close(fd3);
    close(fd2);
    close(fd1);

    return 0;
}