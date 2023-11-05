#include "shell.h"
/**
 * _cd - to change directory
 * @name: the name of directory
 * Return: 0 in success
 */
int _cd(char *name)
{
	char pr_dir[BUF];
	char cwd[BUF];

	if (_strcmp(name, "-") == 0)
	{/* Handle 'cd -'*/
		char *temp = pr_dir;

		pr_dir[0] = '\0';/*Clear the previous directory*/
		if (temp[0] != '\0')
		{
			_print(temp); /* Print the directory being switched to*/
			_print("\n");
			chdir(temp);
			if (chdir(temp) != 0)
			{
				_print("cd: Cannot change directory to\n");
				_print(temp);
				_print("\n");
				return (-1);
			}
			getcwd(cwd, sizeof(cwd));
		}
	}
	else
	{
		chdir(name);
		if (chdir(name) != 0)/*change directory*/
		{
			_print("cd: Cannot change directory to\n");
			_print(name);
			return (-1);
		}
		getcwd(cwd, sizeof(cwd));
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		_print("cd: Error getting current working directory\n");
		return (-1);
	}

	_strcpy(pr_dir, cwd);
	update_pwd(cwd);
	return (0);
}
/**
 * update_pwd - to update current working directory
 * @new: the new pwd
 * Return: void
 */
void update_pwd(char *pwd_new)
{
	if (pwd_new == NULL)
	{
		_print("cd: Error updating PWD\n");
		return;
	}

	if (_setenv("PWD", pwd_new, 1) != 0)
	{
		_print("cd: Error updating PWD\n");
	}
}
