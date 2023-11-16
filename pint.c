#include "monty.h"
/**
 * pint - prints top most item on tack
 * @stack: pointer to stack
 * @line_number: instruction
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (input->top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", input->top->n);
}
