/* HSTMATCH module=EBOOT.BIN start=0x002ad998 end=0x002ad9e8 symbol=FUN_002ad998 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the four accepted values with a single switch; readability pass; exact match verified; names and types await human review. */
extern int DAT_0034a678;
extern void FUN_002ad758(int, int, int);

/* Route 4 for modes 0, 0x2a, 0x31 and 0x44 (route 0 otherwise); the two arguments pass through. */
void FUN_002ad998(int arg1, int arg2)
{
    int route = 0;
    switch (DAT_0034a678) {
    case 0:
    case 0x2a:
    case 0x31:
    case 0x44:
        route = 4;
        break;
    }
    FUN_002ad758(route, arg1, arg2);
}
