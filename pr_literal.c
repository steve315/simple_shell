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
