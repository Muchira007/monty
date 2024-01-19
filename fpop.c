#include "monty.h"

/**
 * pop - removes top element on the stack
 * @head: points to the head node
 * @count: traverse
 * Return: no return
 */
void pop(stack_t **head, unsigned int count)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(jaza.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);

}
