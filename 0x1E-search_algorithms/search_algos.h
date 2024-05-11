#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_t - Node structure for a singly linked list.
 *
 * @n: The integer value stored in the node.
 * @index: The index of the node within the linked list.
 * @next: Pointer to the next node in the singly linked list.
 */
typedef struct listint_s
{
  int n;
  size_t index;
  struct listint_s *next;
} listint_t;

/**
 * struct skiplist_t - Node structure for a skiplist.
 *
 * @n: The integer value stored in the node.
 * @index: The index of the node within the skiplist.
 * @next: Pointer to the next node in the standard list structure.
 * @express: Pointer to another node in the skiplist used for the express lane.
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
