#include "shell.h"

/**
 * _atoi - convert str to integer
 * @str: str
  * Return: integer
 */
int _atoi(char *str)
{
	char _positive;
	unsigned int num, j;

	num = 0;
	j = 0;

	while (str[j] != '\0')
	{
		if (!((str[j] >= '0') && (str[j] <= '9')))
			return (-1);

		if (((str[j] >= '0') && (str[j] <= '9')))
			num = (num * 10) + (str[j] - '0');

		else if (str[j] == '+')
			_positive++;

		j++;
	}
	return (num);
}
