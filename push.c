#include "monty.h"

/**
 * push - adds an element to a stack
 * @head: points to head of stack
 * @count: line number
 * Return: no return
 */

void push(stack_t **head, unsigned int count)
{
	int store, j;

	if (!jaza.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(jaza.file);
		free(jaza.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	for (j = 0; jaza.arg[j] != '\0'; j++)
	{
		if (!isdigit(jaza.arg[j] && jaza.arg[j] != 'n'))
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(jaza.file);
			free(jaza.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	store = atoi(jaza.arg);
	addnode(head, store);
}
