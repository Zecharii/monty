#include "monty.h"

/**
 * free_globalvar - frees the global variables
 *
 * Return: no return
 */
void free_globalvar(void)
{
	free_dlistint(globalvar.head);
	free(globalvar.buffer);
	fclose(globalvar.fd);
}

/**
 * start_globalvar - initializes the global variables
 * @fd: file descriptor
 * Return: no return
 */
void start_globalvar(FILE *fd)
{
	globalvar.lifo = 1;
	globalvar.cont = 1;
	globalvar.arg = NULL;
	globalvar.head = NULL;
	globalvar.fd = fd;
	globalvar.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_globalvar(fd);
	nlines = getline(&globalvar.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = zsh_strtoky(globalvar.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", globalvar.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_globalvar();
				exit(EXIT_FAILURE);
			}
			globalvar.arg = zsh_strtoky(NULL, " \t\n");
			f(&globalvar.head, globalvar.cont);
		}
		nlines = getline(&globalvar.buffer, &size, fd);
		globalvar.cont++;
	}

	free_globalvar();

	return (0);
}
