/* HSTMATCH module=EBOOT.BIN start=0x001b3f24 end=0x001b4074 symbol=FUN_001b3f24 lang=c99 */
extern int DAT_002e515c[];
extern void FUN_00062904(int);
extern int FUN_000627e8(int, int);
extern int FUN_00062a6c(int);
extern void FUN_00062a9c(int, int, int);

int FUN_001b3f24(int *param_1)
{
    int self = *param_1;
    int cur = *(int *)(self + 0x7b0);
    unsigned int want = *(int *)(self + 0x7a4) + 0x28;
    int v;
    float f;

    if (want == cur)
        return 0;
    if (cur < 0x1da) {
        if (*(int *)(self + cur * 4) != 0) {
            if (*(int *)(self + 0x7ac) >= 0) {
                FUN_00062904(*(int *)(self + cur * 4));
                *(int *)(self + 0x7ac) = -1;
            }
            *(int *)(self + 0x7b0) = 0x1da;
        }
    }
    if (want < 0x32) {
        if ((int)want < 0x1da && *(int *)(self + want * 4) != 0) {
            *(unsigned int *)(self + 0x7b0) = want;
            v = FUN_000627e8(*(int *)(self + want * 4), 0);
            *(int *)(self + 0x7ac) = v;
            f = (float)DAT_002e515c[want];
            if (v < 0 || FUN_00062a6c(v) == 0) {
                *(int *)(self + 0x7ac) = -1;
            } else {
                FUN_00062a9c(*(int *)(self + 0x7ac), (int)(f * 128.0f), (int)(f * 128.0f));
            }
        }
    }
    return 1;
}
// near miss: 74/84 words. Logic recovered: want = +0x7a4 + 0x28, early-out when it equals the
// current +0x7b0, stop the old track (slot guard, FUN_00062904 when +0x7ac >= 0, reset +0x7b0),
// then the start-track tail (FUN_000627e8 -> +0x7ac, DAT_002e515c volume, FUN_00062a6c check,
// FUN_00062a9c(handle, v*128, v*128)) and return 1. Ours is 10 words short, same register
// lifetime difference as the 0x001b3ce8/0x001b42b8 twins (retail re-loads +0x7b0 for each guard,
// ours caches it).
// near miss from lane fm6 (unreviewed)
