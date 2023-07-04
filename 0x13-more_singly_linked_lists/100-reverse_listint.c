#include "lists.h"
#include <stdlib.h>

/**
 * reverse_recursive - reverses the linked list using recursion
 *
 * @first_node: node to reverse
 * @second_node: node adjacent to the first node
 *
 * Return: void
 */

listint_t *reverse_recursive(listint_t *first_node, listint_t *second_node)
{
	listint_t *curr_node, *previous_node = NULL;

	curr_node = first_node;
	while (curr_node->next != second_node)
	{
		previous_node = curr_node;
		curr_node = curr_node->next;
	}

	if (previous_node)
		previous_node->next = first_node;
	second_node = first_node->next;
	first_node->next = curr_node->next;
	if (first_node != curr_node && second_node != first_node)
		second_node = reverse_recursive(second_node, first_node);
	curr_node->next = second_node;
	return (curr_node);
}

/**
 * reverse_listint - reverses listint_t list
 *
 * @head: linked list to reverse
 *
 * Return: new head of list
 */

listint_t *reverse_listint(listint_t **head)
{
	if (!head || *head == NULL)
		return (NULL);

	*head = reverse_recursive(*head, NULL);
	return (*head);
}
