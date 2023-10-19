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

/**
 * struct elist - linked list for env
 * @n: index field
 * @str: string
 * @next: pointer to next
 */
typedef struct elist
{
	int n;
	char *str;
	struct elist *next;
} elist_t;

extern char **environ;
/**
 * struct infom - struct for initializing function variables
 * @argc: argument count
 * @argum: arguments vector
 * @argv: main prog argument vector
 * @path: path
 * @file_name: executable command name
 * @commnd: command string
 * @environ: environment variable
 * @file_ds: file description
 * @envi: environment
*/
typedef struct infom
{
	int argc;
	char **argum;
	char **argv;
	char *path;
	char *file_name;
	char **environ;
	char *commnd;
	int file_ds;
	elist_t *envi;
} infom_t;

#define INITALIZE_INFOM {0, NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL}


void commnd(char *command, size_t size);
void exec_command(infom_t *infom, char **argv);

char *loc_env(infom_t *infom);
int isin_env(infom_t *infom);

/*builtin functions*/
int builtin(infom_t *infom);
int builtin_env(char **args);
int builtin_exit(char **name);
int builtin_cd(char **args);
int builtin_env(char **args);
/*******/

void fork_cmd(const char *args);

/*display and manipulation*/
void dis_prompt(void);
int _putchar(char c);
void pr_literal(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char **strtow(char *str, char *d);
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream);
/*************/

char **to_tokens(infom_t *infom);
int fork_command(infom_t *infom);
char *get_input(infom_t *infom);
char *my_strtok(char *str, const char *del);
char *_strchr(const char *s, int c);

/**environment*/
int env_list(infom_t *infom);
elist_t *add_end(elist_t **head, const char *str);
void fill_infom(infom_t *infom, char **argv);
void reset_infom(infom_t *infom);
char *_getenv(infom_t *infom, const char *env_name);
size_t print_list(const elist_t *elist);

#endif
