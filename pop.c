#include "monty.h"

/**
 * f_pop - prints the top
 * @head: stack head
 * @counts: line_number
 * Return: none
*/
void f_pop(stack_t **head, unsigned int counts)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counts);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}
