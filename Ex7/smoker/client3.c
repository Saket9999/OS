
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    int f3; 
    char *myclient3="/tmp/myclient3"; 
    mkfifo(myclient3, 0666); 
    char string3[80];
        f3=open(myclient3,O_RDONLY,0666,0); 
        read(f3,string3,80); 
	printf(string3,"%s");
	close(f3);
} 



