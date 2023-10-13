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
// ssize_t get_commad(infom_t *infom)
// {
//     static char *buffer;
// 	static size_t len;
// 	ssize_t r = 0;
// 	char **bufer = &(infom->argc), *p;

// 	r = copy_buffer(infom, &buffer, &len);
//     return (r);
// }
// ssize_t input_buf(infom_t *infom, char **buffer, size_t *len)
// {
//     size_t lenn; 
//     ssize_t r;

//     if (!len)
//     {
//         r = getline(buffer, &lenn, stdin);
//     }
//     return (r);
// }
char **strtow(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		// if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		// while (is_delim(str[i], d))
			i++;
		k = 0;
		// while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
/**
 * _getline - custom getline funciton
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
				return (-1);
			*lineptr = newptr;
		}
		(*lineptr)[i] = (char)c;
		i++;
		if (c == '\n')
			break;
	}
	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}
