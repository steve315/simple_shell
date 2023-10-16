#include "shell.h"
/**
 * isin_env - checks if a command is in the environment
 * @command: command to check
 * Return: 1 if false 0 if true
 */
int isin_env(const char *command)
{
	char *path = getenv("PATH");
	char *copy_path = _strdup(path);
	char *token = my_strtok(copy_path, ":");
	char path_f[1024];

	if (path == NULL)
	{
		perror("Path varible not set\n");
	}

	while (token != NULL)
	{
		strcpy(path_f, token);
		strcat(path_f, "/");
		strcat(path_f, command);

		if (access(path_f, X_OK) == 0)
		{
			free(copy_path);
			return (1);
		}
		token = my_strtok(NULL, ":");
	}
	free(copy_path);
	return (0);
}
/**
 * builtin - parses builtin functions
 * @name: input command
 * Return: on success
 */
int builtin(char **name)
{
	unsigned long int x;
	char *func_name[] = {"exit", "env", "cd"};

	int (*func[])(char **) = {&builtin_exit, &builtin_env, &builtin_cd};
	if (name[0] == NULL)
	{
		return (-1);
	}
	for (x = 0; x < sizeof(func_name) / sizeof(char *); x++)
	{
		if (strcmp(name[0], func_name[x]) == 0)
		{
			return ((*func[x])(name));
		}
	}
	return (0);
}
/**
 * _strdup - copies a string and returns a pointer to the new string
 * @str: input string
 * Return: pointer to the new string (dst)
 */
char *_strdup(char *str)
{
	int len;
	char *dest;
	int i;

	len = 0;
	if (str == NULL)
	{
		return (NULL);
	}
	while (*(str + len) != '\0')
	{
		len++;
	}
	len = len + 1;
	dest = (char *) malloc(len * sizeof(char));
	if (dest == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			dest[i] = str[i];
		}
		dest[i] = '\0';
	}
	return (dest);
	free(dest);
}
