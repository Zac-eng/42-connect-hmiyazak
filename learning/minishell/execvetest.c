#include "./all.h"

int	main(int argc, char *argv[], char *env[])
{
	int		pipes[2];
	pid_t	pid;
	int		status;
	char	*cmd[] = {"cat", NULL};

	pid = fork();
	pipe(pipes);
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		int	stdout = dup(1);
		close(pipes[0]);
		dup2(pipes[1], 1);
		printf("this is a test\n");
		dup2(stdout, 1);
		exit(100);
	}
	close(pipes[1]);
	dup2(pipes[0], 0);
	execve("/bin/ls", &cmd[0], env);
	waitpid(pid, &status, 0);
	printf("%d\n", status);
}
