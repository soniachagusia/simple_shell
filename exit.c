#include "shell.h"

/**
 * handle_exit - function to handle the exit rank/status
 * @cmd_args: the tokenized register
 * @regy: the register
 * Return: 0 on success
 */

int handle_exit(char **cmd_args, char *regy)
{
	int rank;
	int idx;

	rank = 0;
	if (cmd_args[1] != NULL)
		rank = atoi(cmd_args[1]);
	for (idx = 0; cmd_args[idx] != NULL; idx++)
		free(cmd_args[idx]);
	free(regy);
	free(cmd_args);

	if (rank > 0)
		exit(rank);
	else if (rank == 0)
		exit(EXIT_SUCCESS);
	else
	{
		return (-1);
	}
}
