#include "monty.h"
#include <stdlib.h>
/**
 * main- monty code interpretor
 * @argc: number of arguments
 * @argv: pointer to the arguments
 * Return: Always Success(0)
 */
int main(int argc, char **argv)
{
	char *fileContent;
	FILE *montyFile;
	size_t sizeRead = 0, readFile = 1;
	stack_t *linkedListStack = NULL;
	unsigned int lineNumber = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	montyFile = fopen(argv[1], "r");
	monty.file = montyFile;
	if (!montyFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readFile > 0)
	{
		fileContent = NULL;
		readFile = getline(&fileContent, &sizeRead, montyFile);
		monty.content = fileContent;
		lineNumber++;
		if (readFile > 0)
		{
			process_opcode(fileContent, &linkedListStack, lineNumber, montyFile);
		}
		free(fileContent);
	}
	freeStack(linkedListStack);
	fclose(montyFile);
	return (0);
}
