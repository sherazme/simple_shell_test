#include "shell.h"

char *get_location(char *command){
    char *path, *path_copy, *path_token, *file_path;
    int command_length, directory_length;
    struct stat buffer;

    path = getenv("PATH");

	printf("begin loc");
    if (path){
        /* Duplicate the path string -> remember to free up memory for this because strdup allocates memory that needs to be freed*/ 
        path_copy = strdup(path);
		printf("path");
        /* Get length of the command that was passed */
        command_length = strlen(command);

        /* Let's break down the path variable and get all the directories available*/
        path_token = strtok(path_copy, ":");

        while(path_token != NULL){
            printf("path token");
			/* Get the length of the directory*/
            directory_length = strlen(path_token);
            /* allocate memory for storing the command name together with the directory name */
            file_path = malloc(command_length + directory_length + 2); /* NB: we added 2 for the slash and null character we will introduce in the full command */
            /* to build the path for the command, let's copy the directory path and concatenate the command to it */
            strcpy(file_path, path_token);
            strcat(file_path, "/");
            strcat(file_path, command);
            strcat(file_path, "\0");

            /* let's test if this file path actually exists and return it if it does, otherwise try the next directory */
            if (stat(file_path, &buffer) == 0){
                /* return value of 0 means success implying that the file_path is valid*/
				printf("file path");

                /* free up allocated memory before returning your file_path */
                free(path_copy);

                return (file_path);
            }
            else{
                /* free up the file_path memory so we can check for another path*/
                free(file_path);
                path_token = strtok(NULL, ":");
				printf("free path");

            }

        }

        /* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */ 
        free(path_copy);

        /* before we exit without luck, let's see if the command itself is a file_path that exists */
        if (stat(command, &buffer) == 0)
        {
			printf("command");
            return (command);
        }


        return (NULL);

    }


    return (NULL);
}