#include "monty.h"

/**
 * add - adds two elements in a sack
 * @head: ...
 * @count: ...
 * Return: ....
 */
void add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int len = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(jaza.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n += (*head)->n;
	pop(head, count);
}
