#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

jaza_t jaza = {NULL, NULL, NULL, 0};

/**
 * main - interprates monty code according to format
 * @argc: ......
 * @argv: ......
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t g_line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: cant open with format \n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	jaza.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (g_line > 0)
	{
		content = NULL;
		g_line = getline(&content, &size, file);
		jaza.content = content;
		count++;
		if (g_line > 0)
		{
			execute(content, &stack, count, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
