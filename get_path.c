#include "shell.h"

/**
 * search_path - search command path in environment path.
 *
 * @commad: command to search for.

 * Return: command full path.
 */

char *search_path(char *command)
{
	char *path, *path_cp, *token, *exe_file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		/* Duplicate the path string*/
		path_cp = _strdup(path);
		/* Get length of the command that was passed */
		cmd_len = _strlen(command);
		/* Let's break down the path variable and get all the directories available*/
		token = strtok(path_cp, ":");
		while (token != NULL)
		{
			/* Get the length of the directory*/
			dir_len = _strlen(token);
			/* allocate memory for storing command name and directory name */
			exe_file_path = malloc(cmd_len + dir_len + 2);
			/* NB: we added 2 for the slash and null character*/
			/* build command by copying directory path and concatenate command*/
			_strcpy(exe_file_path, token);
			_strcat(exe_file_path, "/");
			_strcat(exe_file_path, command);
			_strcat(exe_file_path, "\0");
			/* test if file path actually exists otherwise try the next directory*/
			if (stat(exe_file_path, &buffer) == 0)
			{
			/* return value of 0 means success implying that the exe_file_path is valid*/
				/* free up allocated memory before returning your exe_file_path */
				free(path_cp);
				return (exe_file_path);
			}
			else
			{
				/* free up the exe_file_path memory so we can check for another path*/
				free(exe_file_path);
				token = strtok(NULL, ":");
			}
		}
		/* if exe_file_path exists for command return NULL and free memory path_copy*/
		free(path_cp);
		/* before exit check if the command itself is a exe_file_path that exists*/
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
