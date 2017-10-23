#include "../types.h"
#define CMD_AMOUNT 3
cmd_t builtins[CMD_AMOUNT];
extern void help(char**);
extern void echo(char**);
extern void set(char**);
extern void initializeCommands();
