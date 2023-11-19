#include "monty.h"
void unknown_instruction(void);
/**
 * unknown_instruction - throws errors
 * Return: nothing
 */
void unknown_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			input->line_num, input->tkns[0]);
	close_file();
	free_input();
	free_opcodes();
	exit(EXIT_FAILURE);
}
/**
 * get_opcodes_func - select function
 * Return: nothing
 */

void get_opcodes_func(void)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", &push},
		{"pint", &pint},
		{"nop", &nop},
		{"pall", &pall},
		{"div", &ddiv},
		{"mod", &mod},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"sub", &sub},
		{"mul", &mul},
		{"pchar", &pchar},
		{"stack", &stack},
		{"queue", &queue},
		{"rotl", &rotl},
		{"rotr", &rotr},
		{"pstr", &pstr},
		{"NULL", NULL}
	};
	if (input->num_tkns == 0)
	{
		return;
	}
	if (input->tkns[0][0] == '#')
	{
		input->instruction->opcode = "nop";
		input->instruction->f = nop;
		return;
	}
	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, input->tkns[0]) == 0)
		{
			input->instruction->opcode = instructions[i].opcode;
			input->instruction->f = instructions[i].f;
			return;
		}
	}
	unknown_instruction();
}
