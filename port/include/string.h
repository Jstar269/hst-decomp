#ifndef HST_PORT_STRING_H
#define HST_PORT_STRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *memchr(const void *memory, int value, size_t count);
int memcmp(const void *left, const void *right, size_t count);
void *memcpy(void *destination, const void *source, size_t count);
void *memmove(void *destination, const void *source, size_t count);
void *memset(void *memory, int value, size_t count);
char *strcat(char *destination, const char *source);
char *strchr(const char *text, int character);
int strcmp(const char *left, const char *right);
int strcoll(const char *left, const char *right);
char *strcpy(char *destination, const char *source);
size_t strcspn(const char *text, const char *reject);
char *strerror(int error_number);
size_t strlen(const char *text);
char *strncat(char *destination, const char *source, size_t count);
int strncmp(const char *left, const char *right, size_t count);
char *strncpy(char *destination, const char *source, size_t count);
char *strpbrk(const char *text, const char *accept);
char *strrchr(const char *text, int character);
size_t strspn(const char *text, const char *accept);
char *strstr(const char *text, const char *find);
char *strtok(char *text, const char *delimiters);
size_t strxfrm(char *destination, const char *source, size_t count);

#ifdef __cplusplus
}
#endif

#endif
