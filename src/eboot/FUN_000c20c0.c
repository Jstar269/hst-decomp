/* HSTMATCH module=EBOOT.BIN start=0x000c20c0 end=0x000c210c symbol=FUN_000c20c0 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern int DAT_002d5a8c;  /* selector, 0 to 2 */
extern float DAT_003412e8, DAT_003412f0, DAT_003412f8;  /* constants for selector 1, 0 and 2 */
/* Returns the float constant that belongs to the current selector (0.0f when it is out of range). */
float FUN_000c20c0(void)
{
    switch (DAT_002d5a8c) {
    case 1:
        return DAT_003412e8;
    case 0:
        return DAT_003412f0;
    case 2:
        return DAT_003412f8;
    }
    return 0.0f;
}
