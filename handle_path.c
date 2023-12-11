#include "shell.h"
#include <stdio.h>

/**
 * handle_path - is a function that checks if path exists or not
 * @cmd_args: pointer to the string used to store parsed commands arguments
 * @argv: an array of characters
 * @regy:  is a pointer to a string and is used to store user input
 */
void handle_path(char **cmd_args, char **argv, char *regy)
{
	char *path_t = NULL;

	path_t = malloc((strlen(cmd_args[0]) + 1) * sizeof(char));
	if (path_t == NULL)
	{
		perror("allocation failed");
	}

	else
	{
		strcpy(path_t, cmd_args[0]);
		if (!(access(path_t, F_OK) == 0))
			dprintf(STDERR_FILENO, "%s: %s: path not found\n", argv[0], regy);
		else
			execute(path_t, cmd_args);
	}

	free(path_t);
	if (path_t)
	{
	if (cmd_args != NULL)
		_free(cmd_args);
	}
}

/**
 * read_error - is funtion that exists if getline ufunction fails
 * @vw: is a function that stores the return value of getline function
 * @regy: is a pointer to a string and is used to store user input
 * Return: void
 */
void read_error(ssize_t vw, char *regy)
{
	if (vw == -1)
	{
		free(regy);
		exit(EXIT_FAILURE);
	}
}
