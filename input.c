#include "shell.h"

/**
 * tokenize_input - Tokenize input
 * @input: Input string
 * Return: Tokenized array
 */
char **tokenize_input(const char *input)
{
	char *str;
	int count = 0;
	char **result;
	char *token;

	str = _strdup(input);
	result = malloc(MAX_TOKENS_NUM * sizeof(*result));

	token = strtok(str, " \n\t");

	while (token != NULL && count < MAX_TOKENS_NUM - 1)
	{
		if (_strlen(token) > 0)
		{
			result[count] = _strdup(token);
			count++;
		}
		token = strtok(NULL, " \n\t");
	}

	result[count] = NULL;
	free(str);

	return (result);
}

/**
 * free_str_array - Free string array
 * @array: Array to free
 */
void free_str_array(char **array)
{
	int i;

	for (i = 0; array[i]; ++i)
		free(array[i]);
	free(array);
}

/**
 * handle_exit_cmd - Handle exit command
 * @cmd: Command
 * @status: Status pointer
 * Return: 1 if not exit command, else exit
 */
int handle_exit_cmd(char *cmd, int *status)
{
	if (_strcmp(cmd, "exit") == 0)
	{
		if (*status != 0)
		{
			free(cmd);
			exit(2);
		}
		else
		{
			free(cmd);
			exit(0);
		}
	}
	return (1);
}

/**
 * read_input - Read input
 * Return: User input
 */
char *read_input(void)
{
	char *cmd = NULL;
	size_t buffer_size = 0;
	ssize_t line_length;

	line_length = getline(&cmd, &buffer_size, stdin);
	if (line_length == -1)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
			putchar('\n');
		return (NULL);
	}
	if (cmd[line_length - 1] == '\n')
		cmd[line_length - 1] = '\0';

	return (cmd);
}

/**
 * handle_env_cmd - Handle env command
 * @cmd: Command
 * Return: 0 if env command, else 1
 */
int handle_env_cmd(char *cmd)
{
	int i = 0;

	if (_strcmp(cmd, "env") == 0)
	{
		while (environ[i])
			_puts(environ[i++]);
		free(cmd);
		return (0);
	}
	return (1);
}
