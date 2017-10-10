#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "cmd.h"
#include "signals.h"

struct downloaditem
{
	char *url;
	unsigned priority;
	float progress;
	struct downloaditem *next;
};

/* function to create the items, setting all values to NULL or zero */
void initalizeitem(struct downloaditem *new, struct downloaditem *prev)
{
	/* set all values to none */
	new->url = NULL;
	new->progress = 0.0;
	new->next = NULL;

	if (prev != NULL)
	{
		prev->next = new;
		printf("prev->next = new;\n");
	}
}

int main()
{
	struct sigaction sa; /* for signals */
	struct downloaditem inital; /* must have an an inital struct to allow for linking lists */
	char cmd[32]; /* commands which are typed in are stored here */

	sa.sa_handler = &handlesignal;


	initalizeitem(&inital, NULL);

	do {
		putchar('>');
	} while (fscanf(stdin, "%s", cmd) != EOF);
	return 0;
}
