#include "lists.h"

/**
 * sum_dlistint_recursively - Sums all data (n) in
 * a dlistint_t linked list recursively.
 *
 * @head: A pointer to the head node of the dlistint_t list.
 * @sum: Running sum of current node's n + previous sum.
 *
 * Description: Recursively sums each node's n data by traversing list.
 * Updates sum with current node's data + previous recursive call's sum.
 * Continues traversing list and summing until end is reached (head == NULL).
 *
 * Return: Sum of all data (n) in the dlistint_t linked list.
 */

int sum_dlistint_recursively(dlistint_t *head, int sum)
{
	if (head)
		sum = sum_dlistint_recursively(head->next, sum + head->n);
	return (sum);
}

/**
 * sum_dlistint - Sums all data (n) in a dlistint_t linked list.
 * @head: A pointer to the head node of the dlistint_t list.
 *
 * Description: Initializes sum to 0, calls recursive sum_dlistint_recursively
 * function to traverse list and calculate sum of all node's data (n).
 *
 * Return: Sum of all node's data (n) in list.
 */

int sum_dlistint(dlistint_t *head)
{
	int n = 0;

	return (sum_dlistint_recursively(head, n));
}
