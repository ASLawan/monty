#include "monty.h"
/**
 * set_input_defaults - initialize input variables
 * Return: nothing
 */
void set_input_defaults(void)
{
	input = (inputs *)malloc(sizeof(inputs));
	if (input == NULL)
	{
		not_allocated();
	}
	input->instruction = (instruction_t *)malloc(sizeof(instruction_t));
	if (input->instruction == NULL)
	{
		not_allocated();
	}

	input->source = NULL;
	input->line = NULL;
	input->num_tkns = 0;
	input->lnum = 0;
	input->height = 0;
	input->top = NULL;
	input->data = 1;
}


