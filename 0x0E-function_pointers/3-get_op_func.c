#include <stdlib.h>
#include "3-calc.h"

/**
 * get_op_func - return the arithmetic operator function to use
 * @s: string containing operator to use
 *
 * Return: pointer to function or NULL if operator is unsupported
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (*ops[i].op == *s)
			break;
		i++;
	}
	return (ops[i].f);
}
