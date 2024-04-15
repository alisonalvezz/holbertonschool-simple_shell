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
        printf("la_shellula ");
        fflush(stdout);
}
