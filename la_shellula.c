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

/**
 * display_prompt - displays prompt of the function
 */
void display_prompt(void)
{
	printf("shellula$ ");
	fflush(stdout);
}

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

/**
 * execute_command - executes the command that the input gives us
 * @cmd: command
 */
void execute_command(char *cmd)
{
pid_t pid;
int pidnumber;
 char *argv[] = {NULL};
        pid = fork();
        if (pid == -1)
        {
                perror("fork_error");
                exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
          if (execve(cmd, argv, NULL) == -1)
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
