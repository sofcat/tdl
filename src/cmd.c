#include <stdio.h>
#include <string.h>
#include "types.h"

static int test(char *string)
{
	printf("Horray, %s!\n", string);
	return 0;
}

static int echo(char *phrase)
{
	puts(phrase);
	return 0;
}

int parsecmd(char *cmd)
{
}
