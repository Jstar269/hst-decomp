/* HSTMATCH module=EBOOT.BIN start=0x001b42b8 end=0x001b4418 symbol=FUN_001b42b8 lang=c99 */
extern int DAT_002e515c[];
extern char *FUN_0022cd60(void);
extern void FUN_00062904(int);
extern int FUN_000627e8(int, int);
extern int FUN_00062a6c(int);
extern void FUN_00062a9c(int, int, int);

int FUN_001b42b8(int *param_1, unsigned int param_2)
{
    int self = *param_1;
    int cur = *(int *)(self + 0x7b8);
    int v;
    float f;

    if (param_2 == cur)
        return 0;
    if (cur < 0x1da) {
        if (*(int *)(self + cur * 4) != 0) {
            if (*(int *)(self + 0x7b4) >= 0) {
                FUN_00062904(*(int *)(self + cur * 4));
                *(int *)(self + 0x7b4) = -1;
            }
            *(int *)(self + 0x7b8) = 0x1da;
        }
    }
    if (*FUN_0022cd60() == 0)
        return 1;
    if (param_2 < 0x32) {
        if ((int)param_2 < 0x1da && *(int *)(self + param_2 * 4) != 0) {
            *(unsigned int *)(self + 0x7b8) = param_2;
            v = FUN_000627e8(*(int *)(self + param_2 * 4), 0);
            *(int *)(self + 0x7b4) = v;
            f = (float)DAT_002e515c[param_2];
            if (v < 0 || FUN_00062a6c(v) == 0) {
                *(int *)(self + 0x7b4) = -1;
            } else {
                FUN_00062a9c(*(int *)(self + 0x7b4), (int)(f * 128.0f), (int)(f * 128.0f));
            }
        }
    }
    return 1;
}
// near miss: 79/88 words. Logic recovered: early-out when param_2 equals the current +0x7b8,
// stop the old track (slot guard, FUN_00062904 when +0x7b4 >= 0, reset +0x7b8 to 0x1da), the
// FUN_0022cd60() byte gate returning 1, then the same start-track tail as 0x001b3ce8
// (FUN_000627e8 -> +0x7b4, DAT_002e515c volume, FUN_00062a6c check, FUN_00062a9c(handle,
// v*128, v*128)), returning 1. Ours is 9 words short and keeps the +0x7b8 value in a register
// where retail re-loads it.
// near miss from lane fm6 (unreviewed)
