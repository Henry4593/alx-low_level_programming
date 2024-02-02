#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key in a hash table
 * @key: The key to hash (a null-terminated string)
 * @size: The size of the hash table
 *
 * Description: This function calculates the index where a key should be stored
 * in a hash table of a given size. It uses the djb2 hash function to map the
 * key to a hash value and then takes the modulo of the hash value and the size
 * of the table to ensure the index stays within the valid range (0 to size-1).
 *
 * Return: The index of the key in the hash table, within the range [0, size-1]
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
