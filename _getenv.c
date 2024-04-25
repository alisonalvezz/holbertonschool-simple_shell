#include "simple_shell.h"
/**
 * _getenv - gets enviroment variable
 *
 *
 */
char *_getenv(const char *name)
{
  int i = 0;
  char *token;
  char *tokendup;
  char *return_path = NULL;
  while (environ[i] != NULL)
	{
	  tokendup = strdup(environ[i]);
	  if (!tokendup)
	    {
	      return (NULL);
	    }
		token = strtok(tokendup, "=");
		if (token != NULL && strcmp(token, name) == 0)
		{
		  return_path = strdup(strtok(NULL, "="));
		  free(tokendup);
		  return (return_path);
		}
		free(tokendup);
		i++;
	}
  return (NULL);
}
