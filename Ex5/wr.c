#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#inlcude <time.h>

int main()
{
	char *buf, tmp[30];
	key_t key = ftok("ipccomm", 90);
	int len, shmid, val, i=0;
	int lft, rt, id;
	len = sprintf(tmp," %d",val);
	write(1, tmp, len);

	
	struct  sembuf p1;
	time_t t;
	
         
    shmid= semget(key, 1, IPC_CREAT|0777);
	shmid = shmget(key,1024,0666|IPC_CREAT);

	if (shmid == -1)
	{
		write (1,"Error occured",35);
		exit(0);
	}
			
	while (1)
	{
 
		write(1,"\n",1);		
		write(1,"Enter the Cma4", 28);
		write(1,"\n",1);
		p1.sem_num = 0;  
		p1.sem_op = -1;   
		p1.sem_flg = 0;  
		val = semop(id, &p1, 1);
		
		if (val == -1 )
		{
			write(1, "Wait failed", 22);
			exit(0);
		}

 	        write(1,"Enter shared memory detail:", 20);
	        val = read(0, buf, 20);
         	write(1,"Updated details in shared memory", 20);
         	
		write(1, ctime(&t),15);
			
		read(0, buf, 1);
	
		val = semop(id, &p1, 1);
		
		if (val ==-1 )
		{
			write(1, "Signal operation Failed", 24);
			exit(0);
		}
		
		write(1,"\n",1);
		val = semctl(id, 0, GETVAL, NULL);
		write(1,"Cma4 value : ",19);
		
	
	if (val == -1)
	{
		write (1,"Shared memory Detach Error",15);
		exit(0);
	}
	return 0;
}
}

