#ifndef CALC_H
#define CALC_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct op - Struct that contains the
 * operator and the operation.
 * @op: the operator for computation
 * @f: computational function
 */

typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);
int _atoi(char *s);
int idx_num_starts(char *s);
int find_sign(char *s);
int _strlen(char *s);

#endif
