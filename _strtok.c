#include "shell.h"

/**
 * _strtok - custom strtok
 * @s: string
 * @delim: delimeter
 * Return: tokenzied s
 *
*/
char *_strtok(char *s, const char *delim)
{
	return (strtok(s, delim));
}
