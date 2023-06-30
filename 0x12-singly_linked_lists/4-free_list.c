#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees list_t
 *
 * @head: list to free
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *next;

	if (!head)
		return;
	next = head->next;

	while (head != NULL)
	{
		if (head->str != NULL)
			free(head->str);
		free(head);
		head = next;
		if (head)
			next = head->next;
	}
}
