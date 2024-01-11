#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * findLargestChar - Finds largest char in string and generates random number
 * @username: The string to search
 * @length: The length of the string
 *
 * Description: Iterates through the string to find largest char value.
 * Seeds rand with largest char xor'd with 14. Generates a random number.
 * Returns the random number bitwise AND'd with 63.
 *
 * Return: Random number derived from largest char in string
 */

int findLargestChar(char *username, int length)
{
	char currentChar = *username;
	int idx_char = 0;
unsigned int randomNumber;
	while (idx_char < length)
	{
		if (currentChar < username[idx_char])
			currentChar = username[idx_char];
		idx_char += 1;
	}

	srand(currentChar ^ 14);
	randomNumber = rand();

	return (randomNumber & 63);
}

/**
 * multiplyChars - Multiplies chars in string and bit shifts result
 * @username: The string of chars
 * @length: Length of the string
 *
 * Description: Iterates over the string, multiplying each char by itself
 * and summing to get a result integer.  Result is then XOR'd with 239
 * and bitwise AND'd with 63 before returning.
 *
 * Return: Bit shifted and masked integer derived from input string
 */

int multiplyChars(char *username, int length)
{
	int result = 0;
	int idx_char = 0;

	while (idx_char < length)
	{
		result = result + username[idx_char] * username[idx_char];
		idx_char += 1;
	}

	return (((unsigned int)result ^ 239) & 63);
}

/**
 * generateRandomChar - Generates random char derived from string
 * @username: The input string
 *
 * Description: Iterates over string, generating random number
 * at each step. Final random number is XOR'd with 229 and
 * bitwise AND'd with 63 before returning.
 *
 * Return: Random char generated based on input string
 */

int generateRandomChar(char *username)
{
	int result = 0;
	int idx_char = 0;

	while (idx_char < *username)
	{
		result = rand();
		idx_char += 1;
	}

	return (((unsigned int)result ^ 229) & 63);
}

/**
 * main - Generates a license key based on command line input
 * @argc: Number of command line arguments
 * @argv: Array of command line argument strings
 *
 * Description: Generates 6-char license key by processing argv[1]:
 * - Sum chars
 * - Multiply chars
 * - Find largest char
 * - Generate random char based on string
 * Results fed through lookup table to map to key chars.
 * Null terminates keygen array and prints result.
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char keygen[7];
	int length, ch, vch, idx_char;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void)argc;

	for (length = 0; argv[1][length]; length++)
		;

	keygen[0] = ((char *)alph)[(length ^ 59) & 63];
	ch = vch = 0;
	while (vch < length)
	{
		ch = ch + argv[1][vch];
		vch = vch + 1;
	}
	keygen[1] = ((char *)alph)[(ch ^ 79) & 63];

	ch = 1;
	idx_char = 0;
	while (idx_char < length)
	{
		ch = argv[1][idx_char] * ch;
		idx_char += 1;
	}
	keygen[2] = ((char *)alph)[(ch ^ 85) & 63];

	keygen[3] = ((char *)alph)[findLargestChar(argv[1], length)];
	keygen[4] = ((char *)alph)[multiplyChars(argv[1], length)];
	keygen[5] = ((char *)alph)[generateRandomChar(argv[1])];
	keygen[6] = '\0';

	for (ch = 0; keygen[ch]; ch++)
		printf("%c", keygen[ch]);

	return (0);
}
