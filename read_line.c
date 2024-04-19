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
                perror("read_line");
                exit(EXIT_FAILURE);
        }
        if (strcmp(cmd, "exit\n") == 0)
                  {
                    free(cmd);
                    exit(EXIT_SUCCESS);
                  }
        return (cmd);
}
