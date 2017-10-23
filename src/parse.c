#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "builtins/builtins.h"
#include "types.h"

extern int parseEntry(char *name, char **args)
{
	unsigned i;

	for (i = 0; i < sizeof(builtins)/sizeof(builtins[0]); i++)
	{
		if (strcmp(name, builtins[i].name) == 0)
		{
				builtins[i].func(args);
				return 0;
		}
	}

	return 1;
}
