#include "shell.h"
/**
 * exec_command - executes command
 * Return: 0 on success
 */
void exec_command(void)
{
	char **arguments;
	char *line = NULL;

	line = get_input(); /*reads input*/
	arguments = to_tokens(line);/*splits line to tokens*/
	free(line);
	builtin(arguments);/*checks for builtin commands*/

	fork_command(arguments);
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
 * @line: input stream
 * Return: tokens
 */
char **to_tokens(char *line)
{
	int buffer_size = 128;
	char *token;
	char **tokens = malloc(buffer_size * sizeof(char *));
	const char *delim = " ";
	int i = 0;

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
 * @argum: inpur arguments
 * Return: 1 on success
 */
int fork_command(char **argum)
{
	int stat = 0;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execvp(argum[0], argum);
		perror("Error executing command");
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
