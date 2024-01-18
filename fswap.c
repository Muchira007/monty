#include "monty.h"

/**
 * swap - exchanges two elements in a stack
 * @head: ...
 * @count: ...
 * Return: no return
 */
void swap(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int len = 0, aux;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", count);
		fclose(jaza.file);
		free(jaza.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}
/**
 * nop - does nothing
 * @head: .....
 * @count: ...
 * Return: ...
 */
void nop(stack_t **head, unsigned int count)
{
	(void) head;
	(void) count;
}
