/* HSTMATCH module=EBOOT.BIN start=0x0024de88 end=0x0024df74 symbol=FUN_0024de88 lang=c99 rodata=0x002ca5e8 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: switch table thresholds, early break/return idiom; readability pass; exact match verified; names and types await human review. */

/* Return 1 when count is enough for the given level (level 0 never passes, level 1 always does, levels 2..17 need 1..9). */
int FUN_0024de88(void *unused, int level, int count)
{
    switch (level) {
    case 0:
        break;
    case 1:
        return 1;
    case 2:
        if (count > 0) {
            return 1;
        }
        break;
    case 3:
    case 4:
        if (count >= 2) {
            return 1;
        }
        break;
    case 5:
    case 6:
        if (count >= 3) {
            return 1;
        }
        break;
    case 7:
        if (count >= 4) {
            return 1;
        }
        break;
    case 8:
    case 9:
    case 10:
        if (count >= 5) {
            return 1;
        }
        break;
    case 11:
        if (count >= 6) {
            return 1;
        }
        break;
    case 12:
    case 13:
        if (count >= 7) {
            return 1;
        }
        break;
    case 14:
    case 15:
        if (count >= 8) {
            return 1;
        }
        break;
    case 16:
    case 17:
        if (count >= 9) {
            return 1;
        }
        break;
    }
    return 0;
}
