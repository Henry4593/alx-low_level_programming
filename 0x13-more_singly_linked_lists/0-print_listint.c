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
	size_t len = 0;

	if (!h)
		return (0);

	for (; h; h = h->next, len++)
		printf("%d\n", h->n);

	return (len);
}
