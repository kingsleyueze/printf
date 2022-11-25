#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdlib.h>
#define SCHAR sizeof(char)

int _printf(const char *format, ...);
void doi(int, char *, int *, int *);
void ui(unsigned int, char *, int *, int *);
void check_boh(const char *, char *, unsigned int, int *, int*);
void boh(int,  unsigned int, char *, int *);
void p(long int, char *, int *, int *);
void hp(long int, char *, int *);
void c(int, char *, int *, int *);
void s(char *, char *, int *, int *);
void rs(char *, char *, int *, int *);

#endif /* _MAIN_H_ */
