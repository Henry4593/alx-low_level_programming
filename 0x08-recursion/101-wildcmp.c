#include "main.h"
/**
 * substr_match - check if a substring immediately after
 * special char "*" matches s1
 * @s1: normal string
 * @s2: special string
 * @after_spec_char: placeholder immediately after special char "*"
 * Return: 1 if identical, 0 if non-identical
 */

int substr_match(char *s1, char *s2, char *after_spec_char)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '\0' && *s2 == '*')
		return (substr_match(s1, s2 + 1, s2 + 1));
	if (*s1 == '\0' && *s2 != '\0')
		return (0);
	if (*s2 == '*')
		return (substr_match(s1, s2 + 1, s2 + 1));
	if (*s1 == *s2)
		return (substr_match(s1 + 1, s2 + 1, after_spec_char));
	else
		return (substr_match(s1 + 1, after_spec_char, after_spec_char));
}

/**
 * wildcmp - compare if string with special char matches
 * @s1: normal string
 * @s2: special string
 * Return: 1 if matches, 0 if it does not
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s2 == '*')
		return (substr_match(s1, (s2 + 1), (s2 + 1)));
	else
		return (0);
}
