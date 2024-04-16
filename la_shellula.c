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

<<<<<<< HEAD
#include "simple_shell.h"

void execute_command(char *cmd)
{
       /** -obtener comando*/
        /**construir ruta al ejecutable ("/bin/" + comando)*/
        /**verificar si el ejecutable es accesible (con access()*/
        /**ejecutar el comando en un proceso hijo con fork donde:*/
        /**construye lo que se precise para exceve*/
        /**si no es accesible, mostrar error con perror y terminar _exit*/
        /**si es accesible, ejecutar con execve*/
        /**esperar que el proceso hijo termine y joya*/
=======
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
>>>>>>> 7d0892c4d0dfa696326673e8d59a1ab21b00e049
}
