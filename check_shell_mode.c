#include"shell.h"
/**
 * check_shell_mode - check shell mode
 * based on the number of command-line arguments (argc)
 * @argc: arguments counter
 * Return:-1 in case of error
 * 0 if non interactive mode
 * 1 if interactive mode
*/
int check_shell_mode(int argc)
{
	struct stat stat_stdin;

	/* system call to get info about file associated with file descriptor */
	fstat(STDIN_FILENO, &stat_stdin);

	/*   and  standard input is a terminal */
	if (argc == 1 && isatty(STDIN_FILENO))
		return (INTERACTIVE_MODE);

	/* only one command-line and standard input is not a terminal */
	if (argc == 1 && !isatty(STDIN_FILENO))
		return (NON_INTERACTIVE_PIPE);/* non-interactive mode,reading from a pipe. */

	/* there is at least one command-line argument */
	if ((argc >= 1))
		return (NON_INTERACTIVE_MODE);

	/* unknown mode error */
	return (ERROR);
}
