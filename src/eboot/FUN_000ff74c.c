/* HSTMATCH module=EBOOT.BIN start=0x000ff74c end=0x000ff760 symbol=FUN_000ff74c */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int a, b, c; } Triple;

Triple *FUN_000ff74c(Triple *t)
{
    t->a = 0;
    t->b = 0;
    t->c = 0;
    return t;
}
