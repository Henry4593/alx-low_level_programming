#include "lists.h"
#include <stdlib.h>

/**
 * find_listint_loop - finds loop(s) in listint_t linked list
 *
 * @head: linked list to traverse
 *
 * Return: address of the node where loop begins/returns, (NULL) No loop
 */

listint_t *find_listint_loop(listint_t *head)
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
