#include "shell.h"

/**
 * argv_store - Store each token in the argv array
 *
 * @argv: Argv array pointer
 *
 * @str: String to tokenize.
 *
 * @delim: delemter
 *
 * Return: void
 */
void argv_store(char **argv, char *str, const char *delim)
{
	int i;
	char *token;

	token = strtok(str, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
		argv[i] = NULL;
}

/**
 * _print - prints messages to screen.
 *
 * @msg: String to be printed.
 *
 * Return: void
 */
void _print(const char *msg) 
{
    write (STDOUT_FILENO, msg, _strlen(msg));
}

