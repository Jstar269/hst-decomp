/* HSTMATCH module=hstp_trans_main.prx start=0x0000bd14 end=0x0000bd28 symbol=FUN_0000bd14 lang=c99 cc=gcc171x-O2 */
/* Clone of src/eboot/FUN_0000bcfc.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef union { float f; unsigned w; } F;
float FUN_0000bd14(float x) { F u; u.f = x; u.w &= 0x7fffffff; return u.f; }
