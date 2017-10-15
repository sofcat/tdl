#include <stdlib.h>
#include <stdio.h>
#include "signals.h"

void cleanup(void *p)
{
	int i;
}

void death(int signal)
{
	printf("Quiting\n");
	exit(signal);
}
