#include "simple_shell.h"

/**
 * read_line - reads the line in the input
 * Return: the command
 */
char *read_line(void)
{
	char *cmd = NULL;
	size_t BUFSIZE = 0;

	if (getline(&cmd, &BUFSIZE, stdin) == -1)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	return (cmd);
}

int exit_command(const char *cmd)
{
	return (strcmp(cmd, "exit\n") == 0);
}
