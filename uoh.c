#include <stdio.h>
#include "main.h"

/**
 * uoh - function that adds unsigned octal or hexadecimal numbers to character
 * array pointed to by @b.
 * @a: number in base 10.
 * @b: base.
 * @out: pointer to character array to be written to stdout.
 * @j: pointer to current index.
 * Return: nothing;
 */
void uoh(int b, unsigned int a, char *out, int *j)
{
	char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'a', 'b', 'c', 'd', 'e', 'f'}, *tmp;
	int index, i, swp;

	index = *j;
	i = 0, swp = 0;
	tmp = (char *) malloc(0);
	while (a != 0)
	{
		if (index == 0)
			out = (char *) realloc(out, SCHAR);
		else
		{
			tmp = (char *) realloc(tmp, SCHAR * i + SCHAR);
			out = (char *) realloc(out, SCHAR * index + SCHAR);
		}
		if (tmp != NULL && out != NULL)
		{
			tmp[i] = a % b;
			a /= b;
			index++, i++;
		}
		else
		{
			printf("realloc(): function failed\n");
			exit(1);
		}
	}
	*j = --index;
	while (swp < i)
	{
		out[index] = *(base_digits + tmp[swp]);
		swp++, index--;
	}
	free(tmp);
}
