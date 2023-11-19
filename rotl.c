#include "monty.h"
/**
 * rotl - rotates stack to the top
 * @stack: pointer to the stack
 * @line_number: instruction
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1;
	stack_t *temp_2;

	(void)stack;
	(void)line_number;
	if (input->height < 2)
	{
		return;
	}
	temp_1 = input->top;
	temp_2 = temp_1->next;
	input->top = temp_2;
	while (temp_2)
	{
		if (temp_2->next == NULL)
		{
			temp_2->next = temp_1;
			temp_1->next = NULL;
			temp_1->prev = temp_2;
			break;
		}

		temp_2 = temp_2->next;
	}
}
