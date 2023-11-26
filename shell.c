#include "shell.h"

/**
* main - main function
* @argc: arguments counter
* @argv: arguments vector
* @env: shell environment
* Return: status exit
*/
int main(int argc, char *argv[], char *env[])
{
	lst_path *current_path;
	int n = 0, st = 0, non_interactive = 1, mode, *status;
	char **cmd_array = NULL, **cmd_lines, *cmd;

	mode = check_shell_mode(argc);
	status = &st;
	if (mode != INTERACTIVE_MODE)
		cmd_lines = search_cmd_file(mode, argv[1], argv[0]);
	current_path = convert_paths_to_linkedlist();/* handle PATH */
	while (non_interactive && ++n)
	{
		if (mode == NON_INTERACTIVE_PIPE || mode == NON_INTERACTIVE_MODE)
		{
			if (cmd_lines[n - 1])
				cmd = cmd_lines[n - 1];
			else
			{
				free(cmd_lines);
				break;
			}
		}
		else if (mode == INTERACTIVE_MODE)
			cmd = read_cmd_user(current_path);/* prompt and getLine */
		if (!cmd)
			continue;
		cmd_array = convert_cmdline_to_array(cmd, *status);/* strtok */
		if (!cmd_array)
		{
			free(cmd);
			continue;
		}
		if (check_dir_exist(cmd_array[0], argv, n, cmd_array, status, cmd) == 0)
			continue;
		if (cmds_builtin_logic(cmd, cmd_array, current_path, argv[0], n, status,
			NULL, cmd_lines, argv) != 0)
			cmds_nonbuiltin_logic(cmd_array, env, status, n, current_path, argv);
		free_cmds_all(cmd, cmd_array);
	}
	free_path_lst(current_path);
	exit(*status);
}
