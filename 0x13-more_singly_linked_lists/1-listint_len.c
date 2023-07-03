#include <stddef.h>
#include "lists.h"
#include <stdio.h>

/**
 * listint_len - returns the length of the singly linked list
 *
 * @h: the singly linked list
 *
 * Return: length of the linked list/number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t len;

	if (!h)
		return (NULL);

	for (len = 0; h; h = h->next, len++)
		;

	return (len);
}
