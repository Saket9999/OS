
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    int f2; 
    char *myclient2="/tmp/myclient2"; 
    mkfifo(myclient2,0666); 
    char string2[80];
        f2=open(myclient2,O_RDONLY,0666,0); 
        read(f2, string2, 80); 
	printf(string2,"%s");
	close(f2);
} 



