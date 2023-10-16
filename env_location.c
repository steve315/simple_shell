#include "shell.h"
/**
 * loc_env - get command exec location
 * @name: name of environment
 * Return: location
 */
char *loc_env(const char *name)
{
	char *env_list;

	env_list = getenv(name);

	return (env_list);
}
