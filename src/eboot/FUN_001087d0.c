/* HSTMATCH module=EBOOT.BIN start=0x001087d0 end=0x001087e0 symbol=FUN_001087d0 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad; int value; } Counter;

void FUN_001087d0(Counter *c, int n)
{
    c->value -= n;
}
