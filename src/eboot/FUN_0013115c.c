/* HSTMATCH module=EBOOT.BIN start=0x0013115c end=0x00131198 symbol=FUN_0013115c */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { char pad[0x78]; unsigned char busy; } Child78;
typedef struct { char pad[0x80]; Child78 *child; int pad84; int a; int b; } Parent80;
extern void FUN_0001f1fc(Child78 *c, int v);

void FUN_0013115c(Parent80 *p)
{
    FUN_0001f1fc(p->child, 0);
    p->child->busy = 0;
    p->a = 0;
    p->b = 0;
}
