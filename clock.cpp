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
	clock_t clock_id;
	clock_id=clock();
	printf("%ld",clock_id);
	return 0;
}
