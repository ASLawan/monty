#include "monty.h"
/**
 * remove_node - deletes stack item
 * Return: nothing
 */

void remove_node(void)
{
	stack_t *temp;

	temp = input->top;
	input->top = temp->next;
	free(temp);
}
