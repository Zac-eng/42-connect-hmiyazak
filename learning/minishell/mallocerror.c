#include "./all.h"

volatile sig_atomic_t g_status;

int	main(int argc, char *argv[], char *env[])
{
	char *allocated;
	char *cmd[] = {"bash", NULL};

	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (1000000000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (100000000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (10000000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (1000000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (100000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (10000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (1000000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (100000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (10000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (1000));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (100));
	}
	allocated = "allocated";
	while (allocated != NULL)
	{
		allocated = (char *)malloc(sizeof(char) * (10));
	}
	execve("/bin/bash", &cmd[0], env);
}
