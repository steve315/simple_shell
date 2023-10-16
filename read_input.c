#include "shell.h"
/**
 * get_input - reads input from stdin
 * Return: input chars
 */
char *get_input(void)
{
	ssize_t chars;
	ssize_t len = 0;
	char *line = NULL;

	chars = _getline(&line, &len, stdin);
	if (chars == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	line[strcspn(line, "\n")] = '\0';
	return (line);
}