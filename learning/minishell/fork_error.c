#include "./all.h"

volatile sig_atomic_t	g_status;

int	main(int argc, char *argv[], char *env[])
{
	int	pid;
	char *cmd[] = {"bsh", NULL};

	while (1)
	{
		pid = fork();
		if (pid < 0)
		{
			printf("status %d\n ", g_status);
			break;
		}
	}
	execve("/bin/bash", &cmd[0], env);
}

