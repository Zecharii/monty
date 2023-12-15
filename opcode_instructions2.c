#include "monty.h"

/**
 * zsh_queue - sets the format of the data to a queue (FIFO)
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void zsh_queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	globalvar.lifo = 0;
}

/**
 * zsh_stack - sets the format fo the data to a stack (LIFO)
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void zsh_stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	globalvar.lifo = 1;
}

/**
 * zsh_add - adds the top two elements of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void zsh_add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	zsh_pop(doubly, cline);
}

/**
 * zsh_nop - does nothing
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void zsh_nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * zsh_sub - subtracts the top element to the second top element of the stack
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void zsh_sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
