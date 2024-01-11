#include "lists.h"

/**
 * get_node_recursively - Gets a node at a given index in a
 * dlistint_t list recursively.
 * @head: A pointer to the head node of the list.
 * @index: The index of the node to get - 0 based.
 * @n: Current index traversing through the list - increments at each call.
 *
 * Description: Traverses list recursively keeping count with n.
 * When n matches index, returns the node at that position.
 *
 * Return: Pointer to the node at index, or NULL if fail.
 */

dlistint_t *get_node_recursively(dlistint_t *head, unsigned int index,
		unsigned int n)
{
	if (head)
	{
		if (n == index)
			return (head);
		head = get_node_recursively(head->next, index, n + 1);
	}
	return (head);
}

/**
 * get_dnodeint_at_index - Gets a node at a given index in a dlistint_t list.
 * @head: A pointer to the head node of the list.
 * @index: The index of the node to get - 0 based.
 *
 * Description: Initializes counter n at 0, calls recursive
 * get_node_recursively function to find and return node at
 * index, passing n counter to increment through list.
 *
 * Return: Pointer to node, or NULL if node doesn't exist.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	int n = 0;

	return (get_node_recursively(head, index, n));
}
