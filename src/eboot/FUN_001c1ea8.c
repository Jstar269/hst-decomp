/* HSTMATCH module=EBOOT.BIN start=0x001c1ea8 end=0x001c1efc symbol=FUN_001c1ea8 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern unsigned char DAT_003420de[2][2];

int FUN_001c1ea8(int i, int j)
{
    if (i >= 0 && i < 2 && j >= 0 && j < 2) return DAT_003420de[i][j] != 0;
    return 0;
}
