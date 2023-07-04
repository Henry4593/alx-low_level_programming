#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * find_loop_listint_t - finds a loop in a linked list
 *
 * @head: linked list to traverse
 *
 * Return: address of the looped node, NULL on NO loop
 */

listint_t *find_loop_listint_t(listint_t *head)
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
 * print_listint_safe - safely prints listint_t linked list
 *
 * @head: head of the linked list listint_t
 *
 * Return: number of nodes in the linked list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t length = 0;
	int loop;
	listint_t *looped_node;

	looped_node = find_loop_listint_t((listint_t *) head);

	for (length = 0, loop = 1; (head != looped_node || loop) &&
			head != NULL; length++)
	{
		printf("[%p] %d\n", (void *) head, head->n);
		if (head == looped_node)
			loop = 0;
		head = head->next;
	}

	if (looped_node)
		printf("-> [%p] %d\n", (void *) head, head->n);
	return (length);
}
