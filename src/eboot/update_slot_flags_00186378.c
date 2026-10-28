/* HSTMATCH module=EBOOT.BIN start=0x00186378 end=0x0018659c symbol=FUN_00186378 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: 3-way mode switch with case-scoped loop induction variables, Table5 struct copy, pragma opt_strength_reduction off for indexed access; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off

#include "hst/types.h"

typedef struct {
    int v[5];
} Table5;

extern Table5 DAT_002e0988;
extern void FUN_000ffb3c(u32, int);
extern int FUN_0016bc70(void);

void FUN_00186378(int param_1)
{
    int *base1 = (int *)(FUN_0016bc70() + 0x588);
    Table5 tab = DAT_002e0988;

    switch (*(int *)(FUN_0016bc70() + 0x584)) {
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
                FUN_000ffb3c(*puVar3, 0);
            } else {
                FUN_000ffb3c(*puVar3, 1);
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
                    FUN_000ffb3c(*puVar3, 0);
                } else {
                    FUN_000ffb3c(*puVar3, 1);
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
                    FUN_000ffb3c(*puVar3, 0);
                } else {
                    FUN_000ffb3c(*puVar3, 1);
                }
            }
        }
        break;
    }
    }
}
