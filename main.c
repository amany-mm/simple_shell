#include "main.h"
/**
 * main - Entry point for the shell
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
char command[MAX_COMMAND_LENGTH];

while (1)
{
printf(PROMPT);
fflush(stdout);

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
if (feof(stdin))
{
printf("\nCtrl+D\n");
break;
}
else
{
perror("fgets");
continue;
}
}
command[strcspn(command, "\n")] = 0;

if (strlen(command) > 0)
{
execute_command(command);
}
}
return (0);
}
