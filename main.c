#include "monty.h"
void not_allocated(void);
inputs *input = NULL;
/**
 * not_allocated - throws error on malloc failure
 * Return: nothing
 */
void not_allocated(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_input();
	exit(EXIT_FAILURE);
}
/**
 * check_input - checks number of cmdline inputs
 * @ac: number of inputs
 * Return: nothing
 */
void check_input(int ac)
{
	if (ac == 2)
	{
		return;
	}
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * free_opcodes - free memory
 * Return: nothing
 */
void free_opcodes(void)
{
	int i = 0;

	if (input->tkns == NULL)
	{
		return;
	}
	while (input->tkns[i])
	{
		free(input->tkns[i]);
		i++;
	}
	free(input->tkns);
	input->tkns = NULL;
}
/**
 * close_file - closes files
 * Return: nothing
 */
void close_file(void)
{
	if (input->source == NULL)
	{
		return;
	}
	fclose(input->source);
	input->source = NULL;
}
/**
 * main - program entry point
 * @ac: number of arguments
 * @av: argument array
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	size_t num = 0;

	check_input(ac);
	set_input_defaults();
	read_file(av[1]);

	while (getline(&input->line, &num, input->source) != -1)
	{
		input->line_num += 1;
		get_opcodes();
		get_opcodes_func();
		execute_opcodes_func();
		free_opcodes();

	}
	close_file();
	free_input();
	return (0);
}
