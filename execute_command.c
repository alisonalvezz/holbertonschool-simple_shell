#include "simple_shell.h"
#define ARGV_SIZE 32

/**
 * execute_command - ejecuta comando
 * @cmd: command
 */

void execute_command(char *cmd)
{
        int i = 0;
        pid_t pid;
        char *token;
        int pidnumber;
        char *argv[ARGV_SIZE] = {0};
        token = strtok(cmd, " \n\t");
        argv[0] = token;
        while (argv[i] != NULL)
        {
                i++;
                token = strtok(NULL, " \n\t");
                argv[i] = token;
        }
        pid = fork();
        if (pid == -1)
        {
                perror("fork_error");
                exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
                if (execve(argv[0], argv, NULL) == -1)
                {
                        perror("execve_error");
                        exit(EXIT_FAILURE);
                }
        }
        else
        {
                if (waitpid(pid, &pidnumber, 0) == -1)
                {
                        perror("waitpid");
                        exit(EXIT_FAILURE);
                }
        }
}
