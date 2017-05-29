#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void main()
{
	pid_t pid;
	if((pid=fork())<0)
		printf("Fork error!");
	else if(pid==0)
	{
		printf("First child process %d and its parent %d\n",getpid(),getppid());
		if((pid=fork())<0)
			printf("Fork error!");
		else if(pid>0)
			exit(0);
		sleep(2);
		printf("Second child process %d and its parent %d\n",getpid(),getppid());
		exit(0);
	}
	if(waitpid(pid,NULL,0)!=pid)
		printf("wait pid error!");
	exit(0);
}			
