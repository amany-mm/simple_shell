#include "shell.h"

/**
 * _env - print environment variables
 * @s: status
 * Return: NULL
 */
void _env(int *s)
{
	int j;

	for (j = 0; environ[j] != NULL; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));

		write(STDOUT_FILENO, "\n", 1);
	}

	*s = 0; /* success status */
}

/**
 * _exit_logic - check if exit is cmd entered and perform terminal exit
 * @cmd: command
 * @cmd_arr: command and arguments
 * @shell: shell name
 * @curr: current path
 * @status: status
 * @num: count
 * @cmd_lines: cmd lines
 * @env: env
 * Return: NULL
 */
void _exit_logic(char *cmd, char **cmd_arr, lst_path *curr, char *shell,
		int num, int *status, lst_path *env, char **cmd_lines)
{
	int num_exit;

	if (_strcmp(cmd_arr[0], "exit") == 0)
	{
		if (cmd_arr[1] == NULL)
		{
			free_everything(cmd_lines, num, env, curr, cmd, cmd_arr);
			exit(*status);
		}
		else if (cmd_arr[1] != NULL)
		{
			if (_strlen(cmd_arr[1]) <= 9)
			{
				num_exit = _atoi(cmd_arr[1]);
				if (num_exit != -1)
				{
					free_everything(cmd_lines, num, env, curr, cmd, cmd_arr);
					exit(num_exit);
				}
				else
				{
					*status = EXIT_ERROR;
					_print_errors(shell, num, cmd_arr[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				_print_errors(shell, num, cmd_arr[1], EXIT_ERROR);
			}
		}
	}
}

/**
* _setenv - set an environment variable
* @key: environment variable name
* @value: environment variable value
* @curr: lst_paths structure
* Return : NULL
*/
void _setenv(char *key, char *value, lst_path *curr)
{
	char *env_full = NULL;
	int len_full = 0;

	if (value == NULL || key == NULL)
		return;

	if (curr == NULL)
		return;

	len_full = 2 + _strlen(key) + _strlen(value);

	env_full = malloc(len_full);

	if (env_full == NULL)
		return;

	_strcpy(env_full, key);
	_strcat(env_full, "=");

	_strcat(env_full, value);
	env_full[len_full - 1] = '\0';

	free(env_full);
}


/**
* _cd - change current directory
* @cmd_arr: command array
* @argv: argument vector
* Return: NULL
*/
int _cd(char **cmd_arr, char **argv)
{
	char _cwd[1024];
	char *dir = cmd_arr[1];

	if (getcwd(_cwd, sizeof(_cwd)) == NULL)
	{
		perror("error in getcwd()");
		return (1);
	}
	if (dir == NULL || _strcmp(dir, "~") == 0)
		dir = _get_env_value("HOME");

	else if (_strcmp(dir, "-") == 0)
		dir = _get_env_value("OLDPWD");

	if (chdir(dir) == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));

		write(STDERR_FILENO, ": 1", 3);
		write(STDERR_FILENO, ": ", 2);

		write(STDERR_FILENO, cmd_arr[0], _strlen(cmd_arr[0]));
		write(STDERR_FILENO, ": can't cd to ", 14);

		write(STDERR_FILENO, cmd_arr[1], _strlen(cmd_arr[1]));
		write(STDERR_FILENO, "\n", 1);

		return (1);
	}
	else
	{
		setenv("OLDPWD", _cwd, 1);

		if (getcwd(_cwd, sizeof(_cwd)) == NULL)
		{
			perror("error in getcwd()");
			return (1);
		}
	}
	return (0);
}
