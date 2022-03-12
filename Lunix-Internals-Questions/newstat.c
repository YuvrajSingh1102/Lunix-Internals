#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    struct stat st;
    int fd;

    //fd=open()

    stat("Q1.c", &st);

    printf("file size = %lu\n", (st.st_size));
    

    printf("file inode = %lu\n", st.st_ino);
    printf("size disc of blocks =%lu\n", st.st_blksize);
    printf("\n\n");
    close(fd);
    return 0;
}