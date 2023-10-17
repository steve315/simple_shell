#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define BUFF_SIZE 1024

extern char **environ;
/**
 * struct infom - struct for initializing function variables
 * @argc: argument count
 * @argv: argument vector
 * @path: path
 * @environ: environment variable
 * @file_ds: file description
*/
typedef struct infom
{
	int argc;
	char **argv;
	char *path;
	char **environ;
	int file_ds;
} infom_t;

#define INITALIZE_INFOM {0, NULL, NULL, NULL, 0}

void commnd(char *command, size_t size);
void exec_command(void);

char *loc_env(infom_t *infom);
int isin_env(const char *command);

/*builtin functions*/
int builtin(char **name);
int builtin_env(char **args);
int builtin_exit(char **args);
int builtin_cd(char **args);
int builtin_env(char **args);
/*******/

void fork_cmd(const char *args);

/*display and manipulation*/
void dis_prompt(void);
int _putchar(char c);
void pr_literal(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char **strtow(char *str, char *d);
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream);
/*************/

char **to_tokens(char *line);
int fork_command(char **argum);
char *get_input(void);
char *my_strtok(char *str, const char *del);
char *_strchr(const char *s, int c);

#endif
