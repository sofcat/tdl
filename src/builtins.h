/* amount of items in each command array */
#define LIST_SIZE 2
/* global data */
const char *commandNames[16];
const int (*commandFunctions[])(char*);

/* user functions */
int test(char *string);
int echo(char *phrase);

/* program functions */
cmd_t *initalizeCommands(int (*funcs[])(char*), char **names);
cmd_t *funcScan(char *search, cmd_t list);
