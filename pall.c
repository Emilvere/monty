#include "monty.h"

/**
 * f_pall - prints the stack
 * @head: stack head
 * @counts: no use
 * Return: none
*/
void f_pall(stack_t **head, unsigned int counts)
{
	stack_t *hd;
	(void)counts;

	hd = *head;
	if (hd == NULL)
		return;
	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}
