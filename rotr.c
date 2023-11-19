#include "monty.h"
/**
 * rotr - rotates stack to the bottom
 * @stack: pointer to the stack
 * @line_number: instruction
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *bottom;

	(void)stack;
	(void)line_number;

	if (input->height < 2)
	{
		return;
	}
	temp = input->top;
	while (temp)
	{
		if (temp->next == NULL)
		{
			bottom = temp;
			break;
		}
		temp = temp->next;
	}
	bottom->prev->next = NULL;
	bottom->next = input->top;
	bottom->prev = NULL;

	input->top = bottom;
}

