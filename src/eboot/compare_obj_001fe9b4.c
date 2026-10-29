/* HSTMATCH module=EBOOT.BIN start=0x001fe9b4 end=0x001fea10 symbol=FUN_001fe9b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: simplified return branching; readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"

/* Returns 1 when the first words match and the following six words (from word 2) are equal. */
int FUN_001fe9b4(int *a, int *b)
{
    bool equal;
    int i;

    if (*a == *b) {
        equal = true;
        i = 0;
        do {
            if (a[2] != b[2]) {
                equal = false;
                break;
            }
            i = i + 1;
            b = b + 1;
            a = a + 1;
        } while (i < 6);

        if (equal) {
            return 1;
        }
    }
    return 0;
}
