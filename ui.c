#include "main.h"

/**
 * ui - (unsigned integer) function that adds unsigned integer number to
 * character array pointed to by @out.
 * @a: number to be added to character array.
 * @out: pointer to character array to be written to stdout.
 * @k: pointer to current index of string to be written to stdout
 * @j: pointer to current index of @out.
 * Return: nothing.
 */
void ui(unsigned int a, char *out, int *k, int *j)
{
	unsigned int tmp;
	int i;

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
