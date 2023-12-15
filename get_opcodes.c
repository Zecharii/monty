#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", zsh_push},
		{"pall", zsh_pall},
		{"pint", zsh_pint},
		{"pop", zsh_pop},
		{"swap", zsh_swap},
		{"queue", zsh_queue},
		{"stack", zsh_stack},
		{"add", zsh_add},
		{"nop", zsh_nop},
		{"sub", zsh_sub},
		{"mul", zsh_mul},
		{"div", zsh_div},
		{"mod", zsh_mod},
		{"pchar", zsh_pchar},
		{"pstr", zsh_pstr},
		{"rotl", zsh_rotl},
		{"rotr", zsh_rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (zsh_strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
