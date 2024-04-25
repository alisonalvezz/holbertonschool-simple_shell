#include "simple_shell.h"
/**
 * main - main function
 * Return: exit success
 */
int main(void)
{
	char *cmd;

	while (1)
	{
		display_prompt();
		cmd = read_line();
		execute_command(cmd);
		free(cmd);
	}
	return (EXIT_SUCCESS);
}

