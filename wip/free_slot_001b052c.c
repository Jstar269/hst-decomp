/* HSTMATCH module=EBOOT.BIN start=0x001b052c end=0x001b0610 symbol=FUN_001b052c lang=c99 */
extern void FUN_00062418(int, int);

void FUN_001b052c(int *param_1, int param_2)
{
    int *piVar4;
    int *piVar2;
    int iVar3;
    int iVar1;

    piVar4 = (int *)(param_2 * 4 + (int)param_1) + 0x1da;
    if (param_1[param_2 + 0x1da] != 0) {
        piVar2 = param_1 + 0x1da;
        iVar3 = 0;
        if (piVar2 != param_1 + 0x1de) {
            do {
                if (*piVar2 == *piVar4) {
                    iVar3 = iVar3 + 1;
                }
                piVar2 = piVar2 + 1;
            } while (piVar2 != param_1 + 0x1de);
        }
        if (iVar3 < 2) {
            iVar3 = 0;
            piVar2 = param_1;
            do {
                if (*piVar2 == *piVar4) {
                    iVar1 = param_1[iVar3];
                    if (iVar1 != 0) {
                        FUN_00062418(iVar1, 1);
                        param_1[iVar3] = 0;
                    }
                    break;
                }
                iVar3 = iVar3 + 1;
                piVar2 = piVar2 + 1;
            } while (iVar3 < 0x1da);
        }
        *piVar4 = 0;
        *(char *)(param_2 + (int)param_1 + 0x798) = 0;
    }
}
// NEAR MISS (lane fm3): 57/57 words, 8 differ, two groups only:
//  (1) @0x1b0550 retail computes piVar4's base as `addu v1,v1,s2` (scaled index FIRST, base
//      second) where we always get `addu v1,s2,v1`; tried (int)param_1 + param_2*4,
//      param_2*4 + (int)param_1, (char *)param_1 + param_2*4 and ((int*)p)[param_2]-style
//      indexing -- mwcc canonicalises base-first for the plain addition form.
//  (2) the second (free) loop's scratch registers are swapped: retail keeps i in a2 and the pointer
//      in a1, we get i in a1 / p in a2. Reordering `iVar3 = 0; piVar2 = param_1;`, declaring the
//      pointer first, or introducing a fresh index local all leave it swapped.
// Shape that matters: piVar4 = (int *)(scaled_index + (int)param_1) + 0x1da (the offset add is
// folded as addiu, and the element test reloads through the *pre-add* base), the counting loop is a
// plain `do { if (*p == v) n++; p++; } while (p != end);` guarded by an outer `p != end` if, and the
// clearing loop is `do { if (*p == v) { if (param_1[i]) { FUN_00062418(..,1); param_1[i] = 0; }
// break; } i++; p++; } while (i < 0x1da);`.
// near miss from lane fm3 (unreviewed)
