/* HSTMATCH module=EBOOT.BIN start=0x0000bcfc end=0x0000bd10 symbol=FUN_0000bcfc lang=c99 cc=gcc171x-O2 */
/* Library source: newlib libm sf_fabs.c function fabsf (fdlibm-derived; Sun Microsystems, Inc. 1993, freely redistributable with this notice), adapted by hand from the newlib source, newlib version not recorded; exact match verified; names and types await human review. */
typedef union { float f; unsigned w; } F;
float FUN_0000bcfc(float x) { F u; u.f = x; u.w &= 0x7fffffff; return u.f; }
