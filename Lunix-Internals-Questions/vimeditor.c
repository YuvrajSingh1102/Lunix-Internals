#include<stdio.h>

int main() {

    int ret;
    ret = execl("/usr/bin/vim","vim", "info1", 0);

    if(ret == -1) {
        printf("eroor not creating a file %d\n", ret);
    }
}