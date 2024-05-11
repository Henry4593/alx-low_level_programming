#include "search_algos.h"

/**
 * linear_skip - Searches for a value in a sorted skiplist using Linear Search.
 * @list: Pointer to the head of the sorted skiplist.
 * @value: Target value to search for.
 *
 * Return: Pointer to the matching node in the skiplist, or NULL if not found.
 *
 * Description: This function implements a linear search algorithm to find
 * the first occurrence of a value in a sorted skiplist. It starts
 * at the head of the skiplist and traverses the nodes level by level
 * using the express pointers to quickly jump over large gaps in
 * the list. If no more express pointers are available at a level,
 * it switches to regular next pointers until it reaches the end of
 * the list or finds the target value.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *jump;

	if (list == NULL)
		return (NULL);

	for (node = jump = list; jump->next != NULL && jump->n < value;)
	{
		node = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
