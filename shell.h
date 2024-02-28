#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stddef.h>

#define MAX_TOKENS_NUM 100

extern char **environ;

/**
 * struct CmdInfo - Structure for command information
 * @cmd: Command string
 * @args: Array of command arguments
 * @full_path: Full path to the executable file
 * @prog_name: Program name associated with the command
 *
 * This structure encapsulates information about a command, including its
 * command string, arguments, full path to the executable file, and the program
 * name associated with the command execution.
 */
typedef struct CmdInfo
{
	char *cmd;
	char **args;
	char *full_path;
	const char *prog_name;
} CmdInfo;

/* Function prototypes */
int interactive_mode(const char *prog_name);
int non_interactive_mode(const char *prog_name);
void exec_cmd(char *cmd, int *status, const char *prog_name);
void exec_cmd_from_path(CmdInfo *info, int *status);
void handle_exec_error(CmdInfo *info);
char *find_exec_path(char *cmd, char *search_path);
char **tokenize_input(const char *input);
void free_str_array(char **array);
int handle_exit_cmd(char *cmd, int *status);
char *read_input(void);
int handle_env_cmd(char *cmd);
void print_exec_error(char *cmd, const char *prog_name);
char *get_env_variable(const char *name);
void _putchar(char c);
void _puts(const char *s);
size_t _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *s, int c);

#endif /* SHELL_H */
