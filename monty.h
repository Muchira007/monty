#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

/**
 * struct global_s - variables -args, file, line content
 * @arg: value
 * @file: points to a monty file
 * @content: content present in a line
 * Description: carries values through the program
 */
typedef struct global_s
{
	FILE *file;
	char content[MAX_SIZE];
	char *arg;
} global_t;
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

extern global_t jaza;

int main(int argc, char *argv[]);
void push(stack_t **head, unsigned int count);
void free_stack(stack_t *head);
void addnode(stack_t **head, int store);
int execute(char *content, stack_t **head, unsigned int count, FILE *file);
void pall(stack_t **head, unsigned int count);
void pop(stack_t **head, unsigned int count);
void swap(stack_t **head, unsigned int coun);
void add(stack_t **head, unsigned int count);
void nop(stack_t **head, unsigned int count);

#endif
