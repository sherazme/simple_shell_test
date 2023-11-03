
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void execmd(char **argv);
char *get_location(char *command);


char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
