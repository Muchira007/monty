#include "monty.h"

/**
 * pall - prints out all elements
 * @head: points to head node
 * @count: traverse through list
 * Return: no return
 */

void pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
