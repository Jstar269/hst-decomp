/* HSTMATCH module=hstp_trans_main.prx start=0x000143b0 end=0x00014430 symbol=FUN_000143b0 lang=c99 cc=gcc171-O2 */
/* Clone of src/eboot/FUN_000143b0.c (hstclone.py tag a2c3s): addresses substituted; exact match verified; names and types await human review. */
/* Library source: newlib libc stdio sprintf.c function sprintf (BSD-derived; Regents of the University of California, BSD licence), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
#include <stdarg.h>
struct sbuf { unsigned char *_base; int _size; }; typedef struct sFILE { unsigned char *_p; int _r; int _w; short _flags; short _file; struct sbuf _bf; int _lbfsize; void *_cookie; int (*_read)(); int (*_write)(); int (*_seek)(); int (*_close)(); struct sbuf _ub; unsigned char *_up; int _ur; unsigned char _ubuf[3]; unsigned char _nbuf[1]; struct sbuf _lb; int _blksize; int _offset; void *_data; } FILE;
extern void *FUN_0000fe3c(void);
extern int FUN_00017e48(void *r, FILE *fp, const char *fmt, va_list ap);
int FUN_000143b0(char *str, const char *fmt, ...) { int ret; va_list ap; FILE f; f._flags = 0x208; f._bf._base = f._p = (unsigned char *)str; f._bf._size = f._w = 0x7fffffff; f._file = -1; va_start(ap, fmt); ret = FUN_00017e48(FUN_0000fe3c(), &f, fmt, ap); va_end(ap); *f._p = 0; return ret; }
