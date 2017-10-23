#include <stdio.h>
#include <string.h>
#include "builtins.h"

/*
 * functions which are used within the prompt
 * all must be of type void func(char **str)
 */

/* prints available commands */
static void help(char **unused)
{
	printf("help: print this help prompt\n");
	printf("echo: echo a string\n");
}

/* echos a string */
static void echo(char **phrases)
{
	unsigned i;

	for (i = 0; i < sizeof(phrases)/sizeof(phrases[0]); i++)
		puts(phrases[i]);
}

/* sets a variable */
static void set(char **var)
{
	void *variable; /* where the variable will be stored */
}

/* TODO: make arrays flexable - not hard coded */
char *commandNames[CMD_AMOUNT] = {
	"help",
	"echo"
};

/* TODO: make array type generic so any function can be used*/
static void (*commandFuncs[CMD_AMOUNT])(char**) = {
	&help,
	&echo
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
