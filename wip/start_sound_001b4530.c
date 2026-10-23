/* HSTMATCH module=EBOOT.BIN start=0x001b4530 end=0x001b464c symbol=FUN_001b4530 lang=c99 */
extern float DAT_002e515c[];
extern void FUN_00062904(int);
extern int FUN_000627e8(int, int);
extern int FUN_00062a6c();
extern void FUN_00062a9c(int, int, int);

void FUN_001b4530(int *param_1)
{
    int bVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    float fVar5;

    iVar4 = *param_1;
    bVar1 = *(int *)(iVar4 + 0x7c0) < 0x1da;
    if (bVar1 != 0) {
        bVar1 = *(int *)(iVar4 + *(int *)(iVar4 + 0x7c0) * 4) != 0;
    }
    if (bVar1 != 0) {
        if (*(int *)(iVar4 + 0x7bc) >= 0) {
            FUN_00062904(*(int *)(iVar4 + *(int *)(iVar4 + 0x7c0) * 4));
            *(int *)(iVar4 + 0x7bc) = -1;
        }
    }
    iVar3 = *(int *)(iVar4 + 0x7c0);
    bVar1 = iVar3 < 0x1da;
    if (bVar1 != 0) {
        bVar1 = *(int *)(iVar4 + iVar3 * 4) != 0;
    }
    if (bVar1 != 0) {
        iVar2 = FUN_000627e8(*(int *)(iVar4 + iVar3 * 4), 0);
        *(int *)(iVar4 + 0x7bc) = iVar2;
        fVar5 = DAT_002e515c[iVar3];
        if (iVar2 < 0 || (iVar3 = FUN_00062a6c(), iVar3 == 0)) {
            *(int *)(iVar4 + 0x7bc) = -1;
            bVar1 = 0;
        } else {
            bVar1 = 1;
        }
        if (bVar1 != 0) {
            FUN_00062a9c(*(int *)(iVar4 + 0x7bc), (int)(fVar5 * 128.0f), (int)(fVar5 * 128.0f));
        }
    }
}
// NEAR MISS (lane fm3): 23 of 71 words, and after the first block every one of them is a one-word
// shift: retail has a `nop` after `bltz a1,exit` (0xb1b4578) that we never emit, so the whole tail is
// offset by one instruction; the instruction sequence itself matches (only a1 vs v1 for the 0x7bc
// value). What is already right and should be kept: bVar1 must be an `int` (a bool/u8 gives
// `andi 0xff` and loses the sltu), each flag is `bVar1 = (idx < 0x1da); if (bVar1) bVar1 = *(int *)
// (iVar4 + idx*4) != 0;` (NOT `bVar1 = a && b`, which materialises a 0/1 into a1, and NOT
// `bVar1 = 0; if (c) bVar1 = ..`, which puts `move v1,zero` in the branch delay), the 0x7bc test is
// `>= 0` (bltz, not `-1 <`, which gives slti at), DAT_002e515c is a float array read before the
// FUN_00062a6c call, and the `int)(fVar5*128.0f)` pair is computed once into a1 and copied to a2.
// near miss from lane fm3 (unreviewed)
