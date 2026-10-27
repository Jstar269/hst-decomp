/* HSTMATCH module=EBOOT.BIN start=0x00051358 end=0x00051398 symbol=FUN_00051358 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct P { int a, h; }; extern char DAT_00311170[]; extern void FUN_0004fe04(char *s, int h); extern void FUN_00051118(struct P *p);
void FUN_00051358(struct P *p) { FUN_0004fe04(DAT_00311170, p->h); p->h = -1; FUN_00051118(p); }
