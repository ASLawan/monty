#include "monty.h"
int _isdigit(char *str);
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
 * push - adds data to data structure(stack/queue)
 * @stack: pointer to the stack
 * @line_number: instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

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

	if (input->top == NULL)
	{
		input->top = *stack;
	}
	else
	{
		if (input->data)
		{
			(*stack)->next = input->top;
			input->top->prev = *stack;
			input->top = *stack;
		}
		else
		{
			temp = input->top;
			while (temp->next)
			{
				temp = temp->next;
			}
			temp->next = *stack;
			(*stack)->prev = temp;
		}
	}

	input->height += 1;
}
