#include "simple_shell.h"

void execute_command(char *cmd)
{
i	/** -obtener comando*/
	/**construir ruta al ejecutable ("/bin/" + comando)*/
	/**verificar si el ejecutable es accesible (con access()*/
	/**ejecutar el comando en un proceso hijo con fork donde:*/
	/**construye lo que se precise para exceve*/
	/**si no es accesible, mostrar error con perror y terminar _exit*/
	/**si es accesible, ejecutar con execve*/
	/**esperar que el proceso hijo termine y joya*/
}
