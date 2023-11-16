#include "monty.h"
/**
 * free_top - frees memory
 * Return: nothing
 */
void free_top(void)
{
	if (input->top)
	{
		free_stack(input->top);
	}
	input->top = NULL;
}
/**
 * free_stack - frees memory
 * @top: pointer to first node
 * Return: nothing
 */
void free_stack(stack_t *top)
{
	if (top == NULL)
	{
		return;
	}
	if (top->next != NULL)
	{
		free_stack(top->next);
	}
	free(top);
}
/**
 * free_input - frees allocated memory
 * Return: nothing
 */

void free_input(void)
{
	if (input == NULL)
	{
		return;
	}
	if (input->instruction)
	{
		free(input->instruction);
		input->instruction = NULL;
	}
	free_top();
	if (input->line)
	{
		free(input->line);
		input->line = NULL;
	}
	free(input);
}
