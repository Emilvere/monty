#include "monty.h"

/**
 * func_pstr - prints the string, followed by a new line
 * @head: stack head
 * @counts: line_number
 * Return: no return
*/
void func_pstr(stack_t **head, unsigned int counts)
{
	stack_t *hd;
	(void)counts;

	hd = *head;
	while (hd)
	{
		if (hd->n > 127 || hd->n <= 0)
		{
			break;
		}
		printf("%c", hd->n);
		hd = hd->next;
	}
	printf("\n");
}
