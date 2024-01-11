#include "lists.h"

/**
 * print_dlistint_recursive - Prints all elements of
 * a dlistint_t linked list recursively.
 * @h: A pointer to the head of the dlistint_t list.
 * @elements: Keeps track of the number of nodes printed so far.
 *
 * Description: Recursively prints each node's integer value
 * in the linked list.
 * Prints newline after each element. Updates elements counter after each call.
 * Recursively calls itself to print next node until
 * reaching end of list (NULL).
 *
 * Return: The number of nodes printed.
 */

size_t print_dlistint_recursive(const dlistint_t *h, size_t elements)
{
	if (h)
	{
		printf("%i\n", h->n);
		elements = print_dlistint_recursive(h->next, elements + 1);
	}
	return (elements);
}

/**
 * print_dlistint - Prints all elements of a dlistint_t list.
 * @h: A pointer to the head node of the dlistint_t list.
 *
 * Description: Prints all nodes in a dlistint_t list by calling
 * the print_dlistint_recursive function which prints the
 * list recursively.
 *
 * Return: The number of nodes printed.
 */
size_t print_dlistint(const dlistint_t *h)
{
	return (print_dlistint_recursive(h, 0));
}
