#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - function to write output to stdout, the standard output stream.
 * @format: pointer to string to be written to stdout.
 * Return: the number of characters printed (excluding the null byte used to
 * end output to strings).
 */
int _printf(const char *format, ...)
{
	int i, j;
	char *out;
	va_list arglist;

	i = 0, j = 0, out = (char *) malloc(0), va_start(arglist, format);
	while (format[i])
	{
		out = (char *) realloc(out, SCHAR * j + SCHAR);
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				doi(va_arg(arglist, int), out, &i, &j);
			else if (format[i + 1] == 'u')
				ui(va_arg(arglist, unsigned int), out, &i, &j);
			else if (format[i + 1] == 'p')
				p(va_arg(arglist, long int), out, &i, &j);
			else if (format[i + 1] == 'b' || format[i + 1] == 'o' ||
					format[i + 1] == 'x' || format[i + 1] == 'X')
				check_boh(format, out, va_arg(arglist, unsigned int), &i, &j);
			else if (format[i + 1] == 'c')
				c(va_arg(arglist, int), out, &i, &j);
			else if (format[i + 1] == 's')
				s(va_arg(arglist, char *), out, &i, &j);
			else if (format[i + 1] == 'r')
				rs(va_arg(arglist, char *), out, &i, &j);
			else if (format[i + 1] == '%')
				out[j] = format[i], i++;
			else
				out[j] = format[i];
		}
		else
			out[j] = format[i];
		if (format[i + 1] == 0)
			out = (char *) realloc(out, SCHAR * j + SCHAR);
		i++, j++;
	}
	out[j] = '\0';
	va_end(arglist);
	write(1, out, j), free(out);
	return (j);
}
