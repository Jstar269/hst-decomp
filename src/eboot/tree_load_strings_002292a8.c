/* HSTMATCH module=EBOOT.BIN start=0x002292a8 end=0x002293d4 symbol=FUN_002292a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed FUN_002293d4(param_1) delay-slot save, Pair local layout at 36(sp), and branch structure; exact match verified; names and types await human review. */

#include "hst/types.h"

extern void FUN_000009e4(u32);
extern u32 FUN_00000a90(int);
extern void FUN_000104e0(void *);
extern void *FUN_000149a8(u32, void *);
extern int FUN_00014a40(void *);
extern void *FUN_0004cad0(int, int *, int, int);
extern void FUN_002293d4(int);
extern void FUN_00229868(void *, int, void *);
extern void FUN_0022999c(void *, int, void *);

struct Pair {
    u32 key;
    int val;
};

int FUN_002292a8(int param_1, int param_2)
{
    int local_4;
    u32 local_8;
    int local_c;
    u8 auStack_14[8];
    struct Pair local_pair;

    FUN_002293d4(param_1);
    int *piVar1 = (int *)FUN_0004cad0(param_2, &local_4, 16, 1);
    if (piVar1 == 0 || local_4 <= 0) {
        return 0;
    }
    *(u8 *)(local_4 + (int)piVar1 + -1) = 0;

    int count = *piVar1;
    int *piVar7 = piVar1 + 1;
    int i = 0;

    if (count > 0) {
        do {
            int iVar3 = *piVar7++;
            void *str = (char *)piVar1 + iVar3;
            int slen = FUN_00014a40(str);
            local_8 = FUN_00000a90(slen + 1);
            FUN_000149a8(local_8, str);

            FUN_00229868(&local_c, param_1, &local_8);
            if (local_c != param_1 + 4) {
                FUN_000009e4(local_8);
            } else {
                local_pair.key = local_8;
                local_pair.val = i;
                FUN_0022999c(auStack_14, param_1, &local_pair);
            }
            i++;
        } while (i < count);
    }

    FUN_000104e0(piVar1);
    return 1;
}
