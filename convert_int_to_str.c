#include "shell.h"

/**
 * convert_int_to_str - convert int num to str
 * @n: The integer to be converted.
 * Return: string value of the integer,
 * or NULL on failure.
 */
char *convert_int_to_str(int n)
{
	int tmp = n, i = 0;
	char *n_copy;

	if (n == 0)/* digits count */
		i = 1;
	else
	{
		while (tmp != 0)
		{
			tmp = tmp / 10;
			i++;
		}
	}
    /* memory allocation */
	n_copy = malloc(sizeof(char) * (1 + i));
	if (!n_copy)
	{
		perror("memory allocation error");
		return (NULL);
	}

	n_copy[i] = '\0';/* null terminator */

	while (i != 0)
	{
		i--;
		n_copy[i] = '0' + n % 10;

		n = (n / 10);
	}

	return (n_copy);
}
