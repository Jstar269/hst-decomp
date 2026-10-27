/* HSTMATCH module=EBOOT.BIN start=0x0000b178 end=0x0000b18c symbol=FUN_0000b178 lang=c99 cc=gcc171x-O2 */
/* Library source: newlib libm s_finite.c function finite (fdlibm-derived; Sun Microsystems, Inc. 1993, freely redistributable with this notice), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
typedef union { double d; struct { unsigned lo; int hi; } w; } D;
int FUN_0000b178(double x) { D u; int hx; u.d = x; hx = u.w.hi; return (int)((unsigned)((hx & 0x7fffffff) - 0x7ff00000) >> 31); }
