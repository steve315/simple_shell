#include "shell.h"
/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	infom_t infom[] = {INITALIZE_INFOM};
	int file_des = 2;
	int stat = -1;

	if (argc == 2)
	{
		file_des = open(argv[1], O_RDONLY);
		if (file_des == -1)
		{
			return (EXIT_FAILURE);
		}
		infom->file_ds = file_des;
	}

	if (isatty(STDIN_FILENO) == 1)
	{
		do {
			dis_prompt();
			exec_command(infom, argv);
		} while (stat == -1);
	}
	else
	{
		do {
			exec_command(infom, argv);
		} while (stat == -1);
	}
	wait(NULL);
	return (EXIT_SUCCESS);
}
