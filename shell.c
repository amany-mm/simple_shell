#include "main.h"
/**
 * execute_command - Matches a command with a corresponding
 *               shellby builtin function.
 * @cmd: The command to match.
 *
 * Return: void
 */
void execute_command(char *cmd)
{
	char *command = (char *)malloc(sizeof(char) * strlen(cmd));
	int status;
	char *token = strtok(command, " ");

	strcpy(command, cmd);
	while (token != NULL)
	{
		if (strcmp(token, "exit") == 0)
		{
			exit(0);
		}
		else if (strcmp(token, "cd") == 0)
		{
			token = strtok(NULL, " ");
			if (token != NULL)
			{
				chdir(token);
			}
		}
		else
		{
			pid_t pid = fork();

			if (pid == 0)
			{
				execlp(token, token, NULL);
				exit(EXIT_FAILURE);
			}
			else if (pid < 0)
			{
				perror("fork");
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
		token = strtok(NULL, " ");
	}
	free(command);
}
