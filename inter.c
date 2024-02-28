#include "shell.h"

/**
 * interactive_mode - Interactive Mode
 * @prog_name: Program name
 * Return: Exit status
 */
int interactive_mode(const char *prog_name)
{
	char *user_input;
	int exit_status = 0;

	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		user_input = read_input();
		if (user_input == NULL)
			break;
		if (!handle_exit_cmd(user_input, &exit_status))
		{
			free(user_input);
			break;
		}
		if (!handle_env_cmd(user_input))
			continue;
		exec_cmd(user_input, &exit_status, prog_name);
	}

	return (exit_status);
}
