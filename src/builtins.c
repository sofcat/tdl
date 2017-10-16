#include <stdio.h>
#include <stdlib.h>
#include "builtins.h"

extern int test(char *string)
{
	printf("Horray, %s!\n", string);
	return 0;
}

extern int echo(char *phrase)
{
	puts(phrase);
	return 0;
}

extern const int (*commandFunctions[LIST_SIZE])(char*) = {
	test,
	echo
};

extern const char commandNames[LIST_SIZE][16] = {
	"test",
	"echo"
};

extern cmd_t *initalizeCommands[](int (*funcs[])(char*), char **names)
{
	int size = 0, i;

	while (size < sizeof(names)/sizeof(names))
	{
		size++;
	}

	cmd_t *cmd[size] = calloc(size, sizeof(cmd_t));

	for (i = 0; i < size; i++)
	{
		cmd[i]->name = names[i];
		cmd[i]->func = funcs[i];
	}
}

extern cmd_t *funcScan(char *search, cmd_t list)
{
	int i;

	for (i = 0; i < sizeof(names)/sizeof(char*); i++)
	{
		if (strncmp(search, names[i], 16) == 0)
			return &list[i];
	}

	return NULL;
}

