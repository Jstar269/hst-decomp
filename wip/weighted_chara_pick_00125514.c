/* HSTMATCH module=EBOOT.BIN start=0x00125514 end=0x00125750 symbol=FUN_00125514 lang=c99 */
#pragma opt_strength_reduction off
extern int DAT_0033b584;
extern unsigned int DAT_00310fc8;
extern int DAT_00340284;
extern int FUN_00131b54(int, int, int);

int FUN_00125514(int param_1, int param_2, int param_3)
{
    int ids[32] = {0};
    int w[32] = {0};
    int res;
    unsigned char b;
    int total;
    int count;
    int i;
    char *p;
    int *pi;
    int *pw;
    int c;
    int want;
    int weight;
    int r;

    res = -1;
    b = param_2 > 10 && param_2 < 0x10;
    if (param_2 == 0x10 && param_3 != 0)
        return -1;
    total = 0;
    count = 0;
    i = 0;
    p = (char *)&DAT_0033b584;
    pi = ids;
    pw = w;
    for (; i < 0xe0; i++, p += 0x58) {
        if (p[0x51] == param_2) {
            c = p[0x50];
        } else if (p[0x52] == param_2 || param_2 == 0x10) {
            c = p[0x50];
        } else
            continue;
        want = param_3 != 0 ? 3 : 4;
        if (c != want && !b)
            continue;
        if (!FUN_00131b54(DAT_00340284, p[0x51], *(int *)(p + 0x38)))
            continue;
        if (!FUN_00131b54(DAT_00340284, p[0x52], *(int *)(p + 0x3c)))
            continue;
        weight = *(int *)((char *)&DAT_0033b584 + i * 0x58 + 0x34);
        *pi++ = i;
        *pw++ = weight;
        count++;
        total += weight;
    }
    if (0 < total) {
        DAT_00310fc8 = DAT_00310fc8 * 0x343fd + 0x269ec3;
        r = (int)((DAT_00310fc8 >> 0x10) & 0x7fff) % total;
        for (i = 0; i < count; i++) {
            if (r < w[i]) {
                res = ids[i];
                break;
            }
            r -= w[i];
        }
        return res;
    }
    return -1;
}
// NEAR (143/143 words, 101 differ - three dislocations that cancel out in size).
// #pragma opt_strength_reduction off is REQUIRED: the weight read (base + i*0x58 + 0x34) must be
// recomputed per pass from `i` (retail: sll/addu/sll/addu/sll) while the record walker p += 0x58 and
// the ids/w pointers are source-level.
// Remaining, in physical order:
//  1) `res = -1` is stored in retail's prologue (between sw s2 and sw s1); ours emits it after the
//     two array-zero loops. Declaration position (before/after the arrays, initialiser vs assignment)
//     does not move it.
//  2) the bool for 10 < param_2 < 0x10: retail `beqz v0` + `move s6,zero` (total = 0 in the plain
//     delay slot) then slti/andi; ours `beqzl v0` + `andi s8` in the slot and total = 0 lands in the
//     later `bne s5,16` delay slot.
//  3) loop entry: retail `beql a1,s5,LAB` with `lb v1,0x50(s2)` in the slot and a separate L2 block
//     `lb v1,0x50(s2)` for the second arm; ours emits `bnel a1,s5` + `b LAB` + the load (one extra
//     word, balanced by 1) below).
// Ruled out: pi/pw array indexing (drops a saved reg), `||`-merged condition (142 words),
// inverted nesting, res declared first, res assigned in the body, want as `param_3==0?4:3`
// (that form gives bnezl; `param_3!=0?3:4` gives retail's beqzl).
// near miss from lane fm8 (unreviewed)
