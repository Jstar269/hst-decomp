/* HSTMATCH module=EBOOT.BIN start=0x001b46bc end=0x001b47d8 symbol=FUN_001b46bc lang=c99 */
extern float DAT_002e515c[];
extern void FUN_00062904(int);
extern int FUN_000627e8(int, int);
extern int FUN_00062a6c();
extern void FUN_00062a9c(int, int, int);

void FUN_001b46bc(int *param_1)
{
    int bVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    float fVar5;

    iVar4 = *param_1;
    bVar1 = *(int *)(iVar4 + 0x7c8) < 0x1da;
    if (bVar1 != 0) {
        bVar1 = *(int *)(iVar4 + *(int *)(iVar4 + 0x7c8) * 4) != 0;
    }
    if (bVar1 != 0) {
        if (*(int *)(iVar4 + 0x7c4) >= 0) {
            FUN_00062904(*(int *)(iVar4 + *(int *)(iVar4 + 0x7c8) * 4));
            *(int *)(iVar4 + 0x7c4) = -1;
        }
    }
    iVar3 = *(int *)(iVar4 + 0x7c8);
    bVar1 = iVar3 < 0x1da;
    if (bVar1 != 0) {
        bVar1 = *(int *)(iVar4 + iVar3 * 4) != 0;
    }
    if (bVar1 != 0) {
        iVar2 = FUN_000627e8(*(int *)(iVar4 + iVar3 * 4), 0);
        *(int *)(iVar4 + 0x7c4) = iVar2;
        fVar5 = DAT_002e515c[iVar3];
        if (iVar2 < 0 || (iVar3 = FUN_00062a6c(), iVar3 == 0)) {
            *(int *)(iVar4 + 0x7c4) = -1;
            bVar1 = 0;
        } else {
            bVar1 = 1;
        }
        if (bVar1 != 0) {
            FUN_00062a9c(*(int *)(iVar4 + 0x7c4), (int)(fVar5 * 128.0f), (int)(fVar5 * 128.0f));
        }
    }
}
// NEAR MISS (lane fm3): twin of wip/start_sound_001b4530.c with the index/state fields shifted to
// 0x7c8 / 0x7c4; identical near-miss shape (one-word shift from a missing nop after the bltz, a1 vs
// v1 for the state field). Same fixes apply.
// near miss from lane fm3 (unreviewed)
