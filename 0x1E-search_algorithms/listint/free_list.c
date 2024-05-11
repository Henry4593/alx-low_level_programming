#include "../search_algos.h"

/**
 * free_list - Frees a singly linked list.
 * @list: Pointer to the head of the linked list.
 *
 * Description: This function frees the memory allocated for each node
 * in the linked list in a recursive manner.
 */
void free_list(listint_t *list)
{
	listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}
