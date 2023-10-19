#include "shell.h"
/**
 * get_input - reads input from stdin
 * @infom: struct
 * Return: input chars
 */
char *get_input(infom_t *infom)
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
	infom->commnd = line;
	return (line);
}
/**
 * _strchr - locates occurance of a char
 * @s: input string
 * @c: character
 * Return: pointer to located char
*/
char *_strchr(const char *s, int c)
{

	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
/**
 * reset_infom - resets struct to default
 * @infom: struct
*/
void reset_infom(infom_t *infom)
{
	infom->argc = 0;
	infom->argv = NULL;
	infom->path = NULL;
	infom->argum = NULL;
}
/**
 * strtow - converts string to words using delimiter
 * @str: input string
 * @d: delimiter
 * Return: words
*/
char **strtow(char *str, char *d)
{
	int wordIndex = 0, wordStart = 0, numWords = 1, wordLength = 0;
	int strLength = strlen(str);
	char **words = (char **)malloc(sizeof(char *) * numWords);
	int i, j;

	if (str == NULL || d == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; d[j] != '\0'; j++)
		{
			if (str[i] == d[j])
			{
				numWords++;
				break;
			}
		}
	}
	if (words == NULL)
		return (NULL);
	for (i = 0; i <= strLength; i++)
	{
		for (j = 0; d[j] != '\0'; j++)
		{
			if (str[i] == d[j] || str[i] == '\0')
			{
				wordLength = i - wordStart;
				words[wordIndex] = (char *)malloc(wordLength + 1);
				if (words[wordIndex] == NULL)
					return (NULL);
				strncpy(words[wordIndex], str + wordStart, wordLength);
				words[wordIndex][wordLength] = '\0';
				wordStart = i + 1;
				wordIndex++;
				break;
			}
		}
	}
	return (words);
}
