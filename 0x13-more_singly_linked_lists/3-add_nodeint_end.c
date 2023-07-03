#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a node to the end of the linked list
 *
 * @head: the initial node of the list
 * @n: data/value to assign to the new node
 *
 * Return: address to the newly added node
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *ptr_end, *current_end;

	if (!head)
		return (NULL);
	current_end = *head;
	if (current_end)
		while (current_end->next != NULL)
			current_end = current_end->next;

	ptr_end = malloc(sizeof(listint_t));
	if (!ptr_end)
		return (NULL);

	ptr_end->n = n;
	if (*head == NULL)
	{
		*head = ptr_end;
		ptr_end->next = NULL;
	}
	else
	{
		current_end->next = ptr_end;
		ptr_end->next = NULL;
	}
	return (ptr_end);
}
