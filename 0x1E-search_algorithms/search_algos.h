#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Node structure for a singly linked list.
 * @n: The integer value stored in the node.
 * @index: The index of the node within the linked list.
 * @next: Pointer to the next node in the singly linked list.
 *
 * Description: This structure defines a node for a singly linked list.
 * Each node contains an integer value 'n', an index 'index' indicating
 * the position of the node in the list, and a pointer 'next' to the next
 * node in the list. The list is traversed by following the 'next' pointers
 * from one node to the next.
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Node structure for a skiplist.
 * @n: The integer value stored in the node.
 * @index: The index of the node within the skiplist.
 * @next: Pointer to the next node in the standard list structure.
 * @express: Pointer to another node in the skiplist used for the express lane.
 *
 * Description: This structure defines a node for a skiplist. A skiplist is a
 * data structure that allows fast search within an ordered sequence of
 * elements. Each node contains an integer value 'n', an index 'index'
 * indicating the position of the node in the list, a 'next' pointer to the
 * next node in the standard list structure, and an 'express' pointer to
 * another node in the skiplist used for the express lane, which allows for
 * faster traversal of the list.
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

listint_t *jump_list(listint_t *list, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
