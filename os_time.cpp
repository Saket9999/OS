#include<time.h>
#include<stdio.h>
#include<sys/utsname.h>
#include<unistd.h>
#include<error.h>
//#include<String.h>
using namespace std;

int main()
{
	time_t d;
	int e;
	
	time(&d);
	printf("%ld\n",(d/(3600*24*30*12)));
	return 0;
}

