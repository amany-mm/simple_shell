#include "shell.h"

/**
 * _get_status - get integer status value equivalent string value
 * @num: number
 * Return: status string value
 */
char *_get_status(int num)
{
	char *status;

	status = convert_int_to_str(num);
	return (status);
}
