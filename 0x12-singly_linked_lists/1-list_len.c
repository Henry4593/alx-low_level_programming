#include "lists.h"
#include <stdio.h>

/**
 * list_len - returns number of elements in linked list list_t
 *
 * @h: first node of linked list containing elements
 *
 * Return: number of elements in the nodes
 */

size_t list_len(const list_t *h)
{
	size_t len = 0;

	if (h == 0)
		return (0);
	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}
