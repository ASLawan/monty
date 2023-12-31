#ifndef MONTY_H
#define MONTY_H

/*** HEADER FILES  ***/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>



/*** STRUCTURES  ***/

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
*
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
* struct inputs - handles inputs from files
*
* @source: the file from which input is taken
* @line: the current line's contents
* @tkns: tokens
* @top: the top element in the stack/queue
* @num_tkns: the number of tokens
* @height: height
* @lnum: the current line in the file on which the input is read
* @instruction: instruction for monty
* @data: data structure - stack or queue
* Description: Handles inputs from files
*/
typedef struct inputs
{
	FILE *source;
	char *line;
	char **tkns;
	stack_t *top;
	int num_tkns;
	int height;
	unsigned int lnum;
	instruction_t *instruction;
	int data;
} inputs;

/*** THE GLOBAL VARIABLE ***/
extern inputs *input;

/*** OTHER FUNCTION PROTOTYPES USED IN THE PROJECT ***/

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void ddiv(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void execute_opcodes_func(void);
void free_top(void);
void free_stack(stack_t *top);
void free_input(void);
void free_opcodes(void);
void get_opcodes(void);
void get_opcodes_func(void);
void set_input_defaults(void);
int _isdigit(char *str);
void read_file(char *file);
void remove_node(void);
void close_file(void);
void not_allocated(void);
void check_input(int ac);

#endif
