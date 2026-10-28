/* HSTMATCH module=hstp_trans_main.prx start=0x00192ac4 end=0x00192ce8 symbol=FUN_00192ac4 lang=c99 */
/* Clone of src/eboot/update_slot_flags_00186378.c (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: 3-way mode switch with case-scoped loop induction variables, Table5 struct copy, pragma opt_strength_reduction off for indexed access; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

#include "hst/types.h"

typedef struct {
    int v[5];
} Table5;

extern Table5 DAT_00388008;
extern void FUN_00105470(u32, int);
extern int FUN_00177e98(void);

void FUN_00192ac4(int param_1)
{
    int *base1 = (int *)(FUN_00177e98() + 0x588);
    Table5 tab = DAT_00388008;

    switch (*(int *)(FUN_00177e98() + 0x584)) {
    case 1: {
        int i;
        int off;
        const int *pTab;

        i = 0;
        off = 0;
        pTab = tab.v;
        for (; i < 5; i++, off += 20, pTab++) {
            int off1 = off + 1420;
            char *p = (char *)param_1 + off1;
            u32 *puVar3 = (u32 *)(p + 8052);
            if (base1[*pTab] > 0) {
                FUN_00105470(*puVar3, 0);
            } else {
                FUN_00105470(*puVar3, 1);
            }
        }
        break;
    }
    case 2: {
        int i;
        int j;
        const int *pTab;
        int idx;

        i = 0;
        pTab = tab.v;
        for (; i < 5; i++, pTab++) {
            j = 0;
            idx = i + 78;
            for (; j < 2; j++, idx += 5) {
                u32 *puVar3 = (u32 *)((char *)param_1 + idx * 20 + 8052);
                if (base1[*pTab] >= j + 1) {
                    FUN_00105470(*puVar3, 0);
                } else {
                    FUN_00105470(*puVar3, 1);
                }
            }
        }
        break;
    }
    case 3: {
        int i;
        int j;
        const int *pTab;
        int idx;

        i = 0;
        pTab = tab.v;
        for (; i < 5; i++, pTab++) {
            j = 0;
            idx = i + 91;
            for (; j < 3; j++, idx += 5) {
                u32 *puVar3 = (u32 *)((char *)param_1 + idx * 20 + 8052);
                if (base1[*pTab] >= j + 1) {
                    FUN_00105470(*puVar3, 0);
                } else {
                    FUN_00105470(*puVar3, 1);
                }
            }
        }
        break;
    }
    }
}
