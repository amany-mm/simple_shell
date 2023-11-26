#include "shell.h"

/**
 * check_dir_exist - Check if a directory exists and is accessible
 * @cmd: command
 * @args: command arguments
 * @num: number
 * @cmd_arr: Array containing command and its arguments
 * @status: Pointer to command status.
 * @cmd_before: original command before any modifications
 * Return: -1 if the directory exists and is accessible, 0 otherwise
 */
int check_dir_exist(char *cmd, char **args, int num, char **cmd_arr,
					int *status, char *cmd_before)
{
	struct stat _st;

	/* Use stat to check if directory exists */
	if (stat(cmd, &_st) == 0)
	{
		/* Check if file is a directory */
		if (S_ISDIR(_st.st_mode))
		{
			/* Print an error message and update command status */
			_print_errors(args[0], num, cmd_arr[0], PERMISSION_DENIED);
			*status = PERMISSION_DENIED;
			free_cmds_all(cmd_before, cmd_arr);
			return (0);
		}
	}
	return (-1);
}
