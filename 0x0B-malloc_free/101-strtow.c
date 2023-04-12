#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * word_count - counts the number of words in a given string
 * @str: provided string
 *
 * Return: number of words in the string.
 */

int word_count(char *str)
{
	int flag, char_, num_of_words;

	flag = 0;
	num_of_words = 0;

	for (char_ = 0; str[char_] != '\0'; char_++)
	{
		if (str[char_] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			num_of_words++;
		}
	}

	return (num_of_words);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: the strings,NULL (Error)
 */

char **strtow(char *str)
{
	char **matrix, *temp;
	int x, y = 0, len = 0, num_words, char_ = 0, start, end;

	while (*(str + len))
		len++;
	num_words = word_count(str);
	if (num_words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (num_words + 1));
	if (matrix == NULL)
		return (NULL);

	for (x = 0; x <= len; x++)
	{
		if (str[x] == ' ' || str[x] == '\0')
		{
			if (char_)
			{
				end = x;
				temp = (char *) malloc(sizeof(char) * (char_ + 1));
				if (temp == NULL)
					return (NULL);
				while (start < end)
					*temp++ = str[start++];
				*temp = '\0';
				matrix[y] = temp - char_;
				y++;
				char_ = 0;
			}
		}
		else if (char_++ == 0)
			start = x;
	}

	matrix[char_] = NULL;

	return (matrix);
}
