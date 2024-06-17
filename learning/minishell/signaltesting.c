#include "./all.h"

volatile sig_atomic_t	g_status = 0;

int	main(int argc, char *argv[], char *env[])
{
	pid_t 	pid;
	int		status;
	char	*cmd[] = {"cat", NULL};

	pid = fork();
	if (pid < 0)
		exit(g_status);
	else if (pid == 0)
	{
		execve("/bin/cat", &cmd[0], env);
	}
	wait(&status);
	printf("status: %d\n", status);
	exit(g_status);
}
