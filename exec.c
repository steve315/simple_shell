#include "shell.h"
/**
 * exec_command - executes command
 * @command: command to be executed
 * Return: 0 on success
 */
void exec_command(infom_t __attribute__((unused))*infom, char __attribute__((unused))**argv)
{
	pid_t child_pid;
	int count = 0;
	char *token, *delimiter = " ";
	char *arguments[1024];
	// int i, ac = infom->argc;
	char *line = NULL;
	ssize_t len = 0;
	ssize_t chars;

	chars = _getline(&line, &len, stdin); /*inmp fxn to read input*/
	if (chars == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_FAILURE);
		} else
		{
			exit(EXIT_FAILURE);
		}
	}
	line[strcspn(line, "\n")] = '\0';


	token = strtok(line, delimiter);
	while (token != NULL)
	{
		arguments[count++] = token;
		token = strtok(NULL, delimiter);
	}
	arguments[count] = NULL;
	builtin(arguments);
	
	if (isin_env(arguments[0]) == 0)
	{
		pr_literal("command not found\n");
	}
	else
	{
	child_pid = fork();
	if (child_pid < 0)
	{
		pr_literal("Error");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (!execvp(arguments[0], arguments))
		{
			pr_literal("Error Executing command\n");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	}
}
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 on sucess
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/*
int fork_command(char *arguments)
{
	pid_t c_pid;
	c_pid = fork();
	if (c_pid < 0)
	{
		pr_literal("Error");
		exit(1);
	}
	else if (c_pid == 0)
	{
		if (!execvp(arguments[0], arguments))
		{
			pr_literal("Error Executing command\n");
			exit(1);
		}
	}
	return (0);
}
*/
void setinfom(infom_t *infom, char **argv)
{
	int x;

	x = 0;
	infom->file_name = argv[0];

	if (infom->arrg)
	{
		infom->argv = strtow(infom->arrg, " \t");
		if (!infom->argv)
		{
			infom->argv = malloc(sizeof(char *) * 2);
			if (infom->argv)
			{
				infom->argv[0] = _strdup(infom->arrg);
				infom->argv[1] = (NULL);
			}
		}
		for (x = 0; infom->argv && infom->argv[x]; x++)
			;
		infom->argc = x;
	}
}
