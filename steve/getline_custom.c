#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INITIAL_BUFFER_SIZE 128

ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1; // Invalid arguments
    }

    // Static buffer and buffer size
    static char buffer[INITIAL_BUFFER_SIZE];
    static size_t buffer_size = INITIAL_BUFFER_SIZE;

    if (*lineptr == NULL || *n == 0) {
        *n = INITIAL_BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1; // Memory allocation failed
        }
    }

    ssize_t i = 0; // Current position in the line
    char c;

    while (1) {
        if (i >= *n - 1) {
            // Resize the buffer if it's too small
            *n *= 2; // You can use a different resizing strategy
            char *newptr = (char *)realloc(*lineptr, *n);
            if (newptr == NULL) {
                return -1; // Memory allocation failed
            }
            *lineptr = newptr;
        }

        if (buffer_size == 0) {
            // Read more data from the file
            buffer_size = fread(buffer, 1, INITIAL_BUFFER_SIZE, stream);
            if (buffer_size == 0) {
                if (i == 0) {
                    return -1; // No data read
                } else {
                    break; // End of file
                }
            }
        }

        c = buffer[--buffer_size];
        (*lineptr)[i] = c;
        i++;

        if (c == '\n') {
            break; // End of line
        }
    }

    (*lineptr)[i] = '\0'; // Null-terminate the line

    return i;
}

int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *file = fopen("sample.txt", "r");

    if (file == NULL) {
        perror("File open error");
        return 1;
    }

    while ((read = custom_getline(&line, &len, file)) != -1) {
        printf("Line: %s", line);
    }

    free(line);
    fclose(file);

    return 0;
}
