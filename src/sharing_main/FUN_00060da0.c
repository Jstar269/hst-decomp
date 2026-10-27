/* HSTMATCH module=hstp_trans_main.prx start=0x00060da0 end=0x00060dc8 symbol=FUN_00060da0 lang=c99 */
/* Clone of src/eboot/FUN_0005ffb0.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int a, b, off; unsigned short c, n; };
char *FUN_00060da0(struct P *p) { if (p->n == 0) return 0; return (char *)p + p->c + p->off; }
