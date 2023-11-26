#include "shell.h"

/**
 * _get_process_id - get current process id as string
 * Return: process id string
 */

char *_get_process_id()
{
	char *pid_str;
	pid_t pid = getpid();

	pid_str = convert_int_to_str(pid);
	return (pid_str);
}
