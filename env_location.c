#include "shell.h"
/**
 * loc_env - get command exec location
 * @name: name of environment
 * Return: location
 */
char *loc_env(const char *name)
{
	char *path_location;

	path_location = getenv(name);
	return (path_location);
}
