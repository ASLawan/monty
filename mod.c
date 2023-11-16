#include "monty.h"
/**
 * mod - ddiv second last item by the last
 * but one item
 * @stack: pointer to stack
 * @line_number: instruction
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_1;
	stack_t	*temp_2;

	(void) stack;
	if (input->height < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	temp_1 = input->top;
	temp_2 = temp_1->next;

	if (temp_1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		close_file();
		free_opcodes();
		free_input();
		exit(EXIT_FAILURE);
	}
	temp_2->n = temp_2->n % temp_1->n;
	remove_node();
	input->height -= 1;
}
