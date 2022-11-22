#include "main.h"

/**
 * doi - (decimal or integer) function that adds decimal or integer numbers to
 * character array pointed to by @out.
 * @a: number to be added to character array.
 * @out: pointer to character array to be written to stdout.
 * @j: pointer to index of @out.
 * @k: pointer to index of string to be written to stdout.
 * Return: nothing.
 */
void doi(int a, char *out, int *k, int *j)
{
	int i, tmp;

	if (a < 0)
	{
		a *= -1;
		out[*j] = '-';
		*j += 1;
	}

	tmp = a;
	i = 0;

	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}

	*j = tmp = *j + i;
	*k += 1;

	if (*j == 0)
		out = (char *) realloc(out, SCHAR);
	else
		out = (char *) realloc(out, SCHAR * (*j + i));
	if (out != NULL)
	{
		while (i >= 0)
		{
			out[tmp] = (a % 10) + 48;
			a /= 10;
			tmp--;
			i--;
		}
	}
	else
		exit(1);
}
