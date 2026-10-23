/* HSTMATCH module=EBOOT.BIN start=0x001b5640 end=0x001b5740 symbol=FUN_001b5640 lang=c99 */
extern char *DAT_003386b0;
extern char DAT_0034179c[];
extern void FUN_001b2bb8(void *, int);

void FUN_001b5640(int param_1, int param_2)
{
    if (*(int *)(DAT_003386b0 + 0x3c) == 7) {
        if (param_2 == *(int *)(param_1 + 0xec))
            FUN_001b2bb8(DAT_0034179c, *(int *)(param_1 + 0xec));
    } else {
        short *p = *(short **)(param_2 * 4 + param_1 - 600);
        *p = *p + 1;
        p[2] = 0;
        if (param_2 == 0xc9 && p[1] <= *p) {
            int i = 0;
            *(int *)(param_1 + 0xec) = 0xc9;
            FUN_001b2bb8(DAT_0034179c, 0xc9);
            p[1] = p[1] + 1;
            char *q = (char *)param_1;
            do {
                i += 6;
                *(short *)(*(int *)(q + 0xa0)) = 0;
                *(short *)(*(int *)(q + 0xa4)) = 0;
                *(short *)(*(int *)(q + 0xa8)) = 0;
                *(short *)(*(int *)(q + 0xac)) = 0;
                *(short *)(*(int *)(q + 0xb0)) = 0;
                *(short *)(*(int *)(q + 0xb4)) = 0;
                q += 0x18;
            } while (i < 0x12);
        }
    }
}
// near miss: 65 vs 64 words; ours keeps the original parameter in s2 (32-byte frame with s2) while retail advances s1 only.
// near miss from lane fm6 (unreviewed)
