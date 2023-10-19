#include "monty.h"

/**
 * func_div - divides the top two elements of the stack.
 * @head: stack head
 * @counts: line_number
 * Return: none
*/
void func_div(stack_t **head, unsigned int counts)
{
	stack_t *hd;
	int len = 0, aux;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counts);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counts);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = hd->next->n / hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}
