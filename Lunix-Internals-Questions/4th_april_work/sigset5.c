/* using sigset_t */

#include<stdio.h>
#include<signal.h>

void check_blocked_sigs() {
    int i, res;
    sigset_t s;
    sigprocmask(SIG_BLOCK, NULL, &s);   //first param is not considered

    for(i = 0; i < 5; i++) {
        res = sigismember(&s, i);
        if(res) {
            printf("Signal %d is blocked \n",i);
        }
        else {
            printf("Signal %d is not blocked\n", i);
        }
    }



}

int main() {
    sigset_t s_set;
    sigfillset(&s_set);
    sigprocmask(SIG_BLOCK|SIG_SETMASK, &s_set, NULL);
    check_blocked_sigs();



    return 0;
}