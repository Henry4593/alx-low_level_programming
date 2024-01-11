#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: A pointer to the head pointer of the list.
 * @n: The integer for the new node to contain.
 *
 * Description: Dynamically allocates memory for a new node,
 * assigns its integer value to n. If list is empty, sets
 * new node as the head. If not empty, traverses to end,
 * links new node to end by updating next/prev pointers.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp_node = NULL, *new_node = malloc(sizeof(dlistint_t));

	if (new_node)
	{
		new_node->n = n;
		if (*head)
		{
			temp_node = *head;
			while (temp_node->next)
				temp_node = temp_node->next;
			temp_node->next = new_node;
			new_node->prev = temp_node;
		}
		else
			*head = new_node;
	}
	return (new_node);
}
