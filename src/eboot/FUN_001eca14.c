/* HSTMATCH module=EBOOT.BIN start=0x001eca14 end=0x001eca5c symbol=FUN_001eca14 */
/* Hand-written reconstruction (early session work from before provenance notes were recorded; it may have started from Ghidra pseudocode); exact match verified; names and types await human review. */
typedef struct { int pad[3]; int kind; } Kinded;

int FUN_001eca14(Kinded *k)
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
