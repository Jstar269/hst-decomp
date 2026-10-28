/* HSTMATCH module=EBOOT.BIN start=0x002a5680 end=0x002a57ec symbol=FUN_002a5680 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: switch structure for mode dispatch, loop predicate variable, matching idiom (loop counter declared as parameter to steer s-register allocation); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034b354;
extern void FUN_000ffb3c(u32, int);
extern void FUN_0010b8cc(u32, int, int);
extern void FUN_00110a78(u32, u32, int);
extern void * FUN_001fea10(int, int, int);
extern void FUN_002a57ec(int, int, int);

void FUN_002a5680(int param_1, int param_2, int i)
{
    int eq;
    int p;

    i = 0;
    p = param_1;
    for (; i < 4; i++, p += 4) {
        eq = i == param_2;
        FUN_000ffb3c(*(u32 *)(p + 0x78), !eq);
        FUN_000ffb3c(*(u32 *)(p + 0x88), eq);
    }
    FUN_002a57ec(param_1, param_2, 0);
    FUN_0010b8cc(*(u32 *)(param_1 + 0xd4), param_2, 0);
    switch (param_2) {
    case 0:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 13), 0);
        break;
    case 1:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 14), 0);
        break;
    case 2:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 17), 0);
        break;
    case 3:
        FUN_00110a78(DAT_0034b354, (u32)FUN_001fea10(18, 49, 18), 0);
        break;
    }
}
