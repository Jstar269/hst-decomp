/* HSTMATCH module=EBOOT.BIN start=0x001931b8 end=0x0019335c symbol=FUN_001931b8 lang=c99 */
extern char *DAT_00341730;
extern int DAT_00341748;
extern int FUN_00193364(const char *);
extern void FUN_00196478(void *, int, void *);

void FUN_001931b8(int *param_1, int *param_2, const char *param_3)
{
    if (param_3 == 0) return;
    if (param_1 != 0) {
        switch ((unsigned char)param_3[0x33]) {
        default:
            *param_1 = 0;
            break;
        case 1: {
            const char *key = param_3 + 0x3e;
            int res;
            if (DAT_00341730 != 0) {
                int it;
                FUN_00196478(&it, DAT_00341748 + 48, &key);
                if (it != DAT_00341748 + 52) {
                    res = *(int *)(DAT_00341730 + 4) + *(int *)(it + 16) * 156;
                } else {
                    res = 0;
                }
            } else {
                res = 0;
            }
            *param_1 = res;
            break;
        }
        case 2:
            *param_1 = FUN_00193364(param_3 + 0x3e);
            break;
        }
    }
    if (param_2 == 0) return;
    switch ((unsigned char)param_3[0x34]) {
    default:
        *param_2 = 0;
        break;
    case 1: {
        const char *key = param_3 + 0x4e;
        int res;
        if (DAT_00341730 != 0) {
            int it;
            FUN_00196478(&it, DAT_00341748 + 48, &key);
            if (it != DAT_00341748 + 52) {
                res = *(int *)(DAT_00341730 + 4) + *(int *)(it + 16) * 156;
            } else {
                res = 0;
            }
        } else {
            res = 0;
        }
        *param_2 = res;
        break;
    }
    case 2:
        *param_2 = FUN_00193364(param_3 + 0x4e);
        break;
    }
}
// rt2 2026-10-21: EBOOT twin of hstp 0x0019f9c8. Addresses: DAT 0x00341730, 0x00341748,
// FUN_00196478 (lookup helper), FUN_00193364 (getter), field offsets 0x33/0x3e, 0x34/0x4e.
// Best variant: `int res; if (it != end) res = <expr>; else res = 0; *p = res;` -> 101/105.
// Remaining 4 words (2 per half): retail lays out `beq it,end,ZERO; nop; <expr>; b STORE;
// addu; ZERO: move v1,zero; STORE: b END; sw v1,0(p)` i.e. plain (non-likely) beq over a
// 1-insn zero arm plus a shared store trampoline. MWCC 3.0.1 emits `beql ...; move v1,zero`
// and inlines the store, so the branch polarity and the trampoline both differ. Ruled out:
// `int res=0; if(...) res=...;` (moves res to s0, extra stack slots), ternary both
// polarities (bnel), reversed if/else arms (bnel), `if (it==end) res=0; else ...`.
// near miss from lane rt2 (unreviewed)
