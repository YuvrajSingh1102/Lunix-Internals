/* Show how to perform some task periodically*/

#include<stdio.h>
#include<signal.h>

void sighand(int signum) {
    printf("I have to wake up my boss now\n");
    //alarm(5);
}
int main() {
    signal(SIGALRM, sighand);
    alarm(5);
    while(1) {

    }
    return 0;
}

/* Check manual for info on setitimer function*/