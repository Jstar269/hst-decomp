/* HSTMATCH module=EBOOT.BIN start=0x00014438 end=0x000144b8 symbol=FUN_00014438 lang=c99 cc=gcc171-O2 */
/* Library source: newlib libc stdio sscanf.c function sscanf (BSD-derived; Regents of the University of California, BSD licence), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
#include <stdarg.h>
struct sbuf { unsigned char *_base; int _size; }; typedef struct sFILE { unsigned char *_p; int _r; int _w; short _flags; short _file; struct sbuf _bf; int _lbfsize; void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)(); struct sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; struct sbuf _lb; int _blksize; int _offset; void *_data; } FILE;
extern void *FUN_0000fe3c(void);
extern int FUN_00014a40(const char *s); extern int FUN_00014430(); extern int FUN_00019be8(void *r, FILE *fp, const char *fmt, va_list ap);
int FUN_00014438(const char *str, const char *fmt, ...) { int ret; va_list ap; FILE f; f._flags = 4; f._bf._base = f._p = (unsigned char *)str; f._bf._size = f._r = FUN_00014a40(str); f._read = FUN_00014430; f._ub._base = 0; f._lb._base = 0; va_start(ap, fmt); ret = FUN_00019be8(FUN_0000fe3c(), &f, fmt, ap); va_end(ap); return ret; }
