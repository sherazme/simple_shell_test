#include "shell.h"
#include <string.h>
/**
 * get_builtin - to handle all builtin
 * @argv: the command
 * Return: 0 if success
 */
int get_builtin(char **argv)
{
	if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	else if (_strcmp(argv[0], "setenv") == 0)
	{
		char *name = argv[1];
		char *value = argv[2];
		int overwrite = 0;

		if (_getenv(name) != NULL)
			overwrite = 1;
		_setenv(name, value, overwrite);
		return (0);
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		char *name = argv[1];

		if (_getenv(name) != NULL)
			_unsetenv(name);
		return (0);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		char *name_dir;

		if (argv[1] == NULL)
			name_dir = _getenv("HOME");
		else
			name_dir = argv[1];
		_cd(name_dir);
	}
	return (-1);
}
/**
 * print_env - that print the each environment variable
 *
 * Return: void;
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * *_getenv - Check if the environment variable already exists
 * @name_env: the name of environment variable
 * Return: the value of it
 */
char *_getenv(char *env_var)
{
	int i = 0;
	char *key = NULL;

	while (environ[i])
	{
		/* Tokenize the environment variable using "=" as the delimiter*/
		key = strtok(environ[i], "=");

		if (key != NULL)
		{
			/*Compare the key with the target environment variable name*/
			if (_strcmp(env_var, key) == 0)
			{
				/* If a match is found, return the corresponding value*/
				return (strtok(NULL, "\n*"));
			}
		}
		i++;
	}

	/* If the environment variable is not found, return NULL*/
	return (NULL);
}
/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @varName: name of environment variable
 * @varValue: value of environment variable
 * @overwrite: 1 if if the environment variable already exists
 * Return: 0 in success
 */
int _setenv(char *varName, char *varValue, int overwrite)
{
	int i = 0, len = 0;
	char *new_env;

	if (!varName || !varValue)
	{
		_print("setenv: Invalid variable name or the value\n");
		return (-1);
	}
	while (environ[i])
	{
		len = _strlen(varName);
		if (strncmp(environ[i], varName, len) == 0)
		{
			if (overwrite)
			{
				new_env = malloc(_strlen(varName) + _strlen(varValue) + 2);
				_strcpy(new_env, varName);
				_strcat(new_env, "=");
				_strcat(new_env, varValue);
				environ[i] = new_env;
				return (0);
			}
			return (0);
		}
		i++;
	}
	new_env = malloc(_strlen(varName) + _strlen(varValue) + 2);
	_strcpy(new_env, varName);
	_strcat(new_env, "=");
	_strcat(new_env, varValue);
	environ[i] = new_env;
	environ[i + 1] = NULL;
	return (0);
}
/**
 * _unsetenv - to remove the environment variabl
 * @varName: the neme of environment variabl
 * Return: 0 in success
 */
int _unsetenv(char *varName)
{
	int i = 0, len = 0;

	if (!varName)
		return (-1);
	while (environ[i])
	{
		len = _strlen(varName);
		if (_strncmp(environ[i], varName, len) == 0 && environ[i][len] == '=')
		{
			/* Found the environment variable, remove it*/
			free(environ[i]);
			environ[i] = NULL;
			/* Shift the remaining variables to fill the gap*/
			while (environ[i + 1])
			{
				environ[i] = environ[i + 1];
				i++;
			}
			return (0);
		}
		i++;
	}
	return (0);
}
