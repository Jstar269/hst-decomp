/* HSTMATCH module=hstp_trans_main.prx start=0x001d7094 end=0x001d70a8 symbol=FUN_001d7094 */
/* Clone of src/eboot/FUN_001c8c00.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int *p; } IntIter;

IntIter *FUN_001d7094(IntIter *it)
{
    it->p++;
    return it;
}
