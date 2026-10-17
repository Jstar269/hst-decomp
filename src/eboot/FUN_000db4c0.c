/* HSTMATCH module=EBOOT.BIN start=0x000db4c0 end=0x000db4e4 symbol=FUN_000db4c0 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad; int sub; } WithSub;
extern void FUN_000d9910(int *sub, int v);

void FUN_000db4c0(void *self, WithSub *w)
{
    if (w) FUN_000d9910(&w->sub, -1);
}
