#include "lists.h"
#include <stdlib.h>

/**
 * find_loop_listint_t_f - finds loop(s) in a linked list listint_t
 *
 * @head: linked list to traverse
 *
 * Return: address of the node where loop begins/returns, (NULL) NO loop
 */

listint_t *find_loop_listint_t_f(listint_t *head)
{
	listint_t *ptr, *last_node;

	if (!head)
		return (NULL);

	for (last_node = head->next; last_node != NULL; last_node = last_node->next)
	{
		if (last_node == last_node->next)
			return (last_node);
		for (ptr = head; ptr != last_node; ptr = ptr->next)
			if (ptr == last_node->next)
				return (last_node->next);
	}
	return (NULL);
}

/**
 * free_listint_safe - a function that safely frees a listint_t list.
 *
 * @h: head of the linked list
 *
 * Return: number of node(s) freed
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *looped_node;
	size_t length;
	int loop = 1;

	if (!h || *h == NULL)
		return (0);

	looped_node = find_loop_listint_t_f(*h);
	for (length = 0; (*h != looped_node || loop) && *h != NULL; *h = next)
	{
		length++;
		next = (*h)->next;
		if (*h == looped_node && loop)
		{
			if (looped_node == looped_node->next)
			{
				free(*h);
				break;
			}
			length++;
			next = next->next;
			free((*h)->next);
			loop = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (length);
}
