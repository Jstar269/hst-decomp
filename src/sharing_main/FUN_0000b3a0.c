/* HSTMATCH module=hstp_trans_main.prx start=0x0000b3a0 end=0x0000b3d4 symbol=FUN_0000b3a0 lang=c99 cc=gcc171x-O2 */
/* Clone of src/eboot/FUN_0000b388.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef union { double d; struct { unsigned lo; int hi; } w; } D;
int FUN_0000b3a0(double x) { D u; int hx, lx; u.d = x; hx = u.w.hi; lx = u.w.lo; hx &= 0x7fffffff; hx |= (unsigned)(lx | (-lx)) >> 31; hx = 0x7ff00000 - hx; return 1 - (int)((unsigned)(hx | (-hx)) >> 31); }
