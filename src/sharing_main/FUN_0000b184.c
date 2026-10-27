/* HSTMATCH module=hstp_trans_main.prx start=0x0000b184 end=0x0000b190 symbol=FUN_0000b184 lang=c99 cc=gcc171x-O1 */
/* Clone of src/eboot/FUN_0000b16c.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef union { double d; struct { unsigned lo, hi; } w; } D;
double FUN_0000b184(double x) { D u; u.d = x; u.w.hi &= 0x7fffffff; return u.d; }
