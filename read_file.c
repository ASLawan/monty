#include "monty.h"
/**
 * file_not_read - throws error on file read failure
 * @file: file to read from
 * Return: nothing
 */

void file_not_read(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	free_input();
	exit(EXIT_FAILURE);
}

/**
 * read_file - reads from file
 * @file: file to read from
 * Return: nothing;
 */
void read_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		file_not_read(file);
	}
	input->source = fopen(file, "r");
	if (input->source == NULL)
	{
		close(fd);
		file_not_read(file);
	}
}
