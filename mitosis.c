#include "simple_shell.h"

/**
 * mitosis - does pid
 * @cmd: command
 * @argv: argv
 */

void mitosis(char *cmd, char *argv[])
{
	pid_t pid;
	int pidnumber;

	pid = fork();
	if (pid == -1)
	{
		perror("fork_error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(cmd, argv, NULL) == -1)
		{
			perror("execve_error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &pidnumber, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
