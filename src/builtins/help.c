#include <stdio.h>
#include "builtins.h"

/* prints available commands */
extern void help(char **unused)
{
	printf("help: print this help prompt\n");
	printf("echo: echo a string\n");
}
