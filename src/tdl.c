#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "types.h"
#include "cmd.h"
#include "signals.h"

/* function to create the items, setting all values to NULL or zero */
void initalizeitem(struct downloaditem *new, struct downloaditem *prev)
{
	/* set all values to none */
	new->url = NULL;
	new->progress = 0.0;
	new->next = NULL;
	new->state = WAITING;

	if (prev != NULL)
	{
		prev->next = new;
		printf("prev->next = new;\n");
	}
}

int main()
{
	struct sigaction *sa; /* for signals */
	dl_t inital; /* must have an an inital struct to allow for linking lists */
	char cmd[CMD_SIZE]; /* commands which are typed in are stored here */

	initalizeitem(&inital, NULL);

	do {
		putchar('>');
	} while (fgets(cmd, sizeof(cmd), stdin) != NULL);
	return 0;
}
