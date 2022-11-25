#include "main.h"

/**
 * rs - (reverse string) function that adds a string reversed to character
 * array pointed to by @out.
 * @a: character pointer to string.
 * @out: pointer to character array to be written to stdout.
 * @k: pointer to current index of string to be written to stdout.
 * @j: pointer to current index of @out.
 * Return: nothing.
 */
void rs(char *a, char *out, int *k, int *j)
{
	int index, i, swp;

	index = *j;
	i = 0;
	swp = 0;

	while (a[i])
	{
		index++;
		i++;
	}
	*j = --index;
	*k += 1;

	if (index == 0)
		out = (char *) realloc(out, SCHAR);
	else
		out = (char *) realloc(out, SCHAR * index);
	if (out != NULL)
	{
		while (swp < i)
		{
			out[index] = a[swp];
			index--;
			swp++;
		}
	}
	else
		exit(1);

}
