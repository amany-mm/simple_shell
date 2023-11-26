#include "shell.h"

/**
 * _get_env_value - get environment variable value
 * @env_var_name: environment variable name
 * Return: environment variable name value
*/

char *_get_env_value(const char *env_var_name)
{
	char *_val = NULL;
	char *name;
	char *value;
	int j;

	/* Iterate through environment variables */
	for (j = 0; environ[j] != NULL; j++)
	{
		/* Tokenize environment variable into name and value */
		name = strtok(environ[j], "=");
		value = strtok(NULL, "=");

		/* Check if name matches the desired environment variable */
		if (strcmp(name, env_var_name) == 0)
		{
			_val = value;
			break;
		}
	}
	return (_val);
}
