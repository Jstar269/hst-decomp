/* HSTMATCH module=EBOOT.BIN start=0x001c8c00 end=0x001c8c14 symbol=FUN_001c8c00 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int *p; } IntIter;

IntIter *FUN_001c8c00(IntIter *it)
{
    it->p++;
    return it;
}
