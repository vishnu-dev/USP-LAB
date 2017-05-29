#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void printchar(char str[])
{
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0;)
		putc(c,stdout);
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
