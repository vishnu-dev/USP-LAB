#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
void main()
{
	#ifdef _POSIX_JOB_CONTROL
		printf("System supports job control\n");
	#else 
		printf("Job control support unavailable\n");
	#endif
	
	#ifdef _POSIX_SAVED_IDS
		printf("System supports set UID and set GID\n");
	#else 
		printf("set UID and set GID support unavailable\n");
	#endif

	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("System supports change of ownership\n");
	#else 
		printf("change of owner support unavailable\n");
	#endif

	#ifdef _POSIX_VDISABLE	
		printf("System supports disabling character\n");
	#else 
		printf("disabling character support unavailable\n");
	#endif

	#ifdef _POSIX_NO_TRUNC	
		printf("System supports pathname truncate option\n");
	#else 
		printf("pathname trunc option support unavailable\n");
	#endif
}
