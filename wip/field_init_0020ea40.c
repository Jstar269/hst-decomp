/* HSTMATCH module=EBOOT.BIN start=0x0020ea40 end=0x0020ebb0 symbol=FUN_0020ea40 lang=c99 */
extern int DAT_002efa68[];
extern int DAT_0034a6b0;
extern int DAT_003486b0;
extern int FUN_00215a20(int);
extern void FUN_0020ebb0(int, int, int, int, int, int, int);
extern int FUN_0020f540(int, int, int);
extern int FUN_00215630(int, int);
extern float FUN_00210740(int, int, int);
extern float FUN_0020fbf0(int, int, int);

void FUN_0020ea40(int param_1)
{
    int i;
    int r;
    int base;

    for (i = 0; i < 3; i++) {
        if (*(int *)(param_1 + i * 4 + 0x8b4) <= 0) {
            base = FUN_00215a20(param_1) + i * 0x18;
            FUN_0020ebb0(param_1, param_1 + i * 4 + 0x8a8,
                         param_1 + i * 4 + 0x8b4,
                         DAT_0034a6b0 + i * 0xc,
                         base + 0xc4,
                         FUN_00215a20(param_1) + i * 0x18 + 0xd0,
                         DAT_002efa68[i]);
        }
        if (i != 0)
            continue;
        *(char *)(param_1 + 0x8a0) = 0;
        r = FUN_0020f540(param_1, *(int *)(param_1 + 0x8a8),
                         *(int *)(param_1 + 0x8b4));
        *(int *)(param_1 + 0x8e0) = r;
        *(int *)(param_1 + 0x8e0) = FUN_00215630(param_1, r);
    }
    *(float *)(param_1 + 0x8f0) = FUN_00210740(param_1, *(int *)(param_1 + 0x8b0),
                                               *(int *)(param_1 + 0x8bc));
    *(float *)(param_1 + 0x8f8) = FUN_0020fbf0(param_1, *(int *)(param_1 + 0x8ac),
                                               *(int *)(param_1 + 0x8b8));
    *(float *)(param_1 + 0x8f4) = -*(float *)(*(int *)(DAT_003486b0 + 0x88) + 0x110);
    *(int *)(param_1 + 0x8fc) = 0x7f7fffff;
    *(int *)(param_1 + 0x8b4) -= 1;
    *(int *)(param_1 + 0x8b8) -= 1;
    *(int *)(param_1 + 0x8bc) -= 1;
}
// near miss: 92/92 words, 13 differ -- only the saved-register roles are swapped: retail keeps the
// DAT_002efa68 induction pointer in s2 and the i*0x18 offset in s1, ours the reverse (so every
// `addu` operand order and the t2 load follow). Everything else matches, including the single
// `base = FUN_00215a20(param_1) + i*0x18` local feeding `base + 0xc4` while the +0xd0 argument
// calls FUN_00215a20 again (two separate calls in retail), the `if (i != 0) continue` guard, the
// double store to +0x8e0 (0x20f540's result then 0x215630(param_1, that result)), the negated
// +0x110 float into +0x8f4, 0x7f7fffff into +0x8fc and the three trailing decrements.
// near miss from lane fm6 (unreviewed)
