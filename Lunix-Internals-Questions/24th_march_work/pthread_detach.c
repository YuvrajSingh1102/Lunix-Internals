			/* synchronization between threads 

The pthread_join() subroutine blocks the calling thread until the specified threadid thread terminates. 

The programmer is able to obtain the target thread's termination return status if it was specified in the target thread's call to pthread_exit(). 

Two other synchronization methods, mutexes and condition variables, will be discussed later. 
 
When a thread is created, one of its attributes defines whether it is joinable or detached. Only threads that are created as joinable can be joined. If a thread is created as detached, it can never be joined. 

The final draft of the POSIX standard specifies that threads should be created as joinable. However, not all implementations may follow this. 

To explicitly create a thread as joinable or detached, the attr argument in the pthread_create() routine is used. The typical 4 step process is: 

1. Declare a pthread attribute variable of the pthread_attr_t data type 
2. Initialize the attribute variable with pthread_attr_init() 
3. Set the attribute detached status with pthread_attr_setdetachstate() 
4. When done, free library resources used by the attribute with pthread_attr_destroy() 

Detaching: 
The pthread_detach() routine can be used to explicitly detach a thread even though it was created as joinable.
			*/

#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#define NUM_THREADS     3
int i=0;
void *myfun(void *null)
{
	i++;	
	int result=0;
	result = result + i*1000;
	printf("result = %d\n",result);
	
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t thread[NUM_THREADS];
	pthread_attr_t attr;
	const pthread_attr_t attr1;
	int rc, t, status,detach_state;
	//printf("\n Detach State : %d\n",(int *)detach_state);
	pthread_attr_getdetachstate(&attr,&detach_state);
	printf("\n Detach State : %d\n",(int *)detach_state);

	/* Initialize and set thread detached attribute */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	for(t=0; t<NUM_THREADS; t++)
	{
		printf("Creating thread %d\n", t);
		rc = pthread_create(&thread[t], &attr, myfun, NULL); 
		if (rc)
		{	
			printf("ERROR; return code from pthread_create() is %d\n", rc);
         		exit(-1);
   		}
	}
	
	pthread_attr_getdetachstate(&attr1,&detach_state);
	printf("\n Detach State : %d\n",(int *)detach_state);
	pthread_attr_getdetachstate(&attr,&detach_state);
	printf("\n Detach State : %d\n",(int *)detach_state);
	pthread_attr_destroy(&attr);
	for(t=0; t<NUM_THREADS; t++)
	{
		/* explicitly detach a thread even though it was created as joinable */
		rc = pthread_detach(thread[t]);
		if (rc)
		{
			printf("ERROR; return code from pthread_join() is %d\n", rc);
		        exit(-1);
      		}
	      printf("Completed detach with thread %d \n",t);
   	}
	printf("\n Exiting from main Thread\n");
	//pthread_exit(NULL);

}


