#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct global_s - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for Stack, Queues (LIFO, FIFO) project
 */
typedef struct global_s
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern global_t globalvar;

/* opcode_instructions1.c */
void zsh_push(stack_t **stack, unsigned int line_number);
void zsh_pall(stack_t **stack, unsigned int line_number);
void zsh_pint(stack_t **doubly, unsigned int cline);
void zsh_pop(stack_t **doubly, unsigned int cline);
void zsh_swap(stack_t **doubly, unsigned int cline);

/* opcode_instructions2.c */
void zsh_queue(stack_t **doubly, unsigned int cline);
void zsh_stack(stack_t **doubly, unsigned int cline);
void zsh_add(stack_t **doubly, unsigned int cline);
void zsh_nop(stack_t **doubly, unsigned int cline);
void zsh_sub(stack_t **doubly, unsigned int cline);

/* opcode_instructions3.c */
void zsh_div(stack_t **doubly, unsigned int cline);
void zsh_mul(stack_t **doubly, unsigned int cline);
void zsh_mod(stack_t **doubly, unsigned int cline);
void zsh_pchar(stack_t **doubly, unsigned int cline);
void zsh_pstr(stack_t **doubly, unsigned int cline);

/* opcode_instructions4.c */
void zsh_rotl(stack_t **doubly, unsigned int cline);
void zsh_rotr(stack_t **doubly, unsigned int cline);

/* get_opcodes.c */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* str_functions.c */
int zsh_sch(const char *s, char c);
char *zsh_strtoky(const char *s, const char *d);
void *zsh_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *zsh_calloc(unsigned int numb, unsigned int size);
int zsh_strcmp(const char *s1, const char *s2);

/* doubly_linked.c */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main.c */
void free_globalvar(void);
FILE *check_input(int argc, char *argv[]);
int main(int argc, char *argv[]);

#endif /* _MONTY_ */
