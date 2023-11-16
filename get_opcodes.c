#include "monty.h"
/**
 * get_opcodes - tokenizes input
 * Return: nothing
 */
void get_opcodes(void)
{
	int i = 0, len;
	char *tkn = NULL, *line_cpy = NULL, *delim = " \n";

	len = strlen(input->line);
	line_cpy = malloc(sizeof(char) * (len + 1));
	strcpy(line_cpy, input->line);
	input->num_tkns = 0;
	tkn = strtok(line_cpy, delim);
	while (tkn)
	{
		input->num_tkns += 1;
		tkn = strtok(NULL, delim);
	}
	/*printf("\nNumber of tokens: %d\n", input->num_tkns);*/
	input->tkns = malloc(sizeof(char *) * (input->num_tkns + 1));
	/*strcpy(line_cpy, input->line);*/
	tkn = strtok(input->line, delim);

	while (tkn)
	{
		input->tkns[i] = malloc(sizeof(char) * (strlen(tkn) + 1));
		if (input->tkns[i] == NULL)
		{
			not_allocated();
		}
		strcpy(input->tkns[i], tkn);
		tkn = strtok(NULL, delim);
		i++;
	}
	input->tkns[i] = NULL;
	free(line_cpy);
}
