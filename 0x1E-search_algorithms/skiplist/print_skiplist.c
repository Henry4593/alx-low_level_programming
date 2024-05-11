#include "../search_algos.h"

/**
 * print_skiplist - Prints the contents of a skiplist.
 * @list: The head of the skiplist to print.
 *
 * Description: This function prints the elements of a skiplist,
 * one node per line, in two sections:
 *   - Standard list: Prints the index and value of each node
 *     following the `next` pointers.
 *   - Express lane: Prints the index and value of each node
 *     following the `express` pointers (if any).
 */
void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *node;

	printf("List :\n");
	for (node = list; node; node = node->next)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	}
	printf("\nExpress lane :\n");
	for (node = list; node; node = node->express)
	{
		printf("Index[%lu] = [%d]\n", node->index, node->n);
	}
	printf("\n");
}
