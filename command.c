#include "shell.h"
/**
 * commnd - reads command from command prompt
 * @command: command
 * @size: buffer size
 * Return: 0 on success
 */
void commnd(char *command, size_t size)
{
	ssize_t chars = getline(&command, &size, stdin);

	if (chars == -1)
	{
		if (feof(stdin))
		{
			pr_literal("Exiting Shell CTRL D\n");
			exit(EXIT_FAILURE);
		} else
		{
			pr_literal("Error");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
