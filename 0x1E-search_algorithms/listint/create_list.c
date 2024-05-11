#include "../search_algos.h"

void free_list(listint_t *list);

/**
 * create_list - Creates a singly linked list from an array.
 * @array: Pointer to the array to convert to a linked list.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the head of the created linked list, or NULL on failure.
 *
 * Description: This function creates a singly linked list by allocating memory
 * for each node and initializing its value, index, and next pointer.
 * It iterates through the array in reverse order to ensure the order
 * of elements in the linked list matches the order in the array.
 */
listint_t *create_list(int *array, size_t size)
{
	listint_t *list;
	listint_t *node;

	list = NULL;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_list(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->next = list;
		list = node;
	}
	return (list);
}
