
#include "shell.h"

/**
 * _print_errors - print error to STDERROR
 * @shell: shell name
 * @num: command counter
 * @cmd_arr: command and arguments array made the error
 * @err_type: error type
 * Return: NULL
 */
void _print_errors(char *shell, int num, char *cmd_arr, int err_type)
{
	char *str_count;

	str_count = convert_int_to_str(num);

	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, str_count, _strlen(str_count));
	write(STDERR_FILENO, ": ", 2);

	if (err_type == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, cmd_arr, _strlen(cmd_arr));

		write(STDERR_FILENO, "\n", 1);
	}
	else if (err_type == NOT_FOUND)
		write(STDERR_FILENO, "not found\n", 10);

	else if (err_type == PERMISSION_DENIED)
		write(STDERR_FILENO, "Permission denied\n", 18);

	free(str_count);
}
