#include "simple_shell.h"
#define buffer 50

int main()
{
	/**char *cmd;*/

	while (1)
	{
		display_prompt();
		/**tiene que ser dentro del bucle porq sino no se ejecuta siempre*/
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
