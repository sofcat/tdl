#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	}
}

/* makes all string values zero */
void zerostring(char *str)
{
	unsigned i;

	for (i = 0; i < strlen(str); i++)
		str[i] = 0;
}

int main()
{
	struct sigaction *sa; /* for signals */
	dl_t inital; /* must have an an inital struct to allow for linking lists */
	char cmd[CMD_SIZE]; /* commands which are typed in are stored here */
	char *prompt = "> "; /* the command prompt TODO: make changable */

	initalizeitem(&inital, NULL);
	zerostring(cmd);

	do {
		if (strlen(cmd) > 0)
		{
			parsecmd(cmd);
		}
		printf("%s", prompt);
	} while (fgets(cmd, sizeof(cmd), stdin) != NULL);
	return 0;
}
