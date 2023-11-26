#include "shell.h"

/**
 * flags_specific_logic - Handles specific flags in cmd line token
 * @token: Token from the command line
 * @cmd: Original command line string
 * @args: Array of strings representing cmd and its arguments
 * @status: Command status.
 * Return: Processed command string after handling flags.
 */
char *flags_specific_logic(char *token, char *cmd, char **args, int status)
{
	char *variable, *processed_cmd, *line_copy;

	/* Store the original command line for later freeing */
	line_copy = cmd;

	/* Check if the token is NULL */
	if (token == NULL)
	{
		/*Free the dynamically allocated memory for args and line_copy */
		free(args);
		free(line_copy);
		return (NULL);
	}
	/* Check specific flags and handle accordingly */
	if (_strcmp("$$", token) == 0)
		processed_cmd = _get_process_id();
	else if (_strcmp("$?", token) == 0)
		processed_cmd = _get_status(status);
	else if ((token[0] == '$') && (token[1]))
	{
		/* Retrieve environment variable and duplicate its value */
		variable = _get_env_value(&token[1]);
		if (variable)
			processed_cmd = _strdup(variable);
		else
			processed_cmd = _strdup("");
	}
	else
		processed_cmd = _strdup(token);
	/* Return the processed command string */
	return (processed_cmd);
}


/**
 * convert_cmdline_to_array - convert cmdline into array of chars
 * @cmd_line: Command line string
 * @status: Command status
 * Return: characters array of command and arguments
 */
char **convert_cmdline_to_array(char *cmd_line, int status)
{
	char **args, *cmd, *cmd_line_copy, *env_variables, *token;
	int chars_count, j = 0;

	if (cmd_line[0] == '\0')
		return (NULL);
	cmd_line_copy = _strdup(cmd_line);
	if (cmd_line_copy == NULL)
		return (NULL);
	/* Count number of spaces in the command line to determine array size */
	chars_count = count_chars_in_str(cmd_line_copy, ' ');
	args = malloc(sizeof(char *) * (chars_count + 1));
	token = _strtok(cmd_line_copy, CUSTOM_TOKEN_DELIMITER);
	cmd = flags_specific_logic(token, cmd_line, args, status);
	args[j++] = cmd;
	while (token != NULL)/* Tokenize and process each token */
	{
		token = _strtok(NULL, CUSTOM_TOKEN_DELIMITER);
		if (token != NULL)
		{
			if (_strcmp("$$", token) == 0)
				cmd = _get_process_id();
			else if (_strcmp("$?", token) == 0)
				cmd = _get_status(status);
			else if ((token[0] == '$') && (token[1]))
			{
				/* Retrieve environment variable and duplicate its value */
				env_variables = _get_env_value(&token[1]);
				if (env_variables)
					cmd = _strdup(env_variables);
				else
					cmd = _strdup("");
			}
			else
				cmd = _strdup(token);
			args[j++] = cmd;
		}
	}
	args[j] = NULL;/* NULL terminator */
	free(cmd_line_copy);
	return (args);
}
