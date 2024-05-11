#include "../search_algos.h"

/**
 * free_skiplist - Frees the memory allocated for a skiplist.
 * @list: Pointer to the head of the skiplist.
 *
 * Description: This function frees the memory allocated for each node
 * in the skiplist in a recursive manner.
 */
void free_skiplist(skiplist_t *list)
{
	skiplist_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_skiplist(node);
	}
}
