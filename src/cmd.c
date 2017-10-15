#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "cmd.h"
#include "builtins.h"
/* space ascii in hex */
#define SPACE 0x20

/* finds the total amount of spaces (args) in str */
static unsigned totalArgs(char *str)
{
	int i;
	unsigned total = 0;

	if (strlen(str) > 0)
	{
		for (i = 0;; i++)
		{
			if (str[i] == '\0')
			{
				total++;
				break;
			}

			if (str[i] == SPACE)
				total++;
		}

		if (total == 0)
			return 1;
		else
			return total;
	}

	return 0;
}

static char **splitString(char *str, unsigned amount)
{
	unsigned index, prev, i, j, y;
	char *splitString[amount];
	/* splits string into an array of strings */
	/* index is for indexing 2d array (x-axis) */
	/* prev is how many times it looped before last space */
	/* i is the index for the string */
	index = 0, prev = 0, i = 0;
	while(1)
	{
		if (str[i] == SPACE || str[i] == '\0')
		{
			/* i - prev to calculate the distance from the last space */
			splitString[index] = calloc(i - prev, sizeof(char));

			if (splitString[index] < 0)
			{
				fprintf(stderr, "Error allocing memory: %s\n", strerror(errno));
				exit(255);
			}

			/* j is equal to the last instance of a space */
			/* y acts as a typical indexer for the y-axis of the buffer */
			/* while j is less than the current position, increment */
			for (j = prev, y = 0; j < i; j++, y++)
			{
				splitString[index][y] = str[j];
			}

			if (str[i] == '\0')
				break;

			index++;
			prev = i + 1; /* plus one to account for an additional space */
		}

		i++;
	}

	return splitString;
}

cmd_t *parseEntry(char *cmd)
{
	unsigned args = totalArgs(cmd);
	char **buffer;

	if (args == 0)
		return NULL;
	else if (args == 1)
	{
		buffer[0] = calloc(strlen(cmd), sizeof(char));
	}
	else
	{
		buffer = splitString(cmd, args);
	}
}
