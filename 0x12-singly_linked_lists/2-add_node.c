#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a node at the beginning of list_t
 *
 * @head: preceeding node of intended appended node
 * @str: element string of the node
 *
 * Return: address of new element, NULL on failure
 */

list_t *add_node(list_t **head, const char *str)
{
	char *new_string, *_ptr;
	list_t *newNode;
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

	newNode = malloc(sizeof(list_t));
	if (!newNode)
	{
		free(new_string);
		return (NULL);
	}

	if (*head)
		newNode->next = *head;
	newNode->str = new_string;
	newNode->len = len;
	*head = newNode;
	return (newNode);
}
