#include "monty.h"

/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counts: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counts, FILE *file)
{
	instruction_t opst[] = {
				{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
				{"pop", func_pop},
				{"swap", func_swap},
				{"add", func_add},
				{"nop", func_nop},
				{"sub", func_sub},
				{"div", func_div},
				{"mul", func_mul},
				{"mod", func_mod},
				{"pchar", func_pchar},
				{"pstr", func_pstr},
				{"rotl", func_rotl},
				{"rotr", func_rotr},
				{"queue", func_queue},
				{"stack", func_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *optn;

	optn = strtok(content, " \n\t");
	if (optn && optn[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && optn)
	{
		if (strcmp(optn, opst[i].opcode) == 0)
		{	opst[i].func(stack, counts);
			return (0);
		}
		i++;
	}
	if (optn && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counts, optn);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
