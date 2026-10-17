/* HSTMATCH module=EBOOT.BIN start=0x001fe9b4 end=0x001fea10 symbol=FUN_001fe9b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: simplified return branching; exact match verified; names and types await human review. */

typedef unsigned char bool;
#define true 1
#define false 0

int FUN_001fe9b4(int *param_1, int *param_2)
{
    bool bVar1;
    int iVar3;

    if (*param_1 == *param_2) {
        bVar1 = true;
        iVar3 = 0;
        do {
            if (param_1[2] != param_2[2]) {
                bVar1 = false;
                break;
            }
            iVar3 = iVar3 + 1;
            param_2 = param_2 + 1;
            param_1 = param_1 + 1;
        } while (iVar3 < 6);

        if (bVar1) {
            return 1;
        }
    }
    return 0;
}
