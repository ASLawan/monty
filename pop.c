#include "monty.h"

/**
 * pop - removes item from stack
 * @stack: pointer to stack
 * @line_number: instruction
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (input->top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	remove_node();
	input->height -= 1;
}
