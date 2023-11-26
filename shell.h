#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* error codes */
#define ERROR -1
#define EXIT_ERROR 2
#define PERMISSION_DENIED 126
#define NOT_FOUND 127

/* modes */
#define NON_INTERACTIVE_MODE 0
#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPE 2

/* File */
#define CANNOT_OPEN_FILE_ERROR 11

#define CUSTOM_TOKEN_DELIMITER " \t\r\n\a\""


/**
 * struct lst_path - environment path variable nodes
 * @length: path length
 * @path: path environment variable
 * @next: points to the next node
*/
typedef struct lst_path
{
	unsigned int length;
	char *path;
	struct lst_path *next;
} lst_path;

extern char **environ; /* Public variable */


int check_shell_mode(int argc);

/* linked list path */
lst_path *convert_paths_to_linkedlist();
lst_path *add_nodepath_to_linkedlst(lst_path **head, char *path);
size_t print_linkedlist(const lst_path *head);


char *flags_specific_logic(char *token, char *cmd, char **args, int status);
unsigned int count_char(char *string, char character);

char **convert_cmdline_to_array(char *cmd_line, int status);
char *read_cmd_user(lst_path *curr);
int check_dir_exist(char *cmd, char **args, int num, char **cmd_arr,
					int *status, char *cmd_before);

/* non -builtin cmd */
void cmds_nonbuiltin_logic(char **cmd_array, char *env[], int *status,
int n, lst_path *current, char *argv[]);

/* builtin cmd */
int cmds_builtin_logic(char *cmd, char **cmd_arr, lst_path *current,
char *shell, int n, int *status, lst_path *env_list,
char **cmd_lines, char **argv);
void execute_command(char *path, char **argv, char **env, int *status);
char *check_cmd_access(char *cmd, lst_path *curr);
char **search_cmd_file(int mode, char *file, char *shell);
char **non_interactive_file_logic(char *file, char *shell);

char **tokenize_str_to_array(char *str);
unsigned int count_chars_in_str(char *str, char c);

void can_not_open_logic(char *prog, int num, char *file);


char *convert_int_to_str(int num);
int _atoi(char *str);
char *_get_process_id();

/* string helpers */
int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, char *source);
char *_strtok(char *s, const char *delim);

char *_get_status(int status);

/* env */
char *_get_env_value(const char *env_var_name);

/* builtin */
int cmds_builtin_logic(char *cmd, char **cmd_arr, lst_path *curr, char *shell,
			int num, int *status, lst_path *env_lst, char **cmd_lines, char **argv);
void _env(int *s);
void _exit_logic(char *cmd, char **cmd_arr, lst_path *curr, char *shell,
		int num, int *status, lst_path *env, char **cmd_lines);
void _setenv(char *key, char *value, lst_path *curr);
int _cd(char **cmd_arr, char **argv);

/* free */
void free_cmds_all(char *cmd, char **cmd_arr);
void free_array(char **argv);
void free_everything(char **cmd_lines, int num, lst_path *env, lst_path *curr,
		char *command, char **cmd_arr);
void free_path_lst(lst_path *head);

/* non-interactive logic */
char **non_interactive_file_logic(char *file, char *shell);
char **non_interactive_pipes_logic();

/* errors */
void _print_errors(char *shell, int num, char *cmd_arr, int err_type);
#endif

