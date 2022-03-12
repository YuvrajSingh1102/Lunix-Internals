#include <stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main() {

    execl("/home/einfochips/Desktop/lunix internl/10th_march_work/exec", "./exec", 0);
    printf("System gives output as per acccordingly\n");
    return 0;
}