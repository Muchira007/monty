#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
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
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct jaza_s - variables -args, file, line content
 * @arg: value
 * @file: points to a monty file
 * @content: content present in a line
 * Description: carries values through the program
 */
typedef struct jaza_s
{
	char *arg;
	FILE *file;
	char *content;
} jaza_t;
extern jaza_t jaza;

void push(stack_t **head, unsigned int line_nu);
void free_stack(stack_t *head);
void addnode(stack_t **head, int store);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

#endif
