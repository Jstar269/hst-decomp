/* HSTMATCH module=EBOOT.BIN start=0x00062a44 end=0x00062a6c symbol=FUN_00062a44 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int a, b; unsigned char on; int id; };
void FUN_00062a44(struct P *p, int id) { if (p->on && p->id == id) p->id = -1; }
