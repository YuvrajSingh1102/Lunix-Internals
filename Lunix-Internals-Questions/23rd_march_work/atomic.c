#include<stdio.h> //asking cpp to search for header file in /usr/include(repository of user header files)
#include"atomic.h" //cpp to search for header file called atomic.h in current folder

int main() {
    atomic_t v;
    atomic_t u = ATOMIC_INIT(0);

    atomic_set(&v, 4);
    printf("%d\n", atomic_read(&v));

    atomic_add(2, &v);
    printf("%d\n", atomic_read(&v));

    atomic_inc(&v);
    printf("%d\n", atomic_read(&v));

    atomic_sub(1,&v);
    printf("%d\n", atomic_read(&v));

    atomic_dec(&v);
    printf("%d\n", atomic_read(&v));


    return 0;
}