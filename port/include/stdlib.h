#ifndef HST_PORT_STDLIB_H
#define HST_PORT_STDLIB_H

#include <stddef.h>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define RAND_MAX 32767

typedef struct { int quot; int rem; } div_t;
typedef struct { long quot; long rem; } ldiv_t;
typedef struct { long long quot; long long rem; } lldiv_t;

#ifdef __cplusplus
extern "C" {
#endif

void abort(void);
int abs(int value);
int atexit(void (*function)(void));
double atof(const char *text);
int atoi(const char *text);
long atol(const char *text);
long long atoll(const char *text);
void *bsearch(const void *key, const void *base, size_t count, size_t size,
              int (*compare)(const void *, const void *));
void *calloc(size_t count, size_t size);
div_t div(int numerator, int denominator);
void exit(int status);
void free(void *pointer);
char *getenv(const char *name);
long labs(long value);
ldiv_t ldiv(long numerator, long denominator);
long long llabs(long long value);
lldiv_t lldiv(long long numerator, long long denominator);
void *malloc(size_t size);
int mblen(const char *text, size_t count);
size_t mbstowcs(__WCHAR_TYPE__ *wide, const char *text, size_t count);
int mbtowc(__WCHAR_TYPE__ *wide, const char *text, size_t count);
void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *));
int rand(void);
void *realloc(void *pointer, size_t size);
void srand(unsigned int seed);
double strtod(const char *text, char **end);
float strtof(const char *text, char **end);
long strtol(const char *text, char **end, int base);
long long strtoll(const char *text, char **end, int base);
unsigned long strtoul(const char *text, char **end, int base);
unsigned long long strtoull(const char *text, char **end, int base);
int system(const char *command);
size_t wcstombs(char *text, const __WCHAR_TYPE__ *wide, size_t count);
int wctomb(char *text, __WCHAR_TYPE__ wide);

#ifdef __cplusplus
}
#endif

#endif
