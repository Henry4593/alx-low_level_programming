#include <stdio.h>
#include <stdlib.h>

/**
 * init_startup - prints a string/array of characters before main is called.
 */

void __attribute__ ((constructor)) init_startup()
{
	printf("You're beat! and yet, you must allow,\n"
	       "I bore my house upon my back!\n");
}
