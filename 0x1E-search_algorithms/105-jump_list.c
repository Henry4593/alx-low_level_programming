#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted linked list using Jump Search.
 * @list: Pointer to the head of the sorted linked list.
 * @size: Number of elements in the linked list.
 * @value: Target value to search for.
 *
 * Return: Pointer to the matching node in the list, or NULL if not found.
 *
 * Description: This function implements the Jump Search algorithm to find
 * the first occurrence of a value in a sorted linked list. It uses
 * the square root of the list size as a jump step to quickly
 * traverse the list and narrow down the search range. The final
 * linear search is then performed within the narrowed range.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (step += step_size; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
