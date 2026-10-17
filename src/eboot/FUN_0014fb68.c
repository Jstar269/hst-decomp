/* HSTMATCH module=EBOOT.BIN start=0x0014fb68 end=0x0014fba8 symbol=FUN_0014fb68 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad0, pad4; int a; int b; } Src14f;
typedef struct { int pad0, pad4, pad8; void *h; } Dst14f;
extern void FUN_00286f00(void *h, int a1, int a2, int a3, int a4, int a5, int a6, int a7);

int FUN_0014fb68(Src14f *s, Dst14f *d)
{
    FUN_00286f00(d->h, 0, 0, 0, s->a, s->b, 0, 0);
    return 0;
}
