#include "simple_shell.h"

/**
 * print_env - prints environment
 */

extern char **environ;
void print_env(void)
{
	char **env_var = environ;
	if (*env_var == NULL)
	{
		fprintf(stderr, "Error: environ is NULL\n");
		return;
	}
	while (*env_var != NULL)
	{
		if (*env_var != NULL)
			printf("%s\n", *env_var);
		env_var++;
	}
}
