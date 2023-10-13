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

#define BUFF_SIZE 1024;

extern char **environ;

typedef struct list
{
	int num;
	char *str;
	struct list *next;
} list_t;

typedef struct infom
{
	char *file_name;
	char *arrg;
	char **argv;
	char *path;
	int argc;
	unsigned int count;
	list_t *env;
	list_t *alias;
	char **environ;
	int ch_env;
	int ex_status;
    int error_number;
    int file_ds;
} infom_t;

#define INIT_INFOM {NULL, NULL, NULL, NULL, 0, 0,NULL, NULL, NULL, 0, 0, 0, 0}

void commnd(char *command, size_t size);
void exec_command(infom_t *infom, char **argv);

char *loc_env(const char *name);
int isin_env(const char *command);

/*builtin functions*/
int builtin(char **name);
int builtin_env(char **args);
int builtin_cd(char **args);
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

#endif
