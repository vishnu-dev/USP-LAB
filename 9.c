#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>

int sysfunc(const char* cmdstring)
{
	pid_t pid;
	int status;
	if(cmdstring==NULL)
		return 1;
	if((pid=fork())<0)
		status=-1;
	else if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmdstring,(char*)0);
		_exit(127);
	}
	else
	{
		while(waitpid(pid,&status,0)<0)
		{
			if(errno!=EINTR)
			{
				status=-1;
				break;
			}
		}
	}
}
int main(int argc, char** argv)
{
	if(sysfunc("date")<0)
		printf("ERROR!");
	if(sysfunc("who")<0)
		printf("ERROR!");
	return 0;
}
