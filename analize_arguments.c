#include "simple_shell.h"
#define ARGV_SIZE 32

/**
 * analize_arguments - parses arguments
 * @cmd: command of which parses
 * Return: argv
 */

char **analize_arguments(char *cmd)
{
	int i;
	char *token = strtok(cmd, " \n\t");
	char **argv = malloc(ARGV_SIZE * sizeof(char *));

	if (argv == NULL)
	{
		perror("malloc_error");
		exit(EXIT_FAILURE);
		free(argv);
	}

	for (i = 0; token != NULL && i < ARGV_SIZE - 1; i++)
	{
		argv[i] = token;
		token = strtok(NULL, " \n\t");
	}

	argv[i] = NULL;
	return (argv);
}
