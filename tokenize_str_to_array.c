#include "shell.h"

/**
 * tokenize_str_to_array - converts string to array
 * @str: string
 * Return: a pointer to a char array containing the converted text
 */
char **tokenize_str_to_array(char *str)
{
	unsigned int count_chars;
	char **cmd_lines;
	char *cmd, *token;
	int n;

	cmd_lines = NULL;
	n = 0;
	count_chars = 0;

	count_chars = count_chars_in_str(str, '\n');

	/* memory allocation */
	cmd_lines = (char **)malloc((count_chars + 1) * sizeof(char *));

	/* input str is tokenized with delimiter set to newline */
	token = _strtok(str, "\n");

	/* first token (command) is duplicated */
	cmd = _strdup(token);

	cmd_lines[n++] = cmd;
	while (token != NULL)
	{
		token = _strtok(NULL, "\n");

		if (token != NULL)
		{
			cmd = _strdup(token);
			cmd_lines[n++] = cmd;
		}
	}

	free(str);
	cmd_lines[n] = NULL;

	return (cmd_lines);
}
