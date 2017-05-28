#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
int main()
{
	long result;

	// CLOCK TICKS
	if((result=sysconf(_SC_CLK_TCK))==-1)
		printf("error in system conf");
	else
		printf("Number of clock ticks = %ld\n",result);

	// MAX CHILD PROCESS
	if((result=sysconf(_SC_CHILD_MAX))==-1)
		printf("error in system conf");
	else
		printf("Maximum number of child process = %ld\n",result);

	// MAX PATH LENGTH
	if((result=pathconf("/",_PC_PATH_MAX))==-1)
		printf("error in path conf");
	else
		printf("Maximum path length = %ld\n",result);

	// MAX CHARACTER IN FILENAME
	if((result=pathconf("1.c",_PC_NAME_MAX))==-1)
		printf("error in path conf");
	else
		printf("Maximum number of characters in a filename = %ld\n",result);

	// MAX OPENED FILES OR PROCESSES
	if((result=sysconf(_SC_OPEN_MAX))==-1)
		printf("error in system conf");
	else
		printf("Maximum number of opened files = %ld\n",result);
	
}
