#include "shell.h"
/**
 * main - it is the entry
 * @argc: it is the number of arguments
 * @argv: the array arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int index = 0;
	ssize_t vw = 0;
	char *path_t, **cmd_args = NULL, **dir = NULL, *regy = NULL;
	size_t tracker = 0;

	if (!(argc != 0))
		perror("error encountered");
	while (1)
	{
		index++;
		show_prompt();
		fflush(stdout);
		vw = getline(&regy, &tracker, stdin);
		if (vw == EOF)
			end_of_file(regy);
		read_error(vw, regy);
		if ((strcmp(regy, "\n") == 0) || (regy[0] == ' ') || (regy[0] == '#'))
			continue;
		new_regy(&regy);
		del_var(regy);
		cmd_args = str_parser(regy);
		if (strcmp(cmd_args[0], "exit") == 0)
			handle_exit(cmd_args, regy);
		if (strchr(cmd_args[0], '/') != NULL)
		{
			handle_path(cmd_args, argv, regy);
			continue;
		}
		else
			path_t = get_path(cmd_args, dir);
		if (!(access(path_t, F_OK) == 0))
			fprintf(stderr, "%s: %d: %s: path not found\n", argv[0], index, regy);
		else
			execute(path_t, cmd_args);
		if (cmd_args != NULL)
			_free(cmd_args);
	}
	free(regy);
	return (0);
}
