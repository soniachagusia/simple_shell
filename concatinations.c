#include "shell.h"

/**
  * strcat_x -  function that concatinates two strings
  * @src: first string t be concatinated
  * @dest: second string to be concatinated with the first one
  * Return: the  concatinated string
  */
char *strcat_x(char *src, char *dest)
{
	char *output;
	int f, j;
	int length;

	f = 0;
	j = 0;

	length = strlen(src) + strlen(dest) + 2;
	output = malloc(sizeof(char) * length);
	if (!output)
	{
		return (NULL);
	}
	while (src[f] != '\0')
	{
		output[j] = src[f];
		f++;
		j++;
	}
	if (j != 0)
	{
		output[j] = '/';
		j++;
	}
	f = 0;
	while (dest[f] != '\0')
	{
		output[j] = dest[f];
		f++;
		j++;
	}
	output[j] = '\0';
	free(dest);
	return (output);
}
