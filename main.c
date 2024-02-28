#include "shell.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Exit status
 */
int main(int argc, char *argv[])
{
	int exit_status = 0;
	const char *prog_name = argv[0];

	(void)argc;

	if (isatty(STDIN_FILENO))
		exit_status = interactive_mode(prog_name);
	else
		exit_status = non_interactive_mode(prog_name);

	return (exit_status);
}
