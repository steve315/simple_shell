#include <stdio.h>
#include <stdlib.h>

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

// int main() {
// 	char *line = NULL;
// 	ssize_t len = 0;
// 	ssize_t read;

// 	FILE *file = fopen("sample.txt", "r");

// 	if (file == NULL) {
// 		perror("File open error");
// 		return 1;
// 	}

// 	while ((read = _getline(&line, &len, file)) != -1) {
// 		printf("Line: %s", line);
// 	}

// 	free(line);
// 	fclose(file);

// 	return 0;
// }
