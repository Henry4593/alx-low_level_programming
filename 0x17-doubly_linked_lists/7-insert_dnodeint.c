#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node in
 * a dlistint_t list at given index.
 * @h: A pointer to the head pointer of the list.
 * @idx: The index to insert the new node at - 0 based.
 * @n: The integer for the new node to contain.
 *
 * Description: Dynamically allocates new node, sets n value.
 * Handles insert at index 0 separately (new head).
 * Traverses list to find insertion point, updates next/prev
 * pointers to insert.
 *
 * Return: Pointer to new node, or NULL on failure.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *new_node = malloc(sizeof(dlistint_t)), *temp_node = *h;

	if (new_node)
	{
		new_node->n = n;
		if (idx == 0)
		{
			if (*h)
			{
				new_node->next = *h;
				(*h)->prev = new_node;
			}
			*h = new_node;
			return (new_node);
		}
		while (i < idx - 1 && temp_node)
		{
			temp_node = temp_node->next;
			i++;
		}
		if (temp_node)
		{
			if (temp_node->next)
				temp_node->next->prev = new_node;
			new_node->next = temp_node->next;
			new_node->prev = temp_node;
			temp_node->next = new_node;
			return (new_node);
		}
	}
	return (NULL);
}
