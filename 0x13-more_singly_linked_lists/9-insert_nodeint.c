#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given index/position
 *
 * @head: head of the linked list
 * @idx: index to add the new node at
 * @n: value/data element of the newly added node
 *
 * Return: address of the new node,NULL if it fails
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode, *previous_node = NULL;
	int current_t_index = idx;

	if (!head)
		return (NULL);

	for (newNode = *head; current_t_index && newNode != NULL;
			current_t_index--, newNode = newNode->next)
		previous_node = newNode;
	if (current_t_index)
		return (NULL);

	newNode = malloc(sizeof(listint_t));
	if (!newNode)
		return (NULL);

	if (previous_node)
	{
		newNode->next = previous_node->next;
		previous_node->next = newNode;
	}
	else
	{
		newNode->next = NULL;
	}
	if (*head == NULL || idx == 0)
	{
		newNode->next = *head;
		*head = newNode;
	}
	newNode->n = n;
	return (newNode);
}
