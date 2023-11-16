#include "monty.h"
/**
 * add - adds last two items, stores in last
 * but one item
 * @stack: pointer to stack
 * @line_number: instruction
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1;
	stack_t *temp_2;

	(void) stack;
	if (input->height < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	temp_1 = input->top;
	temp_2 = temp_1->next;
	temp_2->n = temp_1->n + temp_2->n;
	remove_node();
	input->height -= 1;
}
