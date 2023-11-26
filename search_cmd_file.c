#include "shell.h"

/**
 * search_cmd_file - search cmd file by mode operation
 * @mode: operation mode
 * @file: file name
 * @shell: shell name
 * Return: cmd lines array read from file
 */
char **search_cmd_file(int mode, char *file, char *shell)
{
	char **command_lines;

	if (mode == NON_INTERACTIVE_PIPE)
	{
		command_lines = non_interactive_pipes_logic();
		if (!command_lines)
			exit(0);
	}

	else if (mode == NON_INTERACTIVE_MODE)
	{
		command_lines = non_interactive_file_logic(file, shell);
		if (!command_lines)
			exit(0);
	}

	return (command_lines);
}



