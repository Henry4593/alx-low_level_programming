#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 hash function for strings
 * @str: The null-terminated string to hash
 *
 * Description: This function calculates a hash value for the given string
 * using the djb2 algorithm. The djb2 algorithm is a fast and simple hash
 * function that produces good hash distributions for most strings.
 *
 * Return: The calculated hash value for the string
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
