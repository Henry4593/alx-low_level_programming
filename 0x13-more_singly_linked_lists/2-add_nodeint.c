#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - preppends a node to a listint_t list
 *
 * @head: node that the new node is preppended to.
 * @n: integer number to be assigned to the data/value element of the new node
 *
 * Return: new head address
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if (!head)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	return (*head);
}
