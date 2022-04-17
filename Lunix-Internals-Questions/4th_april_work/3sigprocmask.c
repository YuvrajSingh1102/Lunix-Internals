#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>

void printSignalSet(sigset_t *set) {
    const int sigList[] = {SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE, SIGKILL, SIGSEGV,};

    const char *sigNames[] = {"SIGHUP", "SIGINT", "SIGQUIT", "SIGILL", "SIGABRT", "SIGFPE", "SIGKILL", "SIGSEGV",};

    const int sigLen = 8;

    for(int i = 0; i<sigLen; i++) {
        int ret = sigismember(set, sigList[i]);
        if(ret == -1) {
            perror("sigismember:");
            exit(EXIT_FAILURE);
        }
        else if(ret == 1) {
            printf("Signal %s=%d IS in the set.\n", sigNames[i], sigList[i]);

        }
        else {
            printf("Signal %s=%d is not in the set.\n", sigNames[i], sigList[i]);
        }

    }

}

int main(void) {
    sigset_t set;
    if(sigprocmask(0, NULL, &set) != 0) {
        perror("sigpromask: ");
        exit(EXIT_FAILURE);
    }

    printf("____Initial signal mask for this process: ---\n");
    printSignalSet(&set);

    if(sigaddset(&set, SIGINT) != 0) {
        perror("sigaddset: ");
        exit(EXIT_FAILURE);
    }

    if(sigprocmask(SIG_SETMASK, &set, NULL) != 0) {
        perror("sigpromask: ");
        exit(EXIT_FAILURE);
    }

    printf("---- NEW Signal mask for this process: ----\n");
    printSignalSet(&set);

    int secToSleep = 5;
    printf("Try Ctrl-c. Try killing this program with 'kill - kill %d'. GOing to sleep for %d seconds.\n", getpid(), secToSleep);
    sleep(secToSleep);
    printf("Sleep returned.\n");

    printf("Removing all signals from mask.\n");
    sigemptyset(&set);
    //sigfillset(&set);

    sigprocmask(SIG_SETMASK, &set, NULL);

    printSignalSet(&set);
    sleep(1);
    printf("Exited normally.\n");

    return 0;
}