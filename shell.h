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
void execute_command(char **argv);
char *search_path(char *command);

/*helping functions*/

/*String functions*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
int strtoknum(char *str, const char *delim);
char * _strdup (char *s);

/*other functions*/
void argv_store(char **argv, char *str, const char *delim);
void _print(char *msg);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* SHELL_H */
