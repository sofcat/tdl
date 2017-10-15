#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "cmd.h"
#include "signals.h"

/* function to create the items, setting all values to NULL or zero */
static void initalizeItem(dl_t *new, dl_t *prev)
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
static void zeroString(char *str)
{
	unsigned i;

	for (i = 0; i < strlen(str); i++)
		str[i] = 0;
}

int main()
{
	dl_t inital; /* must have an an inital struct to allow for linking lists */
	char cmd[CMD_SIZE]; /* commands which are typed in are stored here */
	cmd_t *current; /* cmd is converted to this to be associated with functions */
	char *prompt = "> "; /* the command prompt TODO: make changable */

	/* set up signals */
	signal(SIGINT, death);
	signal(SIGTERM, death);

	initalizeItem(&inital, NULL);
	zeroString(cmd);

	do {
		if (strlen(cmd) > 0)
		{
			current = parseEntry(cmd);
			free(current);
		}
		printf("%s", prompt);
	} while (fgets(cmd, sizeof(cmd), stdin) != NULL);

	return 0;
}
