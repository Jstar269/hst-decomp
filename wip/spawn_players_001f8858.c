/* HSTMATCH module=EBOOT.BIN start=0x001f8858 end=0x001f898c symbol=FUN_001f8858 lang=c99 */
extern int DAT_003386b0;
extern void FUN_001f7f64(int);
extern int FUN_0008882c(int);

void FUN_001f8858(int param_1)
{
    int iVar1;
    int iVar2;
    unsigned int uVar3;
    int iVar4;
    int iVar5;

    *(unsigned char *)(param_1 + 0x5ae) = 0;
    *(int *)(param_1 + 0x524) = 6;
    *(int *)(param_1 + 0x534) = 0;
    *(int *)(param_1 + 0x538) = 0;
    iVar1 = FUN_0008882c(DAT_003386b0);
    iVar5 = 0;
    *(int *)(param_1 + 0x3c4) = *(int *)(iVar1 + 0x5bc);
    iVar1 = *(int *)(iVar1 + 0x144);
    iVar4 = 0;
    *(int *)(param_1 + 0x3d0) = -1;
    *(int *)(param_1 + 0x3d4) = -1;
    *(int *)(param_1 + 0x3d8) = -1;
    do {
        iVar2 = *(int *)(DAT_003386b0 + iVar4 + 0x70);
        if (iVar2 == 0 || *(int *)(iVar2 + 0x144) != iVar1) {
            if (iVar2 != 0) {
                if (*(int *)(param_1 + 0x3d4) == -1) {
                    *(int *)(param_1 + 0x3d4) = iVar5;
                } else if (*(int *)(param_1 + 0x3d4) != -1 && *(int *)(param_1 + 0x3d8) == -1) {
                    *(int *)(param_1 + 0x3d8) = iVar5;
                }
            }
        } else {
            iVar2 = *(int *)(iVar2 + 0x5bc);
            if (iVar2 == *(int *)(param_1 + 0x3c4)) {
                *(int *)(param_1 + 0x3cc) = iVar5;
            } else if (iVar2 != *(int *)(param_1 + 0x3c4)) {
                *(int *)(param_1 + 0x3c8) = iVar2;
                *(int *)(param_1 + 0x3d0) = iVar5;
            }
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 4;
    } while (iVar5 < 4);
    iVar1 = FUN_0008882c(DAT_003386b0);
    uVar3 = *(unsigned int *)(iVar1 + 0x144);
    *(unsigned int *)(param_1 + 0x3dc) = uVar3;
    *(unsigned int *)(param_1 + 0x3e0) = uVar3 ^ 1;
    *(unsigned char *)(param_1 + 0x5ae) = *(unsigned char *)(DAT_003386b0 + 0x5b);
    FUN_001f7f64(param_1);
}
// NEAR MISS (lane fm3): 63 of 77 words. Ours is right in every block (the 4-iteration do/while over
// DAT_003386b0+0x70+i*4, the 0x144 identity test, the 0x3d4/0x3d8 slot pick, the 0x3c4/0x3cc/0x3c8/
// 0x3d0 arms, the uVar3 / uVar3^1 pair and the final 0x5b byte), but the whole function is coloured
// differently because ours takes the ADDRESS of param_1+0x3d4 (`addiu a2,s0,980`) where retail
// re-loads the field with a plain `lw` each time it is tested. Retail's repeating
// `*(int *)(param_1 + 0x3d4) == -1` / `!= -1` tests are separate loads, so the source probably goes
// through a helper/inline getter or a volatile field; that is the next thing to try.
// near miss from lane fm3 (unreviewed)
