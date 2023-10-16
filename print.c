#include "shell.h"
/**
 * pr_literal - prints a string
 * @s: input string literal
 * Return: 0 on succes
 */
void pr_literal(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
/**
 * _getline - custom getline funciton
 * @lineptr: line pointer
 * @n: size of (buffer)
 * @stream: input file stream
 * Return: the input
 */
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream)
{
	int c;
	ssize_t i = 0;
	char *newptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (i >= *n - 1)
		{
			*n *= 2;
			newptr = (char *)realloc(*lineptr, *n);
			if (newptr == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			*lineptr = newptr;
		}
		(*lineptr)[i] = (char)c;
		i++;
		if (c == '\n')
			break;
	}
	if (i == 0)
	{
		free(*lineptr);
		*lineptr = NULL;
		return (-1);
	}
	(*lineptr)[i] = '\0';
	return (i);
}
