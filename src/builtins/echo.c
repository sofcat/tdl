#include <stdio.h>
#include "builtins.h"

/* echos a string */
extern void echo(char **phrases)
{
	unsigned i;

	for (i = 0; i < sizeof(phrases)/sizeof(phrases[0]); i++)
		puts(phrases[i]);
}

