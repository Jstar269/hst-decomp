/* HSTMATCH module=EBOOT.BIN start=0x0000b3bc end=0x0000b3e0 symbol=FUN_0000b3bc lang=c99 cc=gcc171x-O2 */
/* Library source: newlib libm s_isnan.c function isnan (fdlibm-derived; Sun Microsystems, Inc. 1993, freely redistributable with this notice), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
typedef union { double d; struct { unsigned lo; int hi; } w; } D;
int FUN_0000b3bc(double x) { D u; int hx, lx; u.d = x; hx = u.w.hi; lx = u.w.lo; hx &= 0x7fffffff; hx |= (unsigned)(lx | (-lx)) >> 31; hx = 0x7ff00000 - hx; return (int)((unsigned)hx >> 31); }
