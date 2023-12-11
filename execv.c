#include "shell.h"
/**
*del_var - function that removes trailling white spaces
*@string: the string modified
*Return: the clear string
*/

char *del_var(char *string)
{
int len = strlen(string);

if (len > 0 && string[len - 1] == '\n')
	string[len - 1] = '\0';

return (string);
}

/**
*execute -  fucntion to execute  path directories
*@path_t: 1st arguement for execve
*@cmd_args: pointer to array containing arguements to cmdpath
*Return: void
*/

void execute(char *path_t, char **cmd_args)
{
pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Failed to fork");
		return;
	}
	else if (pid == 0)
	{
		if ((execve(path_t, cmd_args, environ)) == -1)
		{
			perror("Failed to execute, try again");
			exit(1);
		}
	}
	else
		wait(NULL);

}

/**
*_free - Frees array of command strings
*@cmd_args: Array containing commands
*Return: Void
*/

void _free(char **cmd_args)
{
int idx;

for (idx = 0; cmd_args[idx] != NULL; idx++)
	free(cmd_args[idx]);
free(cmd_args);

}

/**
  *end_of_file - end of file condition
  *@regy: pointer to input
  *Return: nothing
  */

void end_of_file(char *regy)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(regy);
	exit(0);
}

/**
 * show_prompt -  function displays prompt
  *Return: Nothing
  */

void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		char *new_prompt = "$ ";

		write(STDOUT_FILENO, new_prompt, 2);
	}
}
