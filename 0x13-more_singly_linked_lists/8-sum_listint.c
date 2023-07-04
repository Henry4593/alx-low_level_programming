#include "lists.h"
#include <stdlib.h>

/**
 * sum_listint - a function that returns the sum of all the data (n) of a
 * listint_t linked list.
 *
 * @head: head of the linked list
 *
 * Return: sum of n data/value from all the nodes, (0) on empty list
 */

int sum_listint(listint_t *head)
{
	int sum_total;

	if (!head)
		return (0);

	for (sum_total = 0; head; head = head->next)
		sum_total += head->n;

	return (sum_total);
}
