/* HSTMATCH module=hstp_trans_main.prx start=0x0019f9c8 end=0x0019fb6c symbol=FUN_0019f9c8 lang=c99 */
extern char *DAT_003eaa70;
extern int DAT_003eaa88;
extern int FUN_0019fb74(const char *);
extern void FUN_001a2d70(void *, int, void *);

void FUN_0019f9c8(int *param_1, int *param_2, const char *param_3)
{
    if (param_3 == 0) return;
    if (param_1 != 0) {
        switch ((unsigned char)param_3[51]) {
        default:
            *param_1 = 0;
            break;
        case 1: {
            const char *key = param_3 + 62;
            int res;
            if (DAT_003eaa70 != 0) {
                int it;
                FUN_001a2d70(&it, DAT_003eaa88 + 48, &key);
                if (it == DAT_003eaa88 + 52) {
                    res = 0;
                } else {
                    res = *(int *)(DAT_003eaa70 + 4) + *(int *)(it + 16) * 156;
                }
            } else {
                res = 0;
            }
            *param_1 = res;
            break;
        }
        case 2:
            *param_1 = FUN_0019fb74(param_3 + 62);
            break;
        }
    }
    if (param_2 == 0) return;
    switch ((unsigned char)param_3[52]) {
    default:
        *param_2 = 0;
        break;
    case 1: {
        const char *key = param_3 + 78;
        int res;
        if (DAT_003eaa70 != 0) {
            int it;
            FUN_001a2d70(&it, DAT_003eaa88 + 48, &key);
            if (it == DAT_003eaa88 + 52) {
                res = 0;
            } else {
                res = *(int *)(DAT_003eaa70 + 4) + *(int *)(it + 16) * 156;
            }
        } else {
            res = 0;
        }
        *param_2 = res;
        break;
    }
    case 2:
        *param_2 = FUN_0019fb74(param_3 + 78);
        break;
    }
}
// Near miss: 105/105 words matched (exact frame size 32, exact register allocation s0..s2).
// Discrepancy is branch delay slot scheduling at 0x19fa54: retail has non-likely beq with nop,
// while MWCC emits beql or bnel branch-likely forms.
// near miss from lane u6fr2-0 (unreviewed)
