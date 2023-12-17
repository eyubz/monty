#include "monty.h"
/**
 * freeStack - free a doubly linked list
 * @linkedListStack: a doubly linked list
 */
void freeStack(stack_t *linkedListStack)
{
	stack_t *temp;

	temp = linkedListStack;
	while (linkedListStack)
	{
		temp = linkedListStack->next,
		free(linkedListStack);
		linkedListStack = temp;
	}
}
