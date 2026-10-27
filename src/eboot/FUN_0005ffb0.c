/* HSTMATCH module=EBOOT.BIN start=0x0005ffb0 end=0x0005ffd8 symbol=FUN_0005ffb0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int a, b, off; unsigned short c, n; };
char *FUN_0005ffb0(struct P *p) { if (p->n == 0) return 0; return (char *)p + p->c + p->off; }
