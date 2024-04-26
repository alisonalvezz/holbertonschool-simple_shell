#include "simple_shell.h"

extern char **environ;
void print_env(void)
{
	char **env_var = environ;
	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}
