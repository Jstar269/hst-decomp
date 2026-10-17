/* HSTMATCH module=EBOOT.BIN start=0x002ad998 end=0x002ad9e8 symbol=FUN_002ad998 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the four accepted values with a single switch; exact match verified; names and types await human review. */

extern int DAT_0034a678;
extern void FUN_002ad758(int, int, int);

void FUN_002ad998(int param_1, int param_2)
{
    int val = 0;
    switch (DAT_0034a678) {
    case 0:
    case 0x2a:
    case 0x31:
    case 0x44:
        val = 4;
        break;
    }
    FUN_002ad758(val, param_1, param_2);
}
