#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_SIZE 1024

jaza_t jaza = {NULL, NULL, 0};

/**
 * main - interprates monty code according to format
 * @argc: ......
 * @argv: ......
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char content[MAX_SIZE];
	FILE *file;
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
		content[0] = '\0';
		g_line = (ssize_t)fgets(content, MAX_SIZE, file);

		if (g_line > 0)
		{
			size_t len = strlen(content);

			if (len > 0 && content[len - 1] == '\n')
				content[len - 1] = '\0';
			jaza.content = content;
			count++;

			execute(content, &stack, count, file);
		}
	}
	free_stack(stack);
	fclose(file);
	return (0);
}
