#include "main.h"
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for result
 * @size_r: buffer size
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0;
	int len1 = strlen(n1);
	int len2 = strlen(n2);
        int max_len = (len1 > len2 ? len1 : len2);
	if (max_len + 1 > size_r)
	{
 		/* Result can't be stored in r, return 0 */
		return 0;
	 }
	r[max_len + 1] = '\0';
   	int i = len1 - 1;
	int j = len2 - 1;
	int k = max_len;
	while (i >= 0 || j >= 0) {
		int sum = carry;
		if (i >= 0) 
		{
			sum += n1[i] - '0';
			i--;
		}
		if (j >= 0) 
		{
			sum += n2[j] - '0';
			j--;
		}
			carry = sum / 10;
			r[k] = sum % 10 + '0';
			k--;
		}

   		if (carry > 0) 
		{
	   		r[k] = carry + '0';
			return &r[k];
		} 
		else
		{
			return &r[k+1];
		}
}
