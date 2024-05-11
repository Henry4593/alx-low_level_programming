#include "../search_algos.h"

void free_skiplist(skiplist_t *list);

/**
 * init_express - Initializes express pointers for a skiplist.
 * @list: Pointer to the head of the skiplist.
 * @size: The level of the skiplist (number of express pointers).
 *
 * Description: This function initializes the express pointers for a skiplist.
 * It iterates through the nodes and assigns the express pointer
 * of each node to the `step`-th node ahead (where `step` is the
 * square root of the list size) if it exists within the list bounds.
 */
void init_express(skiplist_t *list, size_t size)
{
	const size_t step = sqrt(size);
	size_t i;
	skiplist_t *save;

	for (save = list, i = 0; i < size; ++i, list = list->next)
	{
		if (i % step == 0)
		{
			save->express = list;
			save = list;
		}
	}
}

/**
 * create_skiplist - Creates a skiplist from an array of integers.
 * @array: Pointer to the array of integers to convert into a skiplist.
 * @size: Number of elements in the array.
 *
 * Return: Pointer to the head of the created skiplist, or NULL on failure.
 *
 * Description: This function creates a skiplist from an array by allocating
 * memory for each node and initializing its value, index, express
 * pointer (initially NULL), and next pointer. It iterates through
 * the array in reverse order to ensure the order of elements in
 * the skiplist matches the order in the array. After creating the
 * basic list structure, the init_express function is called to
 * initialize the express pointers for the skiplist.
 */
skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *list;
	skiplist_t *node;
	size_t save_size;

	list = NULL;
	save_size = size;
	while (array && size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
		{
			free_skiplist(list);
			return (NULL);
		}
		node->n = array[size];
		node->index = size;
		node->express = NULL;
		node->next = list;
		list = node;
	}
	init_express(list, save_size);
	return (list);
}
