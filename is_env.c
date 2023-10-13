#include "shell.h"
/**
 * isin_env - checks if a command is in the environment
 * @command: command to check
 * Return: 1 if true 0 if false
 */
int isin_env(const char *command)
{
    char *path = getenv("PATH");
	char *dup_path = _strdup(path);
	char *token = strtok(dup_path, ":");
	char path_f[1024];

	while (token != NULL)
	{
		strcpy(path_f, token);
		strcat(path_f, "/");
		strcat(path_f, command);

		if (access(path_f, X_OK) == 0)
		{
			free(dup_path);
			return (1);
		}
		token = strtok(NULL, ":");
	}
	free(dup_path);
	return (0);
}
/**
 * built_exit - checks if exit command is passed
 * @name: input command
 * Return: on success
*/
int builtin(char **name)
{
    if (_strcmp(name[0], "exit") == 0)
    {
        exit(0);
    }
    else
    {
        if (_strcmp(name[0], "cd") == 0)
        {
            if (name[1] == NULL)
                chdir(getenv("HOME"));
            else
                chdir(name[1]);
        }
    }
    return (0);
}
int exit_s(infom_t *infom)
{
	int check;
	if(infom->argv[1])
	{
		check = atoi(infom->argv[1]);
		if(check == -1)
		{
			infom->ex_status = 2;
			pr_literal(infom->argv[1]);
			_putchar('\n');
			return (1);
		}
		infom->error_number = atoi(infom->argv[1]);
		return (-2);
	}
	infom->error_number = -1;
	return (-2);
}
/**
 * _strdup - copies a string and returns a pointer to the new string
 * @str: input string
 * Return: pointer to the new string (dst)
 */
char *_strdup(char *str)
{
	int len;
	char *dst;
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
	dst = (char *) malloc(len * sizeof(char));
	if (dst == NULL)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			dst[i] = str[i];
		}
		dst[i] = '\0';
	}
	return (dst);
	free(dst);
}
int builtin_env(char **args)
{
	int i;
    // Check if there are any arguments (not used in this function).
    if (args[1] != NULL) {
        fprintf(stderr, "builtin_env: Too many arguments\n");
        return 1; // Return an error code.
    }

    // Loop through the environment and print each environment variable.
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0; // Return success.
}
int builtin_cd(char **args) {
    if (args[1] == NULL) {
        // If no directory is provided, change to the user's home directory.
        const char *home_dir = getenv("HOME");
        if (home_dir == NULL) {
            fprintf(stderr, "own_cd: HOME environment variable not set\n");
            return 1; // Return an error code.
        }
        if (chdir(home_dir) != 0) {
            perror("own_cd");
            return 1; // Return an error code.
        }
    } else {
        // Change to the directory provided in args[1].
        if (chdir(args[1]) != 0) {
            perror("own_cd");
            return 1; // Return an error code.
        }
    }

    return 0; // Return success.
}
