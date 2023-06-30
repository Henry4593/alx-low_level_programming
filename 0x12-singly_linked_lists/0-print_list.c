#include "lists.h"
#include <stdio.h>

/**
 * print_list - prints contents/elements of linked list
 *
 * @h: first node of linked list to print
 *
 * Return: no_. of node(s) printed
 */
size_t print_list(const list_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h)
	{
		if (h->str)
			printf("[%d] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");
		len++;
		h = h->next;
	}
	return (len);
}
