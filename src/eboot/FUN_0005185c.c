/* HSTMATCH module=EBOOT.BIN start=0x0005185c end=0x00051894 symbol=FUN_0005185c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { char pad[36]; int a, b; }; extern int DAT_0032b17c; extern void FUN_0003cae8(int h, int x);
void FUN_0005185c(struct P *p) { FUN_0003cae8(DAT_0032b17c, p->b); p->b = 0; p->a = 0; }
