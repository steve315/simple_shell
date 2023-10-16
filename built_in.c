#include "shell.h"
/**
 * builtin_env - prints current environment
 * @args: input args
 * Return: 0 on success
*/
int builtin_env(char **args)
{
	int i;

	if (args[1] != NULL)
	{
		fprintf(stderr, "builtin_env: Too many arguments\n");
		return (1);
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (0);
}
/**
 * builtin_cd - changes directory
 * @args: input args
 * Return: 0 on success
*/
int builtin_cd(char **args)
{
	const char *home_dir;

	if (args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			fprintf(stderr, "HOME env not set\n");
			return (1);
		}
		if (chdir(home_dir) != 0)
		{
			perror("own_cd");
			return (1);
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error");
			return (1);
		}
	}
	return (0);
}
/**
 * builtin_exit - exits the program
 * @args: input args
 * Return: 0 on success
*/
int builtin_exit(char **args)
{
	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	return (0);
}
