#include "monty.h"
/**
 * execute_opcodes_func - runs opcode functions
 * Return: nothing
 */

void execute_opcodes_func(void)
{
	stack_t *stack = NULL;

	if (input->num_tkns == 0)
	{
		return;
	}
	input->instruction->f(&stack, input->line_num);
}
