#include "simple_shell.h"
#define ARGV_SIZE 32
#define PATH_SIZE 69
/**
 * execute_command - interpreta y ejecuta el input del usuario
 * @cmd: command pasado por el usuario
 */
void execute_command(char *cmd)
{
    int i;
    pid_t pid;
    int pidnumber;
    char *token;
    char *argv[ARGV_SIZE] = {NULL};

    token = strtok(cmd, " \n\t");
    for (i = 0; token != NULL && i < ARGV_SIZE - 1; i++)
    {
        argv[i] = token;
        token = strtok(NULL, " \n\t");
    }
    argv[i] = NULL;
    if (argv[0] != NULL)
    {
        if (strchr(argv[0], '/') != NULL)
        {
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
        else
	  {
	    char *path = getenv("PATH");
	    char path_buffer[PATH_SIZE];
	    char *path_copy = strdup(path);
	    char *path_token = strtok(path_copy, ":");
            while (path_token != NULL)
	      {
		sprintf(path_buffer, "%s/%s", path_token, argv[0]);
		if (access(path_buffer, X_OK) != -1)
		  {
                    pid = fork();
                    if (pid == -1)
		      {
			fprintf(stderr, "Fork error\n");
                        exit(EXIT_FAILURE);
		      }
                    if (pid == 0)
		      {
                        if (execve(path_buffer, argv, NULL) == -1)
			  {
			    fprintf(stderr, "execve_error\n");
			    exit(EXIT_FAILURE);
                        }
		      }
                    else
		      {
                        if (waitpid(pid, &pidnumber, 0) == -1)
			  {
                            fprintf(stderr, "waitpid error\n");
                            exit(EXIT_FAILURE);
			  }
                        free(path_copy);
                        return;
		      }
		  }
	      path_token = strtok(NULL, ":");
            }
            free(path_copy);
            fprintf(stderr, "Missing cmd: %s\n", argv[0]);
        }
    }
}
