#include<stdio.h>
#include 

int fds[2];

void parent_code() {
    char *buf1 = "aaaaaaaaaaaaaaaaaaaa";
    char *buf = "bbbbbbbbbbbbbbbbbbb";

    close(fds[0]);

    write(fds[1], buf, 20);
    write(fds[1], buf1, 20);

    printf("End of parent\n");

}

void child_code() {
    char buf[100];

    int n, i;
    close(fds[1]);
    n = read
}