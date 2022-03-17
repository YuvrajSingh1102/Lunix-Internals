
#include <stdio.h>
#include <string.h>

int main() {
    char buf1[20];
    char buf2[20];
    int ret;

    memcpy(buf1, "chair", 6);
    memcpy(buf2, "cmad", 6);

    ret = memcmp(buf1, buf2, 5);

    if(ret > 0) 
    {
        printf("buf1 is greater then buf2\n");
    } 
    else if(ret < 0) 
    {
        printf("buf1 is less then buf2\n");
    }
    else 
    {
        printf("buf1 is equal then buf2\n");
    }

    return 0;

}