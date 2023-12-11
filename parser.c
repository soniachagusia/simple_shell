#include "shell.h"
#include <strings.h>

/**
 * str_parser - function that parses pointers to a string
 * @regy: string pointer to be passed
 * Return: the parsed string
 */

char **str_parser(char *regy)
{
	char *current = NULL, *regy_copy = NULL, *current_copy = NULL;
	char **current_array = NULL;
	char *delimeta = " \t\n";
	int current_count = 0, idx = 0, track = 0;

	regy_copy = malloc((strlen(regy) + 1) * sizeof(char));
	if (regy_copy == NULL)
	{
		perror("Mem Allocation Failed");
		return (NULL);
	}
	strcpy(regy_copy, regy);
	current = strtok(regy, delimeta);
	while (current != NULL)
	{
		current_count++;
		current = strtok(NULL, delimeta);
	}
	current_array = malloc(sizeof(char *) * (current_count + 1));
	if (current_array == NULL)
		return (NULL);
	current_copy = strtok(regy_copy, delimeta);
	while (current_copy != NULL)
	{
		current_array[idx] = strdup(current_copy);
		if (current_array[idx] == NULL)
		{
			for (track = 0; track < idx; track++)
				free(current_array[track]);
			free(current_array);
			free(regy_copy);
			return (NULL);
		}
		current_copy = strtok(NULL, delimeta);
		idx++;
	}
	current_array[idx] = NULL;
	free(regy_copy);
	return (current_array);
}
