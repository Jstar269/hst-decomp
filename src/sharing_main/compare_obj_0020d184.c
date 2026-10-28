/* HSTMATCH module=hstp_trans_main.prx start=0x0020d184 end=0x0020d1e0 symbol=FUN_0020d184 lang=c99 */
/* Clone of src/eboot/compare_obj_001fe9b4.c (hstclone.py tag u5fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: simplified return branching; exact match verified; names and types await human review. */

#include "hst/types.h"

int FUN_0020d184(int *param_1, int *param_2)
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
