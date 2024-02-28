#include "shell.h"

/**
 * non_interactive_mode - Non-interactive Mode
 * @prog_name: Program name
 * Return: Exit status
 */
int non_interactive_mode(const char *prog_name)
{
	char *user_input;
	int exit_status = 0;

	while ((user_input = read_input()) != NULL)
	{
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
