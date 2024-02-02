#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and all its key-value pairs
 * @ht: The hash table to delete
 *
 * Description: Frees all memory associated with the hash table, including
 * the hash table structure itself, the array of linked lists, and all
 * key-value node pairs within those lists.
 *
 * Return: None
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *head = ht;
	hash_node_t *node, *temp;
	unsigned long int idx_i;

	for (idx_i = 0; idx_i < ht->size; idx_i++)
	{
		if (ht->array[idx_i] != NULL)
		{
			node = ht->array[idx_i];
			while (node != NULL)
			{
				temp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = temp;
			}
		}
	}
	free(head->array);
	free(head);
}
