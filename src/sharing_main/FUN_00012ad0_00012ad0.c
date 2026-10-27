/* HSTMATCH module=hstp_trans_main.prx start=0x00012ad0 end=0x00012b20 symbol=FUN_00012ad0 lang=c99 cc=gcc171-O2 */
/* Clone of src/eboot/FUN_00012ad0.c (hstclone.py tag a2c2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include <stdarg.h>
struct R { int a, b; void *out; }; extern struct R *FUN_0000fe3c(void); extern int FUN_00017dcc(void *fp, const char *fmt, va_list ap);
int FUN_00012ad0(const char *fmt, ...) { va_list ap; va_start(ap, fmt); return FUN_00017dcc(FUN_0000fe3c()->out, fmt, ap); }
