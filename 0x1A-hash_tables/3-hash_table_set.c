#include "hash_tables.h"

/**
 * hash_table_set - Sets a key-value pair in a hash table
 * @ht: The hash table to set the value in
 * @key: The key to set
 * @value: The value to associate with the key
 *
 * Description: If the key already exists in the hash table, the value is
 * updated. Otherwise, a new node is created and added to the table.
 *
 * Return: 1 on success, 0 on failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node_to_insert;
	char *value_copy;
	unsigned long int index, idx_i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (idx_i = index; ht->array[idx_i]; idx_i++)
	{
		if (strcmp(ht->array[idx_i]->key, key) == 0)
		{
			free(ht->array[idx_i]->value);
			ht->array[idx_i]->value = value_copy;
			return (1);
		}
	}

	node_to_insert = malloc(sizeof(hash_node_t));
	if (node_to_insert == NULL)
	{
		free(value_copy);
		return (0);
	}
	node_to_insert->key = strdup(key);
	if (node_to_insert->key == NULL)
	{
		free(node_to_insert);
		return (0);
	}
	node_to_insert->value = value_copy;
	node_to_insert->next = ht->array[index];
	ht->array[index] = node_to_insert;

	return (1);
}
