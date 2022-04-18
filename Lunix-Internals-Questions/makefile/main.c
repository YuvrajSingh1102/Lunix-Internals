#include<stdio.h>

#include "calc_mean.h"

int d1 = 100;

int main(int argc, char *argv[]) {
    double v1,v2,m1,m2;
    v1 = 5.2;
    v2 = 7.9;
    m1 = mean(v1,v2);
    m2 = sub(v1,v2);

    printf("The mean of %3.3f and %3.2f is %3.2f\n", v1,v2,m1);
    printf("The substraction of %3.3f and %3.2f is %3.2f\n", v1,v2,m2);

    return 0;
}
