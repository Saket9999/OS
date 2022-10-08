#include<time.h>
#include<stdio.h>
#include<sys/utsname.h>
#include<unistd.h>
#include<error.h>
#include<string.h>
#include<sys/stat.h>
using namespace std;

int main()
{
	 char p[20],q[20];
	 int k;
	printf("Enter The Path:");
//	strcpy(p,);
	scanf("%s",p);
	struct stat s;
	
	 if(stat(p, &s)==-1)
	 {
		printf("No Such File In Path!!!");
		_exit(0);
	 }
	 
	 // file in present in path
	 struct tm h,m;
	 
	 if(s.st_mode & R_OK);
	 	printf("read");
	if (s.st_mode & W_OK)
        printf("write ");
    if (s.st_mode & X_OK)
        printf("execute");
	
	printf("\nFile Size: %ldBytes",s.st_size);
	
	//printf("\n%ld",s.st_atime);
	//printf("\n%ld",s.st_ctime);
	//printf("\n%ld",s.st_mtime);
	
	h=*(gmtime(&s.st_atime));
	//t[0].tv_sec=s.st_atime;
	 	
	printf("\nAcessed on : %d-%d-%d %d:%d:%d",h.tm_mday,h.tm_mon+1,h.tm_year+1900,h.tm_hour,h.tm_min,h.tm_sec); 	
	
	h=*(gmtime(&s.st_mtime));
//	t[1].tv_sec=s.st_mtime;
	 	
	printf("\nModified on : %d-%d-%d %d:%d:%d",h.tm_mday,h.tm_mon+1,h.tm_year+1900,h.tm_hour,h.tm_min,h.tm_sec); 	
	
	 struct timespec t[2]={s.st_atime,s.st_ctime};
	 
	 //-----------------------------------------------------------------------------------
	//change the access time of file
	
	futimens(1,t);
	printf("\n\nAcessed on : %d-%d-%d %d:%d:%d",h.tm_mday,h.tm_mon+1,h.tm_year+1900,h.tm_hour,h.tm_min,h.tm_sec); 	
	printf("\nModified on : %d-%d-%d %d:%d:%d\n",h.tm_mday,h.tm_mon+1,h.tm_year+1900,h.tm_hour,h.tm_min,h.tm_sec); 	
	
	
/*		printf("Enter The Path:");
		
	scanf("%s",q);
	k=utimensat(1,q,t,0);
	printf("%d",k);
	printf("\n\nAcessed on : %d-%d-%d %d:%d:%d",h.tm_mday,h.tm_mon+1,h.tm_year+1900,h.tm_hour,h.tm_min,h.tm_sec); 	
	printf("\nModified on : %d-%d-%d %d:%d:%d\n",h.tm_mday,h.tm_mon+1,h.tm_year+1900,h.tm_hour,h.tm_min,h.tm_sec); 	
	*/
	return 0;
}

