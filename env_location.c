#include "shell.h"
/**
 * loc_env - get command exec location
 * @infom: variable struct
 * Return: location
 */
char *loc_env(infom_t *infom)
{
	char *env_list;

	env_list = getenv(infom->path);

	return (env_list);
}
