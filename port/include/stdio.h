#ifndef HST_PORT_STDIO_H
#define HST_PORT_STDIO_H

#include <stddef.h>
#include <stdarg.h>

typedef struct __hst_port_FILE FILE;
typedef long long fpos_t;

#define EOF (-1)
#define BUFSIZ 1024
#define FILENAME_MAX 4096
#define FOPEN_MAX 16
#define TMP_MAX 32767
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#ifdef __cplusplus
extern "C" {
#endif

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

void clearerr(FILE *stream);
int fclose(FILE *stream);
int feof(FILE *stream);
int ferror(FILE *stream);
int fflush(FILE *stream);
int fgetc(FILE *stream);
char *fgets(char *buffer, int count, FILE *stream);
FILE *fopen(const char *filename, const char *mode);
int fprintf(FILE *stream, const char *format, ...);
int fputc(int character, FILE *stream);
int fputs(const char *text, FILE *stream);
size_t fread(void *buffer, size_t size, size_t count, FILE *stream);
FILE *freopen(const char *filename, const char *mode, FILE *stream);
int fscanf(FILE *stream, const char *format, ...);
int fseek(FILE *stream, long offset, int origin);
long ftell(FILE *stream);
size_t fwrite(const void *buffer, size_t size, size_t count, FILE *stream);
int getc(FILE *stream);
int getchar(void);
int printf(const char *format, ...);
int putc(int character, FILE *stream);
int putchar(int character);
int puts(const char *text);
int remove(const char *filename);
int rename(const char *old_name, const char *new_name);
void rewind(FILE *stream);
int scanf(const char *format, ...);
void setbuf(FILE *stream, char *buffer);
int setvbuf(FILE *stream, char *buffer, int mode, size_t size);
int sprintf(char *buffer, const char *format, ...);
int snprintf(char *buffer, size_t size, const char *format, ...);
int sscanf(const char *buffer, const char *format, ...);
FILE *tmpfile(void);
char *tmpnam(char *buffer);
int ungetc(int character, FILE *stream);
int vfprintf(FILE *stream, const char *format, va_list arguments);
int vprintf(const char *format, va_list arguments);
int vsprintf(char *buffer, const char *format, va_list arguments);
int vsnprintf(char *buffer, size_t size, const char *format, va_list arguments);

#ifdef __cplusplus
}
#endif

#endif
