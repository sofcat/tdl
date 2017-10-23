#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include "cmd.h"
#include "builtins/builtins.h"
#include "types.h"
#define SPACE 0x20

extern cmd_t *createCmd(char *cmd)
{
	char *remove = " \n";
	char *token;
	int i = 0;
	cmd_t *newCmd = malloc(sizeof(cmd_t));

	/* removes spaces and newlines */
	token = strtok(cmd, remove);

	while (token != NULL)
	{
		if (i == 0)
			newCmd->name = token;
		else if (0 < i || i < 3)
			newCmd->args[i - 1] = token;

		i++;
		token = strtok(NULL, remove);
	}

	return newCmd;
}
