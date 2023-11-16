#include "monty.h"
/**
 * _isdigit - checks if string represents a number
 * @str: given string
 * Return: 1 on success and 0 otherwise
 */
int _isdigit(char *str)
{
	int i = 0, flag = 1;

	if (str[0] == '-' || str[0] == '+')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			flag = 0;
			break;
		}
		i++;
	}
	return (flag);
}
/**
 * push - adds item to a stack
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (input->num_tkns <= 1 || !(_isdigit(input->tkns[1])))
	{
		free_input();
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (stack_t *)malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		not_allocated();
	}
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = atoi(input->tkns[1]);

	if (input->top != NULL)
	{
		(*stack)->next = input->top;
		input->top->prev = *stack;
	}
	input->top = *stack;
	input->height += 1;
}
