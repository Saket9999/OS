#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <time.h>


sem_t smoker_waits[3];

sem_t smoker_paper;
sem_t smoker_tobacco;
sem_t smoker_match;
sem_t agent;

   int f1,f2,f3;
    
  char *myclient1="/tmp/myclient1"; 
  
  char *myclient2="/tmp/myclient2";
  
  char *myclient3="/tmp/myclient3";

void delaytime(int number_of_seconds)    
{
    int milli_seconds=1000*number_of_seconds;
    clock_t start_time=clock();
    while(clock()<start_time+milli_seconds);
}

void Agentfun()
{
    while(true)
	{
		sem_wait(&agent);
		int select_item=rand()%3;
		if(select_item==0)
		{
		printf("\nThe agent has set out matches and tobacco on the table.\n\n");
		sem_post(&smoker_paper);  
		}
		else if(select_item==1)
		{
		printf("\nThe agent has set out paper and tobacco on the table\n\n");
		sem_post(&smoker_match);
		}
		else
		{
		printf("\nThe agent has set out paper and matches on the table\n\n");
		sem_post(&smoker_tobacco);	
		}
		
		
		sem_post(&smoker_waits[select_item]);   
		sem_t smoker_waits[3];
	}
}

void* Smoker_paper(void* arg)
{
	while(true)
	{
		sem_wait(&smoker_paper);
		printf("Smoker one with paper received matches and tobacco.Now making cigarette. \n\n");
         char a1[80]="Smoke 1 is smoking \n";
        int k;
        for (k=0;k<10;k++)
		 { 
		 delaytime(1); 
		 }
        f1 = open(myclient1, O_WRONLY,0666,0); 
        write(f1, a1, strlen(a1)+1); 
		sem_post(&agent);
	}

	return NULL;
}

void* Smoker_matches(void* arg)
{
	while (true)
	{
		sem_wait(&smoker_match);
		printf("Smoker two with matches received paper and tobacco.Now making cigarette. \n\n");
        char a2[80]="Smoke 2 is smoking\n";
        int l;
        for (l=0;l<10;l++)
		 {  
		 delaytime(1);  
		 }
        f2 = open(myclient2, O_WRONLY,0666,0); 
       write(f2, a2, strlen(a2)+1); 
		sem_post(&agent);
	}

	return NULL;
}

void* Smoker_tobacco(void* arg)
{
	while (true)
	{
		sem_wait(&smoker_tobacco);
		printf("Smoker three with tobacco received matches and paper.Now making cigarette. \n\n");
        char a3[80]="Smoke 3 is smoking \n";	
        int j;
        for(j=0;j<10;j++) 
		{   
		 delaytime(1);
        }
        f3= open(myclient3, O_WRONLY,0666,0); 
      write(f3,a3,strlen(a3)+1); 
	sem_post(&agent);
	}

	return NULL;
}

int main(int argc, char* arvg[])
{

	sem_init(&agent,0,1);

mkfifo(myclient1,0666); 
mkfifo(myclient2,0666);
mkfifo(myclient3,0666);

	pthread_t smoker_threads_paper;
	pthread_t smoker_threads_matches;
	pthread_t smoker_threads_tobacco;
	
 pthread_create(&smoker_threads_paper, NULL, Smoker_paper, NULL) ;
 pthread_create(&smoker_threads_matches, NULL, Smoker_matches, NULL) ;
 pthread_create(&smoker_threads_tobacco, NULL, Smoker_tobacco, NULL) ;

    Agentfun(); 

	pthread_join(smoker_threads_paper, NULL);
	pthread_join(smoker_threads_matches, NULL);
	pthread_join(smoker_threads_tobacco, NULL);

	
}
