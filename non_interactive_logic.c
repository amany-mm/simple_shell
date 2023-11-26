#include "shell.h"

/**
 * non_interactive_file_logic - handle the processing of shell
 * commands from a specified file.
 * @file: file name containing shell commands
 * @shell: shell name
 * Return: array of shell commands.
 */
char **non_interactive_file_logic(char *file, char *shell)
{
	int fd;
	struct stat stat_file;
	size_t read_chars;
	char *txt, **cmd_lines;

	/* check if the specified file exists and is a regular file */
	if (stat(file, &stat_file) != -1)
	{
		if (S_ISREG(stat_file.st_mode))
		{
			fd = open(file, O_RDONLY);
			if (fd  == -1)
				exit(ERROR);
			if (stat_file.st_size == 0)
				exit(0);

			txt = malloc((stat_file.st_size + 1) * sizeof(char));
			if (!txt)
				return (NULL);
			read_chars = read(fd, txt, stat_file.st_size);
			if ((int) read_chars == ERROR)
				perror("read error");
			close(fd);
			txt[read_chars - 1] = '\0';/* Null-terminates */
			/* convert the file content into an array of strings */
			if (txt)
				cmd_lines = tokenize_str_to_array(txt);/* strtok */
			return (cmd_lines);
		}
		else
			exit(0);
	}
	else
	{
		can_not_open_logic(shell, 0, file);
		exit(NOT_FOUND);
	}
	return (NULL);
}

/**
 * non_interactive_pipes_logic - Handles pipes in
 * non interactive shell cmds
 * Return: array of commands
 */
char **non_interactive_pipes_logic()
{
	char characters[2048], *read_txt, **cmd_lines;
	size_t chars_read_total = 0;
	ssize_t read_bytes;
	int n, flags;

	flags = 0;
	cmd_lines = NULL;
	read_txt = NULL;
	/* read input from STDIN */
	while ((read_bytes = read(STDIN_FILENO, characters, 2048)) > 0)
		chars_read_total = chars_read_total + read_bytes;
	if (read_bytes == -1)
	{
		perror("reading error");
		exit(ERROR);
	}
	if (chars_read_total > 2048)/* ensure null terminated string */
		characters[2048 - 1] = '\0';
	else
		characters[chars_read_total - 1] = '\0';
	/* check if there are non space characters in input */
	for (n = 0; characters[n]; n++)
	{
		if (characters[n] != ' ')
			flags = 1;
	}
	/* If no non-space characters found return NULL */
	if (flags == 0)
		return (NULL);
	chars_read_total = _strlen(characters);
	/* Allocate memory for read text */
	read_txt = (char *)malloc((chars_read_total + 1) * sizeof(char));
	if (read_txt != NULL)
	{/* Copy characters to read_txt */
		_strcpy(read_txt, characters);
		read_txt[chars_read_total] = '\0';
		/* tokenize read text into an array of commands */
		cmd_lines = tokenize_str_to_array(read_txt);
	}
	return (cmd_lines);
}

