#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - a function that deletes the node at index index of
 * a listint_t linked list.
 *
 * @head: head of the linked list
 * @index: index at the deletion happens
 *
 * Return: 1 on success, -1 on failure
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *curr_node, *previous_node;

	if (!head || *head == NULL)
		return (-1);
	if (index == 0)
	{
		curr_node = (*head)->next;
		free(*head);
		*head = curr_node;
		return (1);
	}

	for (curr_node = *head; index && curr_node->next != NULL;
			index--, curr_node = curr_node->next)
		previous_node = curr_node;
	if (index)
		return (-1);

	previous_node->next = previous_node->next->next;
	free(curr_node);
	return (1);
}
