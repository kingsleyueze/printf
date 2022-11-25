#include "main.h"

/**
 * s - (string) function that adds a string to character array pointed to by
 * @out.
 * @a: character pointer to string.
 * @out: pointer to character array to be written to stdout.
 * @k: pointer to current index of string to be written to stdout.
 * @j: pointer to current index of @out.
 * Return: nothing.
 */
void s(char *a, char *out, int *k, int *j)
{
	int i, index;

	index = *j;
	i = 0;

	while (a[i])
	{
		if (*j == 0)
			out = (char *) realloc(out, SCHAR);
		else
			out = (char *) realloc(out, SCHAR * (*j + i) + SCHAR);
		if (out != NULL)
		{
			out[index] = a[i];
			index++;
			i++;
		}
		else
			exit(1);
	}

	*j = --index;
	*k += 1;
}
