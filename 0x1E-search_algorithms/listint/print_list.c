#include "../search_algos.h"

/**
 * print_list - Prints the contents of a singly linked list.
 * @list: The head of the singly linked list to print.
 *
 * Description: This function prints the elements of a singly linked list,
 * one node per line. It includes the index and value of each node.
 */
void print_list(const listint_t *list)
{
	printf("List :\n");
	while (list)
	{
		printf("Index[%lu] = [%d]\n", list->index, list->n);
		list = list->next;
	}
	printf("\n");
}
