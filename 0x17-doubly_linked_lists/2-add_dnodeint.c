#include "lists.h"
/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: A pointer to the head pointer of the doubly linked list.
 * @n: The integer for the new node to contain.
 *
 * Description: Dynamically allocates memory for a new node,
 * assigns its integer value to n, links it to the beginning of
 * the list by updating the head pointer and previous/next
 * pointers appropriately.
 *
 * Return: A pointer to the new node, or NULL on failure.
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node)
	{
		new_node->n = n;
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head)
			(*head)->prev = new_node;
		*head = new_node;
	}
	return (new_node);
}
