#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/*function for stack overflow to perform abnormal termination*/
int fun(int val)
{
	int x=0;
	while(val > 0)
	{
		x = x + fun(val--); 
	}
return val;
}

int main()
{
    write(1,"Process starts from here",15);
    int p;
    int pid = fork();
   
    if (pid > 0) //condition for parent process
    {
        write(1,"I am Parent\n",21);
        wait(&p);
        if(WIFEXITED(p))
        {
            write(1,"\nNormal Termination",12);
        } 

    }
    
    if (pid == 0) //condition for child process
    {
        write(1,"I am Child\n",18);
        int cid = fork();
        if(cid > 0)
        {
            wait(&p);
            
            if(WIFEXITED(p))
            {
                write(1,"\nNormal Termination",14);
            }
            else
            {
                write(1,"\nAbnormal Termination",14);
            }
            
        }
        
        if(cid == 0)
        {
        
            write(1,"\nI am Grand Child",14);
            int a = getpid();
            fun(a); 
        }
    }
    
}


