#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - returns new head node data after deleting the previous head
 * node
 *
 * @head: head of the linked list
 *
 * Return: head node data/value,0 on the absence of data
 */

int pop_listint(listint_t **head)
{
	int n;
	listint_t *next_node;

	if (!head || *head == NULL)
		return (0);

	n = (*head)->n;
	next_node = (*head)->next;
	free(*head);
	*head = next_node;
	return (n);
}
