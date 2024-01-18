#include "monty.h"
/**
* execute - executes the opcode
* @head: head linked list - stack
* @count: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **head, unsigned int count, FILE *file)
{
	instruction_t opst[] = {
				{"push", push},
				{"pall", pall},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	jaza.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	return (1);
}
