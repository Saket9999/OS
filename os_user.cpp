#include<iostream>
#include<sys/utsname.h>
#include<unistd>
#include<error>

void main()
{
		uid_t s;
		struct passwd d;
		d= struct passwd *getpwuid(s);
		if(d==NULL)
		{
			error(1,e,"unable to show name");
		}
		write(1,d.getpwid,10);
		
}

