#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char **argv) 
{
	int fd;
	char buffer[255];
	struct flock filelock;
	if (argc != 2) {
		printf("Incorrect number of arguements\n");
		return 1;
	}
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		printf("Error\n");
		return 1;
	}
	filelock.l_type = F_WRLCK;
	filelock.l_whence = SEEK_END;
	filelock.l_start = SEEK_END - 100;
	filelock.l_len = 100;
	if (fcntl(fd, F_GETLK, &filelock) == -1) {
		printf("File locked by process (pid): \t %d\n", filelock.l_pid);
		return 1;
	}
	else {
		if ((fcntl(fd, F_SETLK, &filelock)) == -1)
			printf("Failed to set lock\n");
		if ((lseek(fd, SEEK_END - 50, SEEK_END)) == -1)
			return 1;
		if ((read(fd, buffer, 100)) == -1)
			return 1;
		puts(buffer);
	}
	filelock.l_type = F_UNLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;
	if ((fcntl(fd, F_UNLCK, &filelock)) == -1) {
		printf("Unable to unlock file\n");
		return 1;
	}
	close(fd);
	return 0;
}
