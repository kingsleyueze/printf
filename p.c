#include "main.h"

/**
 * p - (address) function that adds hexadecimal address to character array
 * pointed to by @out.
 * @a: address to be added to character array.
 * @out: pointer to character array to be written to stdout.
 * @k: pointer to current index of string to be written to stdout
 * @j: pointer to current index of @out.
 * Return: nothing.
 */
void p(long int a, char *out, int *k, int *j)
{
	if (*j == 0)
		out = (char *) realloc(out, SCHAR * 3);
	else
		out = (char *) realloc(out, SCHAR * (*j + 2));
	if (out != NULL)
	{
		out[*j] = '0';
		out[*j + 1] = 'x';
	}
	else
		exit(1);

	*j += 2;
	*k += 1;
	hp(a, out, j);
}

/**
 * hp - (hexadecimal address) function that adds hexadecimal address to
 * character array pointed to by @b.
 * @a: number in base 10.
 * @out: pointer to character array to be written to stdout.
 * @j: pointer to current index of @out.
 * Return: nothing;
 */
void hp(long int a, char *out, int *j)
{
	char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'a', 'b', 'c', 'd', 'e', 'f'}, rev_arr[64];
	int index, i, swp;

	index = *j;
	i = 0;
	swp = 0;

	while (a != 0)
	{
		rev_arr[i] = base_digits[a % 16];
		a /= 16;
		index++;
		i++;
	}
	*j = --index;

	if (index == 0)
		out = (char *) realloc(out, SCHAR);
	else
		out = (char *) realloc(out, SCHAR * index + SCHAR);
	if (out != NULL)
	{
		while (swp < i)
		{
			out[index] = rev_arr[swp];
			index--;
			swp++;
		}
	}
	else
		exit(1);
}
