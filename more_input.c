#include "shell.h"

/**
 * print_exec_error - Print execution error
 * @cmd: Command
 * @prog_name: Program name
 */
void print_exec_error(char *cmd, const char *prog_name)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, cmd, strlen(cmd));
		write(STDOUT_FILENO, ": command not found\n", 20);
	}
	else
	{
		write(STDERR_FILENO, prog_name, _strlen(prog_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, cmd, _strlen(cmd));
		write(STDERR_FILENO, ": not found\n", 12);
	}
}

/**
 * get_env_variable - Get environment variable
 * @name: Variable name
 * Return: Value of variable
 */
char *get_env_variable(const char *name)
{
	int i = 0;
	size_t length = _strlen(name);

	while (environ[i])
	{
		if (_strncmp(name, environ[i], length) == 0 && environ[i][length] == '=')
		{
			return (&environ[i][length + 1]);
		}
		i++;
	}
	return (NULL);
}
