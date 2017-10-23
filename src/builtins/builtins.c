#include <stdio.h>
#include <string.h>
#include "builtins.h"

/*
 * functions which are used within the prompt
 * all must be of type void func(char **str)
 */

/* TODO: make arrays flexable - not hard coded */
char *commandNames[CMD_AMOUNT] = {
	"help",
	"echo"
};

/* TODO: make array type generic so any function can be used */
extern void (*commandFuncs[CMD_AMOUNT])(char**) = {
	&help,
	&echo,
	&set
};

/* function which adds all functions to the global builtin array */
extern void initializeCommands()
{
	unsigned i;

	for (i = 0; i < CMD_AMOUNT; i++)
	{
		builtins[i].name = commandNames[i];
		builtins[i].func = commandFuncs[i];
	}
}
