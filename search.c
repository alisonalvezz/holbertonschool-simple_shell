#include "simple_shell.h"
#define PATH_SIZE 69

/**
 * search - searchs for the correct path of a cmd
 * @argv: argv
 */

void search(char *argv[])
{
	char *path = _getenv("PATH");
	char path_buffer[PATH_SIZE];
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");

	if (path == NULL)
	{
		fprintf(stderr, "Failed to get PATH.\n");
		free(path);
		return;
	}

	if (path_copy == NULL)
	{
		fprintf(stderr, "Failed to duplicate PATH.\n");
		free(path_copy);
		return;
	}
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
					break;
				}
				path_token = strtok(NULL, ":");
			}
			if (path_token == NULL)
				fprintf(stderr, "Command not found:  %s\n", argv[0]);
		}
	}
	free(path_copy);
	free(path);
}
