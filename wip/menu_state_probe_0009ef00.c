/* HSTMATCH module=EBOOT.BIN start=0x0009ef00 end=0x0009f088 symbol=FUN_0009ef00 lang=c99 */
typedef unsigned char bool;

extern char DAT_00341837[];
extern int DAT_00338b44;
extern int DAT_0034a77c;
extern int FUN_000dbc54(int, int);
extern char FUN_0024de88(int, int, int);

int FUN_0009ef00(int param_1, int param_2)
{
    int r = -1;
    char c;
    bool b;

    if ((((int)*(char *)(param_2 + 0x8b) << 0x1c) >> 0x1e) == 0) {
        r = 0;
        goto done;
    }
    if ((((int)*(char *)(param_2 + 0x8b) << 0x1a) >> 0x1e) == 0) {
        b = FUN_000dbc54(DAT_00338b44, 1) != 0;
        if (!b) {
            b = FUN_000dbc54(DAT_00338b44, 3) != 0;
        }
        if (!b) {
            r = 1;
            goto done;
        }
        c = *(char *)(param_2 + 0x8b);
    } else {
        c = *(char *)(param_2 + 0x8b);
    }
    if ((((int)c << 0x1e) >> 0x1e) != 0) {
        r = -1;
        goto done;
    }
    b = FUN_000dbc54(DAT_00338b44, 2) != 0;
    if (!b) {
        b = FUN_000dbc54(DAT_00338b44, 3) != 0;
    }
    if (!b) {
        if (FUN_000dbc54(DAT_00338b44, 0x11) == 0) {
            if (FUN_000dbc54(DAT_00338b44, 0x12) == 0) {
                if (FUN_000dbc54(DAT_00338b44, 0x13) == 0) {
                    c = FUN_0024de88(DAT_0034a77c, 8,
                                     DAT_00341837[*(int *)(param_1 + 0x148) * 0x120]);
                } else {
                    c = 1;
                }
            } else {
                c = 1;
            }
        } else {
            c = 1;
        }
        if (c != 0) {
            r = 2;
        }
    }
done:
    return r;
}
// NEAR MISS (lane fm3): 73 of 98 words differ, but only in two idioms, both tried both ways.
// (1) Retail's two `b = (call != 0); if (!b) ...` tests come out as `sltu v0,zero,v0;
//     bnezl v0,T; xori v0,v0,1` (the negation materialised, likely branch with the xori in the
//     delay slot). We always get a plain `bnez v0,T; nop` whether b is int, bool,
//     `if (!b)` or `if (b == 0)`, and whether the failure path is `return 1` or
//     `r = 1; goto done;`. The result value also lives in s0 in retail (`li s0,1; b exit`)
//     where ours uses v0, i.e. retail has ONE exit; the goto form reproduces the epilogue but
//     not the likely/xori pairs.
// (2) The reload of *(char *)(param_2+0x8b) is CSE'd against the entry load in ours (lb v1) but
//     retail reloads into v0 in the else arm and in the merged join.
// Verified along the way: FUN_0024de88 must be prototyped to return `char` (an `unsigned char`
// return makes the caller emit `seb` before the `!= 0` test where retail has `andi 0xff`).
// Everything else (both bitfield extracts, all five FUN_000dbc54(DAT_00338b44,N) calls, the
// 0x120-strided DAT_00341837 index, the 0/1/-1/2 results) already agrees.
// near miss from lane fm3 (unreviewed)
