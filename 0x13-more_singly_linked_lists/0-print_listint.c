#include "lists.h"
#include <stddef.h>
#include <stdio.h>

/**
 * print_listint - prints all the data/value of the nodes and return length
 * of the linked list
 *
 * @h: head of the linked list which is also the name of the linked list
 *
 * Return: length of list
 */

size_t print_listint(const listint_t *h)
{
	size_t len;

	if (!h)
		return (NULL);

	for (len = 0; h; h = h->next, len++)
		printf("%d\n", h->n);

	return (len);
}
