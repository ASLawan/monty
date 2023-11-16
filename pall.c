#include "monty.h"
/**
 * pall - prints stack elements
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	(void)stack;

	if (input->top == NULL)
	{
		return;
	}

	temp = input->top;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
