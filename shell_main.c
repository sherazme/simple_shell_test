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
	char *sh_prompt = "(SZshell) $ ", *user_input = NULL, *user_input_cp = NULL;
	size_t n = 0;
	ssize_t user_input_len;
	const char *delimit = " \n";
	int num_tokens = 0;

	(void)ac;/* declaring void variables */
	/* Create a loop for the shell's prompt */
	while (1)
	{
		_print(sh_prompt);
		user_input_len = getline(&user_input, &n, stdin);
		/* check if the getline failed or reached EOF or user use CTRL + D */
		if (user_input_len == -1)
		{
			_print("Exiting shell....\n");
			return (-1);
		}
		/* allocate space for a copy of the user_input */
		user_input_cp = malloc(sizeof(char) * user_input_len);
		if (user_input_cp == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		/* copy user_input to user_input_cp */
		_strcpy(user_input_cp, user_input);
		/********** split the string (user_input) into an array of words ********/
		num_tokens = strtoknum(user_input, delimit);
		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);
		argv_store(argv, user_input_cp, delimit);
		if (_strcmp(argv[0], "exit") == 0)
			break;
		/* execute the command */
		execute_command(argv);
	}
	/* free up allocated memory */
	free(user_input_cp);
	free(user_input);
	return (0);
}
