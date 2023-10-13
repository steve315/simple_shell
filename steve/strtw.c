#include "../shell.h"
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

	if (str == NULL || d == NULL)
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++)
	{
		for (int j = 0; d[j] != '\0'; j++)
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
	for (int i = 0; i <= strLength; i++)
	{
		for (int j = 0; d[j] != '\0'; j++)
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
