#include "shell.h"

/**
 * read_cmd_user - read user input command
 * @curr: cmd current path
 * Return: command after scanning.
 */
char *read_cmd_user(lst_path *curr)
{
	char *cmd = NULL;
	size_t n = 0;
	ssize_t line_ptr;

	/* display prompt for user input */
	write(STDOUT_FILENO, "($) ", 4); /* write four bytes ($) */
	line_ptr = getline(&cmd, &n, stdin);

	/* check for end of file Ctrl+D */
	if (line_ptr == EOF)
	{
	/* print a newline and free resources before exiting */
		write(STDOUT_FILENO, "\n", 1);

		free_path_lst(curr);
		free(cmd);
		exit(0);
	}

	/* check if cmd is an empty line */
	if (line_ptr == 1 && cmd[0] == '\n')
	{
		free(cmd);
		return (NULL);
	}

	/* replace newline character with null terminator */
	cmd[line_ptr - 1] = '\0';

	return (cmd);
}
