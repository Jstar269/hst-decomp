/* HSTMATCH module=hstp_trans_main.prx start=0x000dfb00 end=0x000dfc24 symbol=FUN_000dfb00 lang=c99 */

extern const char DAT_003eaaf0[];
extern int FUN_000e30f8(void *);

int FUN_000dfb00(void *param_1)
{
    int ok = 1;
    for (int i = 0; i < 2; i++) {
        if (*(int *)((char *)param_1 + 0x8c) != 0) {
            ok = 0;
            break;
        }
    }

    if (!ok) {
        ok = 0;
    } else {
        const char *p = DAT_003eaaf0;
        int i = 0;
        for (; i < 2; i++) {
            int v = FUN_000e30f8(param_1) ? 0 : (unsigned char)p[0xe3];
            if (*(int *)((char *)param_1 + 0xd0 + i * 4) != v) {
                ok = 0;
                break;
            }
            p += 0x120;
        }
    }

    if (ok) {
        int i = 0;
        for (; i < 2; i++) {
            if (*(int *)((char *)param_1 + 0xc4 + i * 4) != 0) {
                ok = 0;
                break;
            }
        }
    } else {
        ok = 0;
    }

    if (ok) {
        int i = 0;
        for (; i < 2; i++) {
            if (*(int *)((char *)param_1 + 0xb8 + i * 4) != 0) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

// Differing instructions (cascading check blocks, ~9 logical words differ):
// 1. +0x44: Retail emits 'bnezl v0, 0x54' branching to the then-block with 'lui s1, 0x3f' in the delay slot,
//    falling through to 'b 0x9c; move v0, zero'. Our compilation emits 'beqzl v0, 0x94'.
// 2. +0x9c and +0xd4: Same pattern repeating across the subsequent cascading check stages.
// Ruled out:
// - Separate static inline helper functions check1..check4 with early returns (produces inverted beqzl logic).
// - Flat && short-circuiting chain (does not emit retail's branch-likely with delay slot initialization).
// - Inverted if (!ok) { ok = 0; } else { ... } vs if (ok) { ... } else { ok = 0; }.
// near miss from lane u1r5-3 (unreviewed)
