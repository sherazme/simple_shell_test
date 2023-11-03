#include "shell.h"

void execmd(char **argv){
	char *command = NULL, *actual_command = NULL;
	pid_t child_pid = fork();

	if (child_pid == -1) {
		printf("Error forking process.\n");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0) {

		if (argv){
			/* get the command */
			command = argv[0];

			/* generate the path to this command before passing it to execve */
			actual_command = get_location(command);

			/* execute the actual command with execve */
			if (execve(actual_command, argv, NULL) == -1){
				perror("Error:");
			}
		}

	} else {
		// Parent process
		wait(NULL);
	}

}