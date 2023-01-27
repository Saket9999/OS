#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
 
void *S1();
void *S2();
int shared = 1; 
sem_t s; 
 
int main()
{
	sem_init(&s, 2, 1); 
 
	pthread_t t1, t2;
 	pthread_create(&t1, NULL, S1, NULL);
 	pthread_create(&t2, NULL, S2, NULL);
 	pthread_join(t1, NULL);
 	pthread_join(t2,NULL);
 	printf("Shared value is: %d\n", shared); 
}
 
void *S1()
{
    int i;
    sem_wait(&s); 
    i = shared;
    printf("T1 reads as %d\n", i);
    i++;  
    printf("T1 update value: %d\n", i);
    sleep(1); 
    shared = i; 
    printf("T1 shared update is: %d\n", shared);    
    sem_post(&s);
}
 
void *S2()
{
    int j;
    sem_wait(&s);
    j = shared;
    printf("T2 reads  as %d\n", j);
    j--;  
    printf("T2 update value: %d\n", j);
    sleep(1); 
    shared = j; 
    printf("T2 shared update is: %d\n", shared);
    sem_post(&s);
}
 
