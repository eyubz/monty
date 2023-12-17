#include "monty.h"
/**
 * print_stack - prints all the values of the stack
 * @linkedListStack: a stack implemeted with linked list
 * @lineNumber: the line number of the opcode
 */
void print_stack(stack_t **linkedListStack, unsigned int lineNumber)
{
	stack_t *temp;
	(void)lineNumber;

	temp = *linkedListStack;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
