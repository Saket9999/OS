#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/utsname.h>
#include<time.h>
#include<error.h>
#include<string.h>

int main(int argv, char *argc[])
{
	char res[100];
	time_t t;
    t = time(NULL);
    char pt[20];
	struct stat s;
	
	//printf("Enter the pathname:");
	//scanf("%s",pt);
	
	if(stat(argc[1], &s) == -1)
	{
		printf("File not found");
		_exit(0);
	}
	 
	struct tm hr;
	
	/*File modes*/ 
	if(s.st_mode & R_OK);
		printf("Read");
	
	if (s.st_mode & W_OK)
        	printf("\nWrite ");
    
	if (s.st_mode & X_OK)
        	printf("\nExecute");
	
	printf("\nFile Size: %ldBytes", s.st_size);
	
	//GM Time 
	hr = *(gmtime(&s.st_atime));
	printf("\nAcessed on : %d-%d-%d %d:%d:%d", hr.tm_mday, hr.tm_mon+1, hr.tm_year+1900, hr.tm_hour, hr.tm_min, hr.tm_sec); 	
	
	hr = *(gmtime(&s.st_mtime));
	printf("\nModified on : %d-%d-%d %d:%d:%d", hr.tm_mday, hr.tm_mon+1, hr.tm_year+1900, hr.tm_hour, hr.tm_min, hr.tm_sec); 	
	
	//Local Time
	hr = *(localtime(&s.st_atime));
	printf("\nAcessed on : %d-%d-%d %d:%d:%d", hr.tm_mday, hr.tm_mon+1, hr.tm_year+1900, hr.tm_hour, hr.tm_min, hr.tm_sec); 	
	
	hr = *(localtime(&s.st_mtime));
	printf("\nModified on : %d-%d-%d %d:%d:%d", hr.tm_mday, hr.tm_mon+1, hr.tm_year+1900, hr.tm_hour, hr.tm_min, hr.tm_sec); 	
	
	struct timespec times[2];
	 
	strftime(res, sizeof(res), "%r", localtime(&t));
	printf("\n\n\n%s", res);
	
	return 0;
}

