#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t linked list.
 * @head: A pointer to the head node of the dlistint_t list.
 *
 * Description: Recursively frees all nodes in a linked dlistint_t list.
 * Traverses to the end of the list freeing nodes along the way by calling
 * itself on each next node. Once next reaches NULL, head is freed.
 * Nodes are freed in reverse order (LIFO) compared to creation order.
 * Return: None
 */

void free_dlistint(dlistint_t *head)
{
	if (head)
	{
		free_dlistint(head->next);
		free(head);
	}
}
