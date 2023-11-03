#include "shell.h"

/**
 * main - Runs a simple UNIX command interpreter.
 * @ac: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0.
 */
 
int main(int ac, char **argv)
{
	char *prompt = "(SZshell) $ ", *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;

	(void)ac;/* declaring void variables */
	/* Create a loop for the shell's prompt */
	while (1)
	{
		_print(prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/* check if the getline failed or reached EOF or user use CTRL + D */
		if (nchars_read == -1)
		{
			_print("Exiting shell....\n");
			return (-1);
		}
		/* allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		/* copy lineptr to lineptr_copy */
		_strcpy(lineptr_copy, lineptr);
		/********** split the string (lineptr) into an array of words ********/
		num_tokens = strtoknum(lineptr, delim);
		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);
		argv_store(argv, lineptr_copy, delim);
		/* execute the command */
		execute_command(argv);
	}
	/* free up allocated memory */
	free(lineptr_copy);
	free(lineptr);
	return (0);
}
