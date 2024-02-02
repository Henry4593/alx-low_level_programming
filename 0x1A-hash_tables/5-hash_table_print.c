#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table's contents in a formatted string
 * @ht: The hash table to print
 *
 * Description: Prints the key-value pairs of the hash table in a format
 * similar to Python dictionaries, enclosed in curly braces and using
 * colons and commas to separate elements.
 *
 * Return: None
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int idx_i;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (idx_i = 0; idx_i < ht->size; idx_i++)
	{
		if (ht->array[idx_i] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			node = ht->array[idx_i];
			while (node != NULL)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (node != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
