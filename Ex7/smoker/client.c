
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    int f1; 
    char * myclient1 = "/tmp/myclient1"; 
    mkfifo(myclient1, 0666); 
    char string1[80];
        f1 = open(myclient1,O_RDONLY,0666,0); 
        read(f1, string1, 80); 
	printf(string1,"%s");
	close(f1);
} 



