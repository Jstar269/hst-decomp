/* HSTMATCH module=hstp_trans_main.prx start=0x000e2708 end=0x000e2c0c symbol=FUN_000e2708 lang=c99 helpers=FUN_000e24b4@0x000e24b4-0x000e25dc,FUN_000e25dc@0x000e25dc-0x000e2708 */
/* Hand-written reconstruction from the disassembly (matching idiom: #pragma auto_inline on + inline_max_auto_size(40) so the two same-file point checks placed by helpers= are auto-inlined like retail, #pragma auto_inline off before the target so its recursive calls stay out of line); exact match verified; names and types await human review. */
/* The two point checks in front are same-file functions that retail emits out of line AND inlines into the target (arg = -1 folded). */
#pragma auto_inline on
#pragma inline_max_auto_size(40)
typedef struct Slot { char pad[0x144]; unsigned f144; } Slot;
typedef struct Game { char pad[0x70]; Slot *slots[2]; } Game;
typedef struct Match {
    char pad0[0x50];
    int f50;
    char pad1[0xc0 - 0x54];
    int fc0;
    int fc4[2];
    int fcc;
    int score[2];
} Match;
extern Game *DAT_003e19f0;
extern unsigned char DAT_003eaaf3;
extern unsigned char DAT_003e1e88;
extern int FUN_000e30f8(Match *);

unsigned char FUN_000e24b4(Match *m, int arg)
{
    unsigned cur = DAT_003e19f0->slots[m->f50]->f144;
    if (arg < 0 || (unsigned)arg == cur) {
        if (FUN_000e30f8(m) != 0) {
            unsigned char r = 1;
            int n = m->score[cur] + 1;
            if (n < 9) {
                int b = n > 6;
                if (b) b = n - m->score[cur ^ 1] > 1;
                if (!b) r = 0;
            }
            return r;
        } else {
            unsigned char r = 0;
            int n = m->score[cur] + 1;
            if (!(n < m->fcc)) {
                int ok = n - m->score[cur ^ 1] > 1;
                if (!ok) ok = DAT_003eaaf3 == 1;
                if (ok) r = 1;
            }
            return r;
        }
    }
    return 0;
}

unsigned char FUN_000e25dc(Match *m, int arg)
{
    unsigned cur = DAT_003e19f0->slots[m->f50]->f144 ^ 1;
    if (arg < 0 || (unsigned)arg == cur) {
        if (FUN_000e30f8(m) != 0) {
            unsigned char r = 1;
            int n = m->score[cur] + 1;
            if (n < 9) {
                int b = n > 6;
                if (b) b = n - m->score[cur ^ 1] > 1;
                if (!b) r = 0;
            }
            return r;
        } else {
            unsigned char r = 0;
            int n = m->score[cur] + 1;
            if (!(n < m->fcc)) {
                int ok = n - m->score[cur ^ 1] > 1;
                if (!ok) ok = DAT_003eaaf3 == 1;
                if (ok) r = 1;
            }
            return r;
        }
    }
    return 0;
}

#pragma auto_inline off
int FUN_000e2708(Match *m, int arg)
{
    unsigned cur;
    if (DAT_003e1e88 != 0) return 0;
    cur = DAT_003e19f0->slots[m->f50]->f144;
    if (FUN_000e24b4(m, -1) && FUN_000e25dc(m, -1)) {
        if (arg == -1) return FUN_000e2708(m, 0) || FUN_000e2708(m, 1);
        cur = arg;
    } else if (!FUN_000e24b4(m, -1)) {
        if (FUN_000e25dc(m, -1)) cur ^= 1;
        else cur = -1;
    }
    if ((int)cur >= 0) {
        if (arg < 0 || (unsigned)arg == cur) {
            int need = m->fc0;
            int n = m->fc4[cur] + 1;
            if (n >= need + 1) return 1;
            if (n >= need && n - m->fc4[cur ^ 1] >= 2) return 1;
        }
    }
    return 0;
}
