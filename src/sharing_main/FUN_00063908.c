/* HSTMATCH module=hstp_trans_main.prx start=0x00063908 end=0x00063930 symbol=FUN_00063908 lang=c99 */
/* Clone of src/eboot/FUN_00062a44.c (hstclone.py tag a2c1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int a, b; unsigned char on; int id; };
void FUN_00063908(struct P *p, int id) { if (p->on && p->id == id) p->id = -1; }
