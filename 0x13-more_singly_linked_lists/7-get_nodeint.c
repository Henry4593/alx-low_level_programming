#include "lists.h"
#include <stdlib.h>

/**
 * get_nodeint_at_index - a function that returns the nth node of a listint_t
 * linked list.
 *
 * @head: head of the linked list/first node of the linked list
 * @index: index/position of the node
 *
 * Return: node at the nth index
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	while (index--)
		if (head)
			head = head->next;
		else
			return (NULL);
	return (head);
}
