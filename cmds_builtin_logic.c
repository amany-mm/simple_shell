#include "shell.h"

/**
 * cmds_builtin_logic - Handles built-in commands in the shell
 * @cmd: command of the user
 * @cmd_arr: array of the parsed cmd
 * @curr: lst_paths struct pointer of current path
 * @shell: The name of the shell.
 * @num: commands count
 * @status: status
 * @env_lst: env list
 * @cmd_lines: cmd lines
 * @argv: arg vector
 * Return: 0 if a builtin cmd
 * -1 if non-builtin cmd or error
 */
int cmds_builtin_logic(char *cmd, char **cmd_arr, lst_path *curr, char *shell,
			int num, int *status, lst_path *env_lst, char **cmd_lines, char **argv)
{
	int i, j;
	char *builtin[] = {"setenv", "env", "cd", "exit"};

	j = -1;

	for (i = 0; i < 4; i++)
	{
		if (_strcmp(builtin[i], cmd_arr[0]) == 0)
		{
			j = i;
			break;
		}
	}

	if (j == -1) /* cmd not built in */
		return (j);

	switch (j)
	{
		case 0:
			_setenv(cmd_arr[1], cmd_arr[2], curr);
			break;
		case 1:
			_env(status);
			break;
		case 2:
			_cd(cmd_arr, argv);
			break;
		case 3:
			_exit_logic(cmd, cmd_arr, curr, shell, num, status, env_lst, cmd_lines);
			break;
		default:
			return (-1);
	}
	return (0);
}


