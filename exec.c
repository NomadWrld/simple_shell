#include "shell.h"

/**
 * exec_cmd - Execute command
 * @cmd: Command to execute
 * @status: Status pointer
 * @prog_name: Program name
 */
void exec_cmd(char *cmd, int *status, const char *prog_name)
{
	pid_t pid;
	char **args = NULL;
	char *full_path = NULL;
	CmdInfo cmd_info;

	pid = fork();
	if (pid == 0)
	{
		args = tokenize_input(cmd);
		if (args == NULL || args[0] == NULL)
		{
			free_str_array(args);
			free(cmd);
			return;
		}
		if (strchr(args[0], '/') != NULL)
			full_path = strdup(args[0]);
		else
			full_path = find_exec_path(args[0], get_env_variable("PATH"));

		cmd_info.cmd = cmd;
		cmd_info.args = args;
		cmd_info.full_path = full_path;
		cmd_info.prog_name = prog_name;

		exec_cmd_from_path(&cmd_info, status);
	}
	else
	{
		wait(status);
		if (WIFEXITED(*status))
			*status = WEXITSTATUS(*status);
		else
			*status = 127;
	}
	free(cmd);
}

/**
 * exec_cmd_from_path - Execute command from path
 * @info: Command info
 * @status: Status pointer
 */
void exec_cmd_from_path(CmdInfo *info, int *status)
{
	(void)status;

	if (info->full_path != NULL && access(info->full_path, F_OK) == 0)
	{
		if (access(info->full_path, X_OK) == -1)
		{
			handle_exec_error(info);
		}
		if (execve(info->full_path, info->args, environ) != -1)
		{
			free_str_array(info->args);
			free(info->full_path);
			exit(EXIT_SUCCESS);
		}
	}
	handle_exec_error(info);
}

/**
 * handle_exec_error - Handle execution error
 * @info: Command info
 */
void handle_exec_error(CmdInfo *info)
{
	print_exec_error(info->cmd, info->prog_name);
	free_str_array(info->args);
	free(info->cmd);
	free(info->full_path);
	exit(127);
}
