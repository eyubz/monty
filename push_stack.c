#include "monty.h"
/*
 * push_stack - add node to the top of the stack
 * @linkedListStack: doubly linked list
 * @lineNumber: lineNumber
 */
void push_stack(stack_t **linkedListStack, unsigned int lineNumber)
{
	int val, i = 0, flag = 0;

	if (monty.value)
	{
		if (monty.value[0] == '-')
			i += 1;
		for (; monty.value[i] != '\0'; i++)
		{
			if (monty.value[i] > 57 || monty.value[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
			fclose(monty.file);
			free(monty.content);
			freeStack(*linkedListStack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
		fclose(monty.file);
		free(monty.content);
		freeStack(*linkedListStack);
		exit(EXIT_FAILURE);
	}
	val  = atoi(monty.value);
	pushNode(linkedListStack, val);
}

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void pushNode(stack_t **linkedListStack, int val)
{
	stack_t *node, *temp;

	temp = *linkedListStack;
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = node;
	node->n = val;
	node->next = *linkedListStack;
	node->prev = NULL;
	*linkedListStack = node;
}
