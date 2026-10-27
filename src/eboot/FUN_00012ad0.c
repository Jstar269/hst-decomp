/* HSTMATCH module=EBOOT.BIN start=0x00012ad0 end=0x00012b20 symbol=FUN_00012ad0 lang=c99 cc=gcc171-O2 */
/* Library source: newlib libc stdio printf.c function printf (BSD-derived; Regents of the University of California, BSD licence), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
#include <stdarg.h>
struct R { int a, b; void *out; }; extern struct R *FUN_0000fe3c(void); extern int FUN_00017dcc(void *fp, const char *fmt, va_list ap);
int FUN_00012ad0(const char *fmt, ...) { va_list ap; va_start(ap, fmt); return FUN_00017dcc(FUN_0000fe3c()->out, fmt, ap); }
