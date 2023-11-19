#include "monty.h"
/**
 * pstr - prints string
 * @stack: poiniter to stack
 * @line_number: instruction
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)stack;
	(void)line_number;

	temp = input->top;
	while (temp != NULL)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
