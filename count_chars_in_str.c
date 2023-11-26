#include "shell.h"

/**
 * count_chars_in_str - calculate occurrences of a char in a string
 * @str: string to search in
 * @c: character to search by
 * Return: no. of occurrence of a charater in string
 */
unsigned int count_chars_in_str(char *str, char c)
{
	unsigned int char_count = 0;

	while (*str != '\0')
	{
		if (*str != c && *(str + 1) == c)
			char_count++;

		str++;
	}

	return (char_count + 1);
}
