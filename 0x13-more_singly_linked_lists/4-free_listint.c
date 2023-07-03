#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees memory of listint_t list
 *
 * @head: head of the linked list to free
 *
 * Return: nothing
 */

void free_listint(listint_t *head)
{
	listint_t *next_node;

	if (!head)
		return;

	for (next_node = head->next; head != NULL; head = next_node)
	{
		next_node = head->next;
		free(head);
	}
}
