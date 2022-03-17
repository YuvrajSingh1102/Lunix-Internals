#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    long int page_size = sysconf(_SC_PAGESIZE);
    printf("My page size is : %ld\n", page_size);

    void *c1 = sbrk(0);
    printf("program break address: %p\n", c1);
    printf("size ofchar: %lu\n", sizeof(char));
    c1 = (void *) ((char *) c1 + 9);

    printf("c1: %p\n", c1);

    brk(c1);

    void *c2 = sbrk(0);

    printf("program break address: %p\n", c2);


    return 0;

}