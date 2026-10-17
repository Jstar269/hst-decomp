/* HSTMATCH module=EBOOT.BIN start=0x0010b564 end=0x0010b5a4 symbol=FUN_0010b564 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern void FUN_00101c18(void *a, int b);
extern void FUN_0010b150(void *a);

void FUN_0010b564(void *a, int b)
{
    FUN_00101c18(a, b);
    if (b == 0) FUN_0010b150(a);
}
