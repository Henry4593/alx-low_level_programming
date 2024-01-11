#include "lists.h"

/**
 * dlistint_len_recursive - Counts number of nodes in a
 * linked dlistint_t list recursively.
 * @h: A pointer to the head node of the dlistint_t list.
 * @elements: Counter for the number of nodes traversed so far.
 *
 * Description: Recursively traverses linked list by calling itself on each
 * next node until the end is reached. Updates the elements counter
 * after each call.
 *
 * Return: The total number of nodes in the list.
 */

size_t dlistint_len_recursive(const dlistint_t *h, size_t elements)
{
	if (h)
		elements = dlistint_len_recursive(h->next, elements + 1);
	return (elements);
}

/**
 * dlistint_len - Returns number of elements in a linked dlistint_t list.
 * @h: A pointer to the head node of the dlistint_t list.
 *
 * Description: Counts number of nodes by calling the
 * dlistint_len_recursive function to traverse the list
 * and count nodes.
 *
 * Return: The number of nodes in the list.
 */

size_t dlistint_len(const dlistint_t *h)
{
	return (dlistint_len_recursive(h, 0));
}
