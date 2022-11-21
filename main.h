#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdlib.h>
#include <stdarg.h>
#define SCHAR sizeof(char)

int _printf(const char *format, ...);
void di(int, char *, int *);
void ui(unsigned int, char *, int *);
void uoh(int, unsigned int, char *, int *);

#endif /* _MAIN_H_ */
