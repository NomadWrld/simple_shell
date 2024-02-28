#include "shell.h"

/**
 * concat_path - Concatenates directory and command to form a full path.
 * @dir: Directory string.
 * @cmd: Command string.
 *
 * Return: Pointer to the full path string.
 */
char *concat_path(char *dir, char *cmd)
{
	char *full_path = malloc(_strlen(dir) + 1 + _strlen(cmd) + 1);

	if (full_path == NULL)
		return (NULL);

	_strcpy(full_path, dir);
	_strcat(full_path, "/");
	_strcat(full_path, cmd);

	return (full_path);
}

/**
 * find_exec_path - Finds the full path of an executable in the search path.
 * @cmd: Command to find.
 * @search_path: Search path.
 *
 * Return: Pointer to the full path string if found, otherwise NULL.
 */
char *find_exec_path(char *cmd, char *search_path)
{
	char *path_copy = NULL, *dir = NULL, *full_path = NULL;

	if (search_path == NULL || cmd == NULL)
		return (NULL);

	path_copy = _strdup(search_path);
	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = concat_path(dir, cmd);

		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
