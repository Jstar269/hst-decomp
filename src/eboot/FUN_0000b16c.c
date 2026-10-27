/* HSTMATCH module=EBOOT.BIN start=0x0000b16c end=0x0000b178 symbol=FUN_0000b16c lang=c99 cc=gcc171x-O1 */
/* Library source: newlib libm s_fabs.c function fabs (fdlibm-derived; Sun Microsystems, Inc. 1993, freely redistributable with this notice), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
typedef union { double d; struct { unsigned lo, hi; } w; } D;
double FUN_0000b16c(double x) { D u; u.d = x; u.w.hi &= 0x7fffffff; return u.d; }
