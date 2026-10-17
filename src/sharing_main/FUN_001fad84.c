/* HSTMATCH module=hstp_trans_main.prx start=0x001fad84 end=0x001fadcc symbol=FUN_001fad84 */
/* Clone of src/eboot/FUN_001eca14.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad[3]; int kind; } Kinded;

int FUN_001fad84(Kinded *k)
{
    switch (k->kind) {
    case 6:
    case 7:
    case 9:
    case 10:
        return 1;
    }
    return 0;
}
