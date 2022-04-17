#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char buff_comm[5];
    strcpy( buff_comm, "ls -l" );

    printf("system() library function uses fork() to create a child process\n");
    printf("child process executes execl() which loads and run new peogram provided by system() arguments\n");
    system(buff_comm);

    return 0;
}