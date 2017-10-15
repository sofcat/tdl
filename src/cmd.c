#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "cmd.h"
#include "types.h"
#include "builtins.h"
/* space ascii in hex */
#define SPACE 0x20

/*
static int parseCmd(char *cmd)
{
	return 0;
}

static int parseArgs(char *items, ...)
{
	return 0;
}
*/

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

int parseEntry(char *cmd)
{
	unsigned i, j, y, index, prev;
	char *buffer[totalArgs(cmd)];

	/* splits string into an array of strings */
	/* index is for indexing 2d array (x-axis) */
	/* prev is how many times it looped before last space */
	/* i is the index for the cmd string */
	index = 0, prev = 0, i = 0;
	while(i < strlen(cmd) + 1)
	{
		if (cmd[i] == SPACE || cmd[i] == '\0')
		{
			/* i - prev to calculate the distance from the last space */
			buffer[index] = calloc(i - prev, sizeof(char));

			if (buffer[index] < 0)
			{
				fprintf(stderr, "Error allocing memory: %s\n", strerror(errno));
				exit(255);
			}

			/* j is equal to the last instance of a space */
			/* y acts as a typical indexer for the y-axis of the buffer */
			/* while j is less than the current position, increment */
			for (j = prev, y = 0; j < i; j++, y++)
			{
				buffer[index][y] = cmd[j];
			}

			if (cmd[i] == '\0')
				break;

			index++;
			prev = i + 1; /* plus one to account for an additional space */
		}

		i++;
	}

	for (i = 0; i < index; i++)
	{
		printf("%s\n", buffer[i]);
	}
}
