#include "hash_tables.h"

/**
 * hash_table_create - Creates a new hash table
 * @size: The size of the hash table array
 * 
 * Description: Allocates memory for a new hash table struct and 
 * array of pointers to nodes based on @size.
 * Initializes array to NULL values.
 * On failure to allocate memory, returns NULL.
 *
 * Return: Upon success - pointer to new hash table struct
 *         On failure   - NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int idx_i;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (idx_i = 0; idx_i < size; idx_i++)
		ht->array[idx_i] = NULL;

	return (ht);
}
