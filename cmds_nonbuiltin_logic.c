#include "shell.h"

/**
* cmds_nonbuiltin_logic - non builtin commands logic
* @cmd_arr: Array of command arguments
* @env: environment variable
* @status: status
* @num: no. of commands executed
* @curr: current lst_paths
* @argv: command arguments
* Return: NULL
*/
void cmds_nonbuiltin_logic(char **cmd_arr, char *env[], int *status, int num,
			lst_path *curr, char *argv[])
{
	char *path;

	if (access(cmd_arr[0], X_OK) == 0)
		execute_command(cmd_arr[0], cmd_arr, env, status);

	else
	{

		path = check_cmd_access(cmd_arr[0], curr);
		if (path)
		{
			execute_command(path, cmd_arr, env, status);
			free(path);
		}

		else
		{
			_print_errors(argv[0], num, cmd_arr[0], NOT_FOUND);
			*status = NOT_FOUND;
		}
	}
}

/**
 * execute_command - executes command
 * @path: command path to execute
 * @env: environment variables
 * @argv: command and arguments array
 * @status: status
 * Returns: NULL
 */
void execute_command(char *path, char **argv, char **env, int *status)
{
	pid_t parent_id;

	parent_id = fork();

	if (parent_id < 0)
	{
		perror("fork has failed");
		exit(EXIT_FAILURE);
	}

	if (parent_id == 0)
	{
		execve(path, argv, env);
		perror("execve has failed");

		exit(EXIT_FAILURE);
	}

	else if (parent_id > 0)
	{

		waitpid(parent_id, status, WUNTRACED);
		*status  = WEXITSTATUS(*status);
	}
}


/**
  * check_cmd_access - check command access
  * @curr: current path
  * @cmd:  command
  * Return: path of command
  */
char *check_cmd_access(char *cmd, lst_path *curr)
{
	int path_found, cmd_len, curr_path_len, len_full;
	char *path_full;

	path_found = 0;

	if (curr == NULL)
		return (NULL);

	while (curr)
	{

		cmd_len = _strlen(cmd);
		curr_path_len = _strlen(curr->path);

		len_full = (2 + cmd_len + curr_path_len);

		path_full = (char *)malloc(sizeof(char) * len_full);

		_strcpy(path_full, curr->path);
		_strcat(path_full, "/");
		_strcat(path_full, cmd);

		if (access(path_full, X_OK) == 0)
		{
			path_found = 1;
			break;
		}

		else
			free(path_full);

		curr = curr->next;
	}

	if (path_found)
		return (path_full);

	else
		return (NULL);
}
