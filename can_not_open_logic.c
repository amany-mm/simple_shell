#include "shell.h"

/**
* can_not_open_logic - errors logic if a file can't be opened
* @prog: the name of the program attempting to open the file
* @num: counter
* @file: file name
* Return : NULL
*/
void can_not_open_logic(char *prog, int num, char *file)
{

	char *i;

	i = convert_int_to_str(num);

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, i, _strlen(i));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, "Can't open ", CANNOT_OPEN_FILE_ERROR);
	write(STDERR_FILENO, file, _strlen(file));

	write(STDERR_FILENO, "\n", 1);
}
