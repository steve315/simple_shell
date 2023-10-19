#include "shell.h"
/**
 * exec_command - executes command
 * @infom: struct
 * @argv: argument vector
 * Return: 0 on success
 */
void exec_command(infom_t *infom, char **argv)
{
	char *line = NULL;

	reset_infom(infom);
	get_input(infom); /*reads input*/

	fill_infom(infom, argv);

	env_list(infom);
	infom->argum = to_tokens(infom);/*splits line to tokens*/

	free(line);
	builtin(infom);/*checks for builtin commands*/
	if (isin_env(infom) == 0)
	{
		fork_command(infom);
	}
	else
	{
		perror("");
	}

	wait(NULL);
}
/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 on success
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}
	return (0);
}
/**
 * to_tokens - tokenizes the input
 * @infom: information struct
 * Return: tokens
 */
char **to_tokens(infom_t *infom)
{
	int buffer_size = 128;
	char *token;
	char **tokens = malloc(buffer_size * sizeof(char *));
	const char *delim = " ";
	int i = 0;
	char *line;

	line = infom->commnd;
	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = my_strtok(line, delim);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			exit(EXIT_FAILURE);
		}
		i++;
		token = my_strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * fork_command - executes the fork command
 * @infom: information struct
 * Return: 1 on success
 */
int fork_command(infom_t *infom)
{
	char **argum = infom->argum;
	int stat = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execve(infom->argv[0], argum, NULL);
		perror("");
		exit(1);
	}
	else if (child_pid < 0)
	{
		perror("Error opening child process");
	}
	else
	{
		do {
			waitpid(child_pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (-1);
}
/**
 * fill_infom - function that populates infom struct
 * @infom: struct
 * @argv: argument vector
 */
void fill_infom(infom_t *infom, char **argv)
{
	int n;

	infom->file_name = argv[0];

	if (infom->commnd)
	{
		infom->argv = strtow(infom->commnd, " \t");
		if (!infom->argv)
		{
			infom->argv[0] = _strdup(infom->commnd);
			infom->argv[1] = NULL;
		}
		for (n = 0; infom->argv && infom->argv[n]; n++)
			;
		infom->argc = n;
	}
}
