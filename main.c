#include "shell.h"
/**
 * main - program entry point
 * Return: 9 on success
 */
int main(int argc, char **argv)
{

	infom_t infom[] = {INIT_INFOM};

	// char command[100];

	int file_des = 2;

    // char *envi = loc_env("PATH");
    // pr_literal(envi);

	if (argc == 2)
	{
		file_des = open(argv[1], O_RDONLY);
		if (file_des == -1)
		{
			// exit(99);
			return (EXIT_FAILURE);
		}
		infom->file_ds = file_des;
	}
	if (isatty(0))
	{
		dis_prompt();
	}
    //     if (isatty(0))
    //     {
    //         dis_prompt();
    //     }
		// commnd(argv, sizeof(command));
		// exec_command(infom, argv);
	exec_command(infom, argv);
	// wait(NULL);
	return (0);
}
/*__attribute__((unused))*/
