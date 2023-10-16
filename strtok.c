#include "shell.h"
/**
 * my_strtok - function that tokenizes a string
 * @str: input string
 * @del: delimiter to be used
 * Return: tokens
 */
char *my_strtok(char *str, const char *del)
{
	int i = 0;
	char *tok;
	int x = 0;
	static char *s;

	if (str)
	{
		s = str;
	}

	if (*(s + i) != '\0')
	{
		while (*(s + i) != '\0' && (strchr(del, *(s + i)) == NULL))
		{
			i++;
		}
		if (i == 0)
		{
			s++;
			return (my_strtok(NULL, del));
		}
		tok = malloc((sizeof(char) * i) + 1);
		if (tok == NULL)
			return (NULL);
		for (x = 0; x < i; x++)
		{
			*(tok + x) = *s;
			s++;
		}
		*(tok + x) = '\0';
		if (*s != '\0')
		{
			s++;
		}
		return (tok);
		free(tok);
	}
	return (NULL);
}
