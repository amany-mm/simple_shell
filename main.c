#include "main.h"

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

        // Remove the newline character at the end of the command
        command[strcspn(command, "\n")] = 0;

        if (strlen(command) > 0)
        {
            execute_command(command);
        }
    }

    return 0;
}

