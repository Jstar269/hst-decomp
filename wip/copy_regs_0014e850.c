/* HSTMATCH module=EBOOT.BIN start=0x0014e850 end=0x0014e958 symbol=FUN_0014e850 lang=c99 */
extern unsigned char DAT_003402f0;
extern char DAT_002dc240[];
extern char DAT_002dc24c[];
extern char DAT_002dc334[];
extern char DAT_00340314[];
extern char DAT_003402f4[];
extern int FUN_0014c610(char *, ...);

int FUN_0014e850(char *param_1, int *param_2)
{
    int regs[8];
    int i;
    int c;
    int v;

    if (DAT_003402f0 != 0) {
        switch (DAT_003402f0) {
        case 0:
            c = *(char *)(param_1 + 0xf);
            break;
        default:
            param_1 = (char *)FUN_0014c610(DAT_002dc240);
            for (i = 0; i < param_2[6] + 1; i++)
                param_1 = (char *)FUN_0014c610(DAT_002dc24c);
            c = *(char *)(param_1 + 0xf);
            break;
        }
        FUN_0014c610(DAT_002dc334, *(char *)(param_1 + 8), *(char *)(param_1 + 9),
                     *(char *)(param_1 + 10), *(char *)(param_1 + 0xb),
                     *(char *)(param_1 + 0xc), *(char *)(param_1 + 0xd),
                     *(char *)(param_1 + 0xe), c);
    }
    for (i = 0; i < 8; i++) {
        v = *(char *)(param_1 + i + 8);
        if (v < 0)
            v = i;
        regs[i] = *(int *)(DAT_00340314 + v * 4);
    }
    for (i = 0; i < 8; i++)
        *(int *)(DAT_003402f4 + 0x20 + i * 4) = regs[i];
    return 0;
}
// near miss: 90/66 words -- the script-debug block is over-built (retail's is a switch with a
// single inlined pass over param_2[6] + 1 lines, ours duplicates the CopyReg setup). Shape that is
// confirmed: 8 signed register bytes at param_1+8..+0xf remapped through DAT_00340314 with the
// negative -> index fallback, stored into DAT_003402f4+0x20, and FUN_0014c610's CopyReg format
// taking the eight register bytes.
// near miss from lane fm6 (unreviewed)
