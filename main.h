#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdlib.h>
#define SCHAR sizeof(char)

int _printf(const char *format, ...);
void doi(int, char *, int *, int *);
void ui(unsigned int, char *, int *, int *);
void check_ooh(const char *, char *, unsigned int, int *, int*);
void ooh(int, unsigned int, char *, int *);
void c(int, char *, int *, int *);
void s(char *, char *, int *, int *);

#endif /* _MAIN_H_ */
