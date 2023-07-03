#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees memory held by listint_t list
 *
 * @head: head of the linked list to free
 *
 * Return: void(nothing to return)
 */

void free_listint2(listint_t **head)
{
	listint_t *next_node;

	if (!head || *head == NULL)
		return;

	for (next_node = (*head)->next; *head != NULL; *head = next_node)
	{
		next_node = (*head)->next;
		free(*head);
	}
}
