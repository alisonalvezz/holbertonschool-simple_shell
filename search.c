#include "simple_shell.h"
#define PATH_SIZE 69

/**
 * search - searchs for the correct path of a cmd
 * @argv: argv
 */

void search(char *argv[])
{
	char *path = getenv("PATH");
	char path_buffer[PATH_SIZE];
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");

	if (argv[0] != NULL)
	{
		if (strchr(argv[0], '/') != NULL)
		{
			mitosis(argv[0], argv);
		}
		else
		{
			while (path_token != NULL)
			{
				sprintf(path_buffer, "%s/%s", path_token, argv[0]);
				if (access(path_buffer, X_OK) != -1)
				{
					mitosis(path_buffer, argv);
					free(path_copy);
					return;
				}
				path_token = strtok(NULL, ":");
			}
			free(path_copy);
			fprintf(stderr, "Command not found:  %s\n", argv[0]);
		}
	}
}
