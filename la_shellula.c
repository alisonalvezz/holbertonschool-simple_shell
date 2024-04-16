#include "simple_shell.h"

int main()
{
	/**char *cmd;*/
	size_t buffer_size = 50;
	char *buffer;

	while (1)
	{
		display_prompt();
		/**tiene que ser dentro del bucle porq sino no se ejecuta siempre*/
		getline(&buffer, &buffer_size, stdin);
		/**leer comando con getline desde la stdin*/
		/*ejecutar comando con execute_command()*/
		/**repetir para esperar el siuiente comando del user*/
		/**execute_command(cmd);*/
	}

	return (0);
}

void display_prompt(void)
{
        printf("shellula ");
        fflush(stdout);
}

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
}
