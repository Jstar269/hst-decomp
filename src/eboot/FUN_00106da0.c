/* HSTMATCH module=EBOOT.BIN start=0x00106da0 end=0x00106dc0 symbol=FUN_00106da0 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern const char DAT_002c1098[], DAT_002c10a0[];

const char *FUN_00106da0(int a, int b)
{
    return b >= 0 ? DAT_002c10a0 : DAT_002c1098;
}
