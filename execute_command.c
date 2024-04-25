#include "simple_shell.h"

/**
 * execute_command - executes a command
 * @cmd: command to execute
 */

void execute_command(char *cmd)
{
	char **argv = analize_arguments(cmd);

	if (argv != NULL)
	{
		search(argv);
		free(argv);
	}
}
