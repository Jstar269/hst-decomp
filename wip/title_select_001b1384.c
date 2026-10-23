/* HSTMATCH module=EBOOT.BIN start=0x001b1384 end=0x001b150c symbol=FUN_001b1384 lang=c99 */
typedef struct {
    int slot;
    unsigned char has;
    unsigned char mask;
    signed char kind;
    char pad;
    char *title;
} Entry;

extern char DAT_002e8f3c[];
extern void FUN_000143b0(char *, char *, int);
extern int FUN_00062b64(int, char *, int);

int FUN_001b1384(int param_1, unsigned int *param_2)
{
    int result;
    char fmt[32];
    unsigned int idx;
    int want;
    int slot;
    int v;
    Entry *e;

    if ((int)*param_2 < 0 || *param_2 >= 0x71)
        return -1;
    result = -1;
    if (*(unsigned char *)(param_1 + 0x7dc) == 0)
        want = 1;
    else
        want = 2;
    while (result < 0 && (idx = *param_2) < 0x71) {
        e = (Entry *)(DAT_002e8f3c + idx * 0xc);
        if ((e->mask & want) == 0) {
            *param_2 = *param_2 + 1;
        } else if (e->has != 0) {
            FUN_000143b0(fmt, e->title, *(int *)(param_1 + 0x7d8));
            result = FUN_00062b64(*(int *)(param_1 + e->slot * 4), fmt, 0);
            *param_2 = *param_2 + 1;
        } else if (e->kind >= 0) {
            result = FUN_00062b64(*(int *)(param_1 + e->kind * 4 + 0x768), e->title, 0);
            *param_2 = *param_2 + 1;
        } else {
            slot = e->slot;
            if (slot == 0x16a)
                v = *(int *)(param_1 + 0x788);
            else if (slot == 0x15b)
                v = *(int *)(param_1 + 0x778);
            else
                v = *(int *)(param_1 + slot * 4);
            if ((unsigned int)(slot - 0xae) > 1 || *(int *)(param_1 + 0x7d8) == 0xb) {
                if (v != 0)
                    result = FUN_00062b64(v, e->title, 0);
            }
            *param_2 = *param_2 + 1;
        }
    }
    return result;
}
// near miss: 103/98 words. Logic recovered (bounds guard returning -1, the want = 1/2 mask from
// +0x7dc, the 0xc-stride table at 0x2e8f3c with slot@0, has@4, mask@5, kind@6, title@8, the three
// arms calling FUN_00062b64 with either *(self + slot*4) or *(self + kind*4 + 0x768), and the
// 0x16a/0x15b special slots + the (slot - 0xae) <= 1 && +0x7d8 != 0xb guard). Delta: the guard's
// return -1 blocks are placed at the end of the function in ours (so `bltz` jumps past a fresh
// `li v0,-1`) while retail shares one block right after the second test with `li v0,-1` in the
// bltz delay slot; ours is 5 words longer.
// near miss from lane fm6 (unreviewed)
