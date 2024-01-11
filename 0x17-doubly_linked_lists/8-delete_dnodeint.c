#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes node at given index in a dlistint_t list.
 * @head: A pointer to the head pointer of the list.
 * @index: The index of the node to delete - 0 based.
 *
 * Description: Handles deleting the head node separately.
 * Traverses list to find node before index.
 * Updates next and prev pointers to remove node at index.
 * Frees the removed node.
 *
 * Return: 1 on success, -1 on failure.
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *preceding_node = *head, *temp_node = *head;

	if (index == 0 && *head)
	{
		if ((*head)->next)
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
			free(temp_node);
		}
		else
			*head = NULL;
		return (1);
	}
	while (i < index - 1 && preceding_node)
	{
		preceding_node = preceding_node->next;
		i++;
	}
	if (preceding_node)
	{
		temp_node = preceding_node->next;
		if (temp_node->next)
			temp_node->next->prev = preceding_node;
		preceding_node->next = temp_node->next;
		free(temp_node);
		return (1);
	}
	return (-1);
}
