#ifndef _MAIN_H
#define _MAIN_H

#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>


#define MAX_COMMAND_LENGTH 100
#define PROMPT "#cisfun$ "
#define MAX_ARGS 10

void execute_command(char *cmd);
#endif
