#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The initial size of the hash table
 *
 * Description: Allocates memory for a sorted hash table structure and
 * initializes its fields. The table uses an array of linked lists to store
 * key-value pairs, and it maintains a sorted order of keys for efficient
 * retrieval.
 *
 * Return: A pointer to the newly created hash table, or NULL on failure
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int idx_i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (idx_i = 0; idx_i < size; idx_i++)
		ht->array[idx_i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Sets a key-value pair in a sorted hash table
 * @ht: The sorted hash table to set the value in
 * @key: The key to set
 * @value: The value to associate with the key
 *
 * Description: Inserts a key-value pair into the hash table, maintaining
 * the sorted order of keys. If the key already exists, the value is
 * updated. Otherwise, a new node is created and inserted at the correct
 * position in the sorted list.
 *
 * Return: 1 on success, 0 on failure
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *temp;
	char *value_copy;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->shead;
	while (temp)
	{
		if (strcmp(temp->key, key) == 0)
		{
			free(temp->value);
			temp->value = value_copy;
			return (1);
		}
		temp = temp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (0);
	}
	new->value = value_copy;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		temp = ht->shead;
		while (temp->snext != NULL && strcmp(temp->snext->key, key) < 0)
			temp = temp->snext;
		new->sprev = temp;
		new->snext = temp->snext;
		if (temp->snext == NULL)
			ht->stail = new;
		else
			temp->snext->sprev = new;
		temp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value from a sorted hash table by key
 * @ht: The sorted hash table to search
 * @key: The key to search for
 *
 * Description: Searches for the given key in the hash table and returns
 * the associated value if found. Leverages the sorted nature of the
 * table to efficiently iterate through keys in order.
 *
 * Return: The value associated with the key, or NULL if not found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - Prints the contents of a sorted hash table
 * @ht: The sorted hash table to print
 *
 * Description: Prints the key-value pairs of the hash table in a sorted
 * format, enclosed in curly braces and using colons and commas to separate
 * elements. Leverages the sorted list structure to print keys in order.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the contents of a sorted hash table in reverse order
 * @ht: The sorted hash table to print
 *
 * Description: Prints the key-value pairs of the hash table in a sorted
 * format, but in reverse order of keys. Leverages the `stail` pointer
 * to efficiently iterate through the sorted list in reverse.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and all its key-value pairs
 * @ht: The sorted hash table to delete
 *
 * Description: Frees all memory associated with the hash table, including
 * the hash table structure itself, the array of linked lists, and all
 * key-value node pairs within those lists. Deallocates memory in a
 * controlled manner to prevent memory leaks.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}

	free(head->array);
	free(head);
}
