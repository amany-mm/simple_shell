#include "shell.h"

/**
* _strdup - duplicate a string
* @str: string
* Return: If str is NULL or if malloc() fails - NULL
*/
char *_strdup(char *str)
{
	char *array;
	int length;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);

	array = malloc(1 + (sizeof(char) * length));

	if (array == NULL)
		return (NULL);

	array[length] = '\0';
	while (length--)
		array[length] = str[length];

	return (array);
}


/**
* _strlen - string length
* @str: string pointer
* Return: string length
*/
int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}

	return (len);
}

/**
 * _strcpy - copy a string
 * @destination: destination
 * @source: source
 * Return: destination string pointer
 */
char *_strcpy(char *destination, char *source)
{
	int n;

	for (n = 0; source[n] != '\0'; n++)
	{
		destination[n] = source[n];
	}

	destination[n] = '\0';

	return (destination);
}


/**
* _strcmp - compare two strings
* @str1: 1st string
* @str2: 2nd string
* Return: integer <, = or > than zero
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((int)*str1 - (int)*str2);
}

/**
 * _strcat - concat 2 string
 * @destination: destination
 * @source: source
 * Return: destination result
 */
char *_strcat(char *destination, char *source)
{
	int n, length;

	length = _strlen(destination);

	for (n = 0; source[n] != '\0'; n++)
	{
		destination[n + length] = source[n];
	}

	destination[n + length] = '\0';

	return (destination);
}
