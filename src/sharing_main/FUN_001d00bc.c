/* HSTMATCH module=hstp_trans_main.prx start=0x001d00bc end=0x001d0110 symbol=FUN_001d00bc */
/* Clone of src/eboot/FUN_001c1ea8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
extern unsigned char DAT_003eb416[2][2];

int FUN_001d00bc(int i, int j)
{
    if (i >= 0 && i < 2 && j >= 0 && j < 2) return DAT_003eb416[i][j] != 0;
    return 0;
}
