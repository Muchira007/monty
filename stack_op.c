#include "monty.h"

/**
 * free_stack -  frees a doubly linked list
 * @head: points to the head node
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while
	{
		temp = head->next;
		free(head);
		head = temp
	}
}
/**
 * addnode - adds a node to the head as a stack or doubly linked list
 * @head: points to the head node
 * @store: new value
 * Return: no return
 */
void addnode(stack_t **head, int store)
{
	stack_t *newnode, *temp;

	temp = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	if (temp)
	{
		temp->prev = newnode;
		newnode->store = store;
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		newnode->store = store;
		newnode->prev = NULL;
		newnode->next = NULL;
		*head = newnode;
	}
}
