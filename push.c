#include "monty.h"

/**
 * func_push - add node to the stack
 * @head: stack head
 * @counts: line_number
 * Return: none
*/
void func_push(stack_t **head, unsigned int counts)
{
	int e, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counts);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counts);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	e = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, e);
	else
		addqueue(head, e);
}
