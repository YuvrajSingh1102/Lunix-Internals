#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

static void signal_handler(int signo) {
    if(signo == SIGINT) 
    printf("Caught SIGINT: \n");
    else if(signo == SIGALRM)
    printf("Caught SIGALRM!\n");
    else{
        printf("Caught SIGABRT!\n");
        fprintf(stderr, "Unecpected signal: \n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);

}

int main(void) {
    if(signal(SIGINT, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Cannot handle SIGINT!\n");
        exit(EXIT_FAILURE);
    }
    alarm(4);
    if(signal(SIGALRM, signal_handler) == SIG_ERR) {
        fprintf(stderr, "Cannot ignore SIGTERM!\n");
        exit(EXIT_FAILURE);
    }

    if(signal(SIGABRT, SIG_DFL) == SIG_ERR) {
        fprintf(stderr, "Cannot reset SIGPROF!\n");
        exit(EXIT_FAILURE);
    }

    //abort();
    if(signal(SIGABRT, SIG_IGN) == SIG_ERR) {
        fprintf(stderr, "Cannot reset SIGPROF!\n");
        exit(EXIT_FAILURE);
    }
    
    for(;;)
    pause();
    return 0;
}