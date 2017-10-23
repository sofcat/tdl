#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "cmd.h"
#include "builtins/builtins.h"
#include "parse.h"
#include "signals.h"
#include "types.h"

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

int main(void)
{
	dl_t inital; /* must have an an inital struct to allow for linking lists */
	cmd_t *current; /* cmd is converted to this to be associated with functions */
	char cmd[64]; /* commands which are typed in are stored here */
	char *prompt = "> "; /* the command prompt TODO: make changable */

	/* set up signals */
	signal(SIGINT, death);
	signal(SIGTERM, death);

	initializeCommands();
	initalizeItem(&inital, NULL);
	zeroString(cmd); /* ensure that string has been initalized */

	do {
		if (strlen(cmd) > 0)
		{
			current = createCmd(cmd);
			if (parseEntry(current->name, current->args) != 0)
				puts("Error: command not found");

			free(current);
			zeroString(cmd);
		}
		printf("%s", prompt);
	} while (fgets(cmd, sizeof(cmd), stdin) != NULL);

	return 0;
}
