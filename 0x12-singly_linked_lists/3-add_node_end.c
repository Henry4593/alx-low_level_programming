#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - adds a node at the end of a list_t
 *
 * @head: preceding node to the new node
 * @str: string value of the new node element
 *
 * Return: address of new node, NULL on failure
 */

list_t *add_node_end(list_t **head, const char *str)
{
	char *new_string, *_ptr;
	list_t *newNode, *last_node = NULL;
	int len = 0;

	if (str)
	{
		_ptr = (char *) str;
		while (*_ptr++)
			len++;
		new_string = malloc(sizeof(char) * (len + 1));
		if (!new_string)
			return (NULL);

		_ptr = new_string;
		while (*str)
			*_ptr++ = *str++;
	}
	else
		new_string = NULL;

	if (*head)
	{
		last_node = *head;
		while (last_node->next)
			last_node = last_node->next;
	}
	newNode = malloc(sizeof(list_t));
	if (!newNode)
	{
		free(new_string);
		return (NULL);
	}

	if (*head == NULL)
		*head = newNode;
	if (last_node)
		last_node->next = newNode;
	newNode->str = new_string;
	newNode->len = len;
	return (newNode);
}
