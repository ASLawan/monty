#include "monty.h"
/**
 * swap - swaps two nodes
 * @stack: pointer to stack
 * @line_number: instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1;
	stack_t *temp_2;

	(void) stack;

	if (input->height < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	temp_1 = input->top;
	temp_2 = temp_1->next;
	temp_1->next = temp_2->next;
	if (temp_1->next)
	{
		temp_1->next->prev = temp_1;
	}
	temp_2->next = temp_1;
	temp_1->prev = temp_2;
	temp_2->prev = NULL;
	input->top = temp_2;
}
