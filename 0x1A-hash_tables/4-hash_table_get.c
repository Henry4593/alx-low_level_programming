#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value from a hash table by key
 * @ht: The hash table to search
 * @key: The key to search for
 *
 * Description: Searches for the given key in the hash table and returns
 * the associated value if found. If the key is not found, returns NULL.
 *
 * Return: The value associated with the key, or NULL if not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *curr_node;
	unsigned long int calc_idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	calc_idx = key_index((const unsigned char *)key, ht->size);
	if (calc_idx >= ht->size)
		return (NULL);

	curr_node = ht->array[calc_idx];
	while (curr_node && strcmp(curr_node->key, key) != 0)
		curr_node = curr_node->next;

	return ((curr_node == NULL) ? NULL : curr_node->value);
}
