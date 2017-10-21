#include <stdio.h>
#include <string.h>
#include "builtins.h"

static void echo(char **phrases)
{
	unsigned i;

	for (i = 0; i < sizeof(phrases)/sizeof(phrases[0]); i++)
		puts(phrases[i]);
}

const char *commandNames[1] = {
	"echo"
};

#define CMD_COUNT sizeof(commandNames)/sizeof(commandNames[0])
static void (*commandFuncs[CMD_COUNT])(char**) = {
	&echo
};

extern void initializeCommands()
{
	unsigned i;

	for (i = 0; i < CMD_COUNT; i++)
	{
		builtins[i].name = commandNames[i];
		builtins[i].func = commandFuncs[i];
	}
}
