#include "shell.h"

/**
  *get_tok_path - is a function that gets and  tokenizes path
  *Return: the tokenirized path if it was found
  */
char **get_tok_path(void)
{
	char **dir;
	char *env_path;
	char *env_copy;
	char *v;
	char *w;
	char *delimeta = ":";
	int idx = 0;
	int looper = 0;
	size_t store;

	store = strlen(getenv("PATH"));
	env_path = malloc(store + 1);
	strcpy(env_path, getenv("PATH"));
	env_copy = strdup(env_path);
	if (env_copy == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	v = strtok(env_path, delimeta);
	while (v != NULL)
	{
		looper++;
		v = strtok(NULL, delimeta);
	}
	dir = malloc(sizeof(char *) * (looper + 1));
	w = strtok(env_copy, delimeta);
	idx = 0;
	while (w != NULL)
	{
		dir[idx] = (char *) strdup(w);
		w = strtok(NULL, delimeta);
		idx++;
	}
	dir[idx] = NULL;
	free(env_copy);
	free(env_path);
	return (dir);
}

/**
  *get_path - gets the concatenated command for execve
  *@cmd_args: pointer to array that holds tokenized input from strparse
  *@dir: pointer to array that holds tokenized path
  *Return: returns 1st argument for execve
  */

char *get_path(char **cmd_args, char **dir)
{
	char *tok;
	int idx;
	struct stat _fileinfo;

	dir = get_tok_path();
	tok = getcwd(NULL, 0);
	for (idx = 0; dir[idx] != NULL; idx++)
	{
		chdir(dir[idx]);
		if (stat(cmd_args[0], &_fileinfo) == 0)
		{
			cmd_args[0] = strcat_x(dir[idx], cmd_args[0]);
			break;
		}
	}
	for (idx = 0; dir[idx] != NULL; idx++)
		free(dir[idx]);
	chdir(tok);
	free(tok);
	free(dir[idx]);
	free(dir);
	return (cmd_args[0]);
}
