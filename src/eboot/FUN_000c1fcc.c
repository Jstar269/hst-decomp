/* HSTMATCH module=EBOOT.BIN start=0x000c1fcc end=0x000c1fdc symbol=FUN_000c1fcc */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad; int value; } Counter;

void FUN_000c1fcc(Counter *c, int n)
{
    c->value -= n;
}
