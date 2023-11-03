#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

/*main functions*/
void execmd(char **argv);
char *get_location(char *command);

/*helping functions*/

/*String functions*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
int strtoknum(char *str, const char *delim);

/*other functions*/
void argv_store(char **argv, char *str, const char *delim);
void _print(const char *msg)

#endif /* SHELL_H */
