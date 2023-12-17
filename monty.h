#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct montyData - contain values , file and content
 * @value: a value
 * @file: pointer to a file
 * @content: line content
 * 
 */ 
typedef struct montyData
{
	char *value;
	FILE *file;
	char *content;
	/*int lifi*/
}montyData;
extern montyData monty;
 
void pushNode(stack_t **linkedListStack, int val);
void push_stack(stack_t **linkedListStack, unsigned int lineNumber);
void freeStack(stack_t *linkedListStack);
void print_stack(stack_t **linkedListStack, unsigned int lineNumber);
int process_opcode(char *fileContent, stack_t **linkedListStack,
                   unsigned int lineNumber, FILE *file);
#endif
