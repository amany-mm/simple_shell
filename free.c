#include "shell.h"

/**
 * free_everything - free everything
 * @cmd: user command
 * @num: command count
 * @cmd_lines: command lines
 * @env: env
 * @cmd_arr: command and arguments array
 * @curr: current path lst_path
 * Return: Nothing
*/
void free_everything(char **cmd_lines, int num, lst_path *env, lst_path *curr,
		char *cmd, char **cmd_arr)
{
	if (cmd_lines)
	{
		free(cmd_lines[num]);
		if (cmd_lines)
			free(cmd_lines);
	}

	free_path_lst(env);
	free_path_lst(curr);

	free_cmds_all(cmd, cmd_arr);
}


/**
* free_cmds_all - Free commands all
* @cmd: command
* @cmd_arr: command and arguments array
* Return: NULL
*/
void free_cmds_all(char *cmd, char **cmd_arr)
{
	free(cmd);

	free_array(cmd_arr);
}

/**
 * free_array - free array memory allocation
 * @argv: argument vector
 * Return : NULL
 */
void free_array(char **argv)
{
	char **char_curr;

	if (argv == NULL)
		return;

	char_curr = argv;

	while (*char_curr != NULL)
	{
		free(*char_curr);
		char_curr++;
	}
	free(argv);
}

/**
* free_path_lst - Free linked list path
* @head: head pointer
* Return: NULL
*/
void free_path_lst(lst_path *head)
{
	lst_path *p = head;
	lst_path *next_node;

	/* Iterate through linked list*/
	while (p != NULL)
	{
		/* Save reference to next node */
		next_node = p->next;

		free(p->path);/* Free path string of current node */

		free(p); /* Free the current node */

		/*  Move to next node in linked lists */
		p = next_node;
	}
}

