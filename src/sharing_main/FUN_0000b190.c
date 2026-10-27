/* HSTMATCH module=hstp_trans_main.prx start=0x0000b190 end=0x0000b1a4 symbol=FUN_0000b190 lang=c99 cc=gcc171x-O2 */
/* Clone of src/eboot/FUN_0000b178.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef union { double d; struct { unsigned lo; int hi; } w; } D;
int FUN_0000b190(double x) { D u; int hx; u.d = x; hx = u.w.hi; return (int)((unsigned)((hx & 0x7fffffff) - 0x7ff00000) >> 31); }
