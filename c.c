#include "main.h"

/**
 * c - (character) function that adds a character to character array pointed to
 * by @out.
 * @a: numeric value of character.
 * @out: pointer to character array to be written to stdout.
 * @k: pointer to current index of string to be written to stdout.
 * @j: pointer to current index of @out.
 * Return: nothing.
 */
void c(int a, char *out, int *k, int *j)
{
	if (*j == 0)
		out = (char *) realloc(out, SCHAR);
	else
		out = (char *) realloc(out, SCHAR * (*j));
	if (out != NULL)
		out[*j] = a;
	else
		exit(1);
	*k += 1;
}
