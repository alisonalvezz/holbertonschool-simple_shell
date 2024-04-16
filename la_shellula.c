#include "simple_shell.h"

int main()
{
	char *cmd;
       
	while (1)
	{
		display_prompt();
		cmd = read_line();
		printf("cmd = %s\n", cmd);
	}
	return (EXIT_SUCCESS);
}

void display_prompt(void)
{
        printf("shellula ");
        fflush(stdout);
}
  
char *read_line(void)
{
char *cmd = NULL;
size_t BUFSIZE = 0;

 if (getline(&cmd, &BUFSIZE, stdin) == -1)
   {
     perror("read_line");
     exit(EXIT_FAILURE);
   }
  return (cmd);

}

void execute_command(char *cmd)
{
  pid_t pid;
  int pidnumber;

  pid = fork();
  if (pid == -1)
    {
      perror("fork_error");
      exit(EXIT_FAILURE);
    }
  if (pid == 0)
    {
      if (execve(cmd, NULL, NULL) == -1)
	{
	  perror("execve_error");
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
waitpid(*cmd, &pidnumber, 0);
    }
}
