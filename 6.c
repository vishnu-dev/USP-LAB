#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void printchar(char str[])
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		printf("%c",str[i]);
	}
}
void main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
		printf("fork error!");
	else if(pid==0)
		printchar("This is child process\n");
	else
		printchar("This is parent process\n");
}
