#include "./all.h"

int	main(int argc, char *argv[], char *env[])
{
	int	fd = 1;
	int	pipes[2];
	char *cmd[] = {"nothing", NULL};

	while(fd < 255)
	{
		fd = open("./all.h", O_RDONLY);
		printf("fd: %d / %d\n", fd, OPEN_MAX);
	}
	fd = open("./all.h", O_RDONLY);
	printf("fd: %d / %d\n", fd, OPEN_MAX);
	printf("exec %d\n", execve("/bin/bash", &cmd[0], env));
}
