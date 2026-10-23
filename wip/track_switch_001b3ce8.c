/* HSTMATCH module=EBOOT.BIN start=0x001b3ce8 end=0x001b3e2c symbol=FUN_001b3ce8 lang=c99 */
extern int DAT_002e515c[];
extern void FUN_00062904(int);
extern int FUN_000627e8(int, int);
extern int FUN_00062a6c(void);
extern void FUN_00062a9c(int, int, int);

void FUN_001b3ce8(int *param_1, unsigned int param_2)
{
    int self = *param_1;
    int v;
    float f;

    if (*(int *)(self + 0x7b0) < 0x1da) {
        if (*(int *)(self + *(int *)(self + 0x7b0) * 4) != 0) {
            if (*(int *)(self + 0x7ac) >= 0) {
                FUN_00062904(*(int *)(self + *(int *)(self + 0x7b0) * 4));
                *(int *)(self + 0x7ac) = -1;
            }
            *(int *)(self + 0x7b0) = 0x1da;
        }
    }
    if (param_2 < 0x32) {
        if ((int)param_2 < 0x1da && *(int *)(self + param_2 * 4) != 0) {
            *(unsigned int *)(self + 0x7b0) = param_2;
            v = FUN_000627e8(*(int *)(self + param_2 * 4), 0);
            *(int *)(self + 0x7ac) = v;
            f = (float)DAT_002e515c[param_2];
            if (v < 0 || FUN_00062a6c() == 0) {
                *(int *)(self + 0x7ac) = -1;
            } else {
                FUN_00062a9c(*(int *)(self + 0x7ac), (int)(f * 128.0f), (int)(f * 128.0f));
            }
        }
    }
}
// near miss: 68/81 words. Logic recovered: stop the current track (index at +0x7b0, guard < 0x1da
// and slot != 0, FUN_00062904 on the slot when +0x7ac >= 0, then reset +0x7b0 to 0x1da), then the
// new track when param_2 < 0x32 and its slot is non-zero: store it, FUN_000627e8(slot, 0) into
// +0x7ac and, unless that is negative or FUN_00062a6c() is 0, FUN_00062a9c(handle, v*128, v*128)
// with v from the DAT_002e515c volume table. Ours is 13 words short and keeps the +0x7b0 value in
// a register where retail re-loads it, so the guards collapse (`slti at` instead of `slti v1`).
// near miss from lane fm6 (unreviewed)
