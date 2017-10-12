#include <stdio.h>

int parsecmd(char *cmd)
{
	int i;
	for (i = 0; i < strlen(cmd); i++)
	{
		printf("%X\n", cmd[i]);
	} 
}
