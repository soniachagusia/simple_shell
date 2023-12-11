#include "shell.h"

/**
 * new_regy - function that removes comments from a string
 * @regy: pointer to a string with comments
  */

void new_regy(char **regy)
{
	size_t w;
	char *rm;
	char *regist;

	if (!(strncmp(*regy, "echo", 4) == 0))
	{
		rm = strchr(*regy, '#');
		if (rm != NULL)
		{
			w = strlen(*regy) - strlen(rm);
			regist = (char *) malloc(w + 100);
			if (regist != NULL)
			{
				strncpy(regist, *regy, w);
				regist[w] = '\0';
				free(*regy);
				*regy = regist;
			}
		}
	}
}
