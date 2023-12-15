#include "monty.h"

/**
 * zsh_push - pushes an element to the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void zsh_push(stack_t **doubly, unsigned int cline)
{
	int n, j;

	if (!globalvar.arg)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "usage: push integer\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	for (j = 0; globalvar.arg[j] != '\0'; j++)
	{
		if (!isdigit(globalvar.arg[j]) && globalvar.arg[j] != '-')
		{
			dprintf(2, "L%u: ", cline);
			dprintf(2, "usage: push integer\n");
			free_globalvar();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(globalvar.arg);

	if (globalvar.lifo == 1)
		add_dnodeint(doubly, n);
	else
		add_dnodeint_end(doubly, n);
}

/**
 * zsh_pall - prints all values on the stack
 * @doubly: head of the linked list
 * @cline: line numbers
 * Return: no return
 */
void zsh_pall(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;
	(void)cline;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * zsh_pint - prints the value at the top of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void zsh_pint(stack_t **doubly, unsigned int cline)
{
	(void)cline;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", cline);
		dprintf(2, "can't pint, stack empty\n");
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * zsh_pop - removes the top element of the stack
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void zsh_pop(stack_t **doubly, unsigned int cline)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", cline);
		free_globalvar();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * zsh_swap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void zsh_swap(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", cline);
		free_globalvar();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
