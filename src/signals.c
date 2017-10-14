#include <stdlib.h>
#include <stdio.h>
#include "signals.h"

void death(int signal)
{
	printf("Quiting\n");
	exit(signal);
}
