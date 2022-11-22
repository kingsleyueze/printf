#include "main.h"

/**
 * check_ooh - function that calls the ooh function based on conditions.
 * @format: pointer to string to be written to stdout.
 * @out: pointer to character array to be written to stdout.
 * @a: number to be added to character array.
 * @i: pointer to index of @format.
 * @j: pointer to index of @out.
 * Return: nothing.
 */
void check_ooh(const char *format, char *out, unsigned int a, int *i, int *j)
{
	int caps, dest;

	caps = 0;
	dest = 'a' - 'A';

	if (format[*i + 1] == 'o')
	{
		ooh(8, a, out, j);
		*i += 1;
	}
	else if (format[*i + 1] == 'x' || format[*i + 1] == 'X')
	{
		if (format[*i + 1] == 'X')
			caps = *j;

		ooh(16, a, out, j);

		if (caps != 0)
		{
			for (; caps <= *j; caps++)
			{
				if (out[caps] >= 'a')
					out[caps] -= dest;
			}
		}

		*i += 1;
	}
}

/**
 * ooh - (octal or hexadecimal) function that adds unsigned octal or
 * hexadecimal numbers to character array pointed to by @b.
 * @a: number in base 10.
 * @b: base.
 * @out: pointer to character array to be written to stdout.
 * @j: pointer to index of @out.
 * Return: nothing;
 */
void ooh(int b, unsigned int a, char *out, int *j)
{
	char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'a', 'b', 'c', 'd', 'e', 'f'}, rev_arr[11];
	int index, i, swp;

	index = *j;
	i = 0, swp = 0;

	while (a != 0)
	{
		rev_arr[i] = a % b;
		a /= b;
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
			out[index] = *(base_digits + rev_arr[swp]);
			swp++;
			index--;
		}
	}
	else
		exit(1);
}
