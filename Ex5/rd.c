#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <time.h>

int main()
{
	char *buf, tmp[20];
	int shmid, val;
	int *data;
	
	key_t key = ftok("ipccomm",8);
	

	shmid = shmget(key, 1024,0666|IPC_CREAT);

	if (shmid == -1)
	{
		write (1,"Error in memory access",25);
		exit(0);
	} 
	 
	key_t k = 100;	
 	struct  sembuf p1;
	time_t t;
	shmid = semget(k, 1, IPC_CREAT|0777);
	
	if (shmid == -1 )
	{
		write(1, "Error Occured", 13);
		exit(0);
	}	
	
	while (1)
	{
		
		buf = (char*) shmat(shmid,(void*)0, 0);
	         val=write(1,buf,10);
		write(1,"Details of shared memory", 20);
		
		p1.sem_num = 0;  /* semaphore number */
		p1.sem_op = +1;   /* semaphore operation */
		p1.sem_flg = 0;  /* operation flags */
		
		write(1,"\n", 1);		
		write(1,"----Exiting----", 17);
		write(1,"\n",1);
		exit(0);
		}
   
		val = semop(shmid,&p1,1);
		
		if (val == -1 )
		{
			write(1, "Operation Failed", 28);
			exit(0);
		}
		
		write(1,"\n", 1);
		val= semctl(shmid, 0, GETVAL, NULL);
		write(1,"Semaphore value is: ",22);
	
	val = shmdt(buf);
	if (val == -1)
	{
		write (1,"Detach error", 33);
		exit(0);
	}
	return 0;
}
