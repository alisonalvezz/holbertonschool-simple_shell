#include "simple_shell.h"

/**
 * display_prompt - displays prompt of the function
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		printf("shellula$ ");
		fflush(stdout);
	}
	else
	{
		return;
	}
}
