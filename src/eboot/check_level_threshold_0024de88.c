/* HSTMATCH module=EBOOT.BIN start=0x0024de88 end=0x0024df74 symbol=FUN_0024de88 lang=c99 rodata=0x002ca5e8 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: switch table thresholds, early break/return idiom; exact match verified; names and types await human review. */

int FUN_0024de88(void *unused, int param_2, int param_3)
{
    switch (param_2) {
    case 0:
        break;
    case 1:
        return 1;
    case 2:
        if (param_3 > 0) {
            return 1;
        }
        break;
    case 3:
    case 4:
        if (param_3 >= 2) {
            return 1;
        }
        break;
    case 5:
    case 6:
        if (param_3 >= 3) {
            return 1;
        }
        break;
    case 7:
        if (param_3 >= 4) {
            return 1;
        }
        break;
    case 8:
    case 9:
    case 10:
        if (param_3 >= 5) {
            return 1;
        }
        break;
    case 11:
        if (param_3 >= 6) {
            return 1;
        }
        break;
    case 12:
    case 13:
        if (param_3 >= 7) {
            return 1;
        }
        break;
    case 14:
    case 15:
        if (param_3 >= 8) {
            return 1;
        }
        break;
    case 16:
    case 17:
        if (param_3 >= 9) {
            return 1;
        }
        break;
    }
    return 0;
}
