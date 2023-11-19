#include "monty.h"
/**
 * pchar - prints character at top of stack
 * @stack: pointer to stack
 * @line_number: instruction
 * Return: nothiing
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) stack;
	if (input->top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	temp = input->top;
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%d: can/t pchar, value out of range\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
