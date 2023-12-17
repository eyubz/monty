#include "monty.h"
/*
 * process_opcode - executes the opcode
 * @fileContent: a one line content from the file
 * @linkedListStack: a doubly linked list stack
 * @lineNumber: line number
 * @file: monty file
 */
int process_opcode(char *fileContent, stack_t **linkedListStack,
		   unsigned int lineNumber, FILE *file)
{
	instruction_t  instruction[] = {{"push", push_stack}, {"pall", print_stack}};
	unsigned int i = 0;
	char *data;

	data = strtok(fileContent, " \n\t");
	monty.value = strtok(NULL, " \n\t");
	while (instruction[i].opcode && data)
	{
		if (strcmp(data, instruction[i].opcode) == 0)
		{
			instruction[i].f(linkedListStack, lineNumber);
			return (0);
		}
		i++;
	}
	if (data && instruction[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, data);
		fclose(file);
		free(fileContent);
		freeStack(*linkedListStack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
