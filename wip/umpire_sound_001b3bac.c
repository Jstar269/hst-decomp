/* HSTMATCH module=EBOOT.BIN start=0x001b3bac end=0x001b3ce8 symbol=FUN_001b3bac lang=c99 */
extern int DAT_0034178c;
extern unsigned char DAT_003417be;
extern char DAT_002c619c[];
extern char DAT_002c61a0[];
extern char DAT_002e961c[];
extern char DAT_0030ebf4[];
extern void FUN_0001ca58(int, char *, int, int, char *);
extern void FUN_001b0ef8(int, int, int, int, int);

void FUN_001b3bac(int *param_1, int param_2, int param_3)
{
    int idx;
    int self;
    int flag;
    int v1;
    int hint;
    char *tbl;

    self = *param_1;
    if (param_3 == 0) {
        DAT_0034178c = DAT_0034178c * 0x343fd + 0x269ec3;
        flag = ((DAT_0034178c >> 16) & 0x7fff) % 2;
    } else {
        flag = param_3 == 2;
    }
    if (DAT_003417be == 0) {
        v1 = *(int *)(self + 0x79c);
    } else {
        param_2 = 0;
        flag = 0;
        v1 = *(int *)(self + 0x79c);
    }
    idx = param_2 * 2 + 0x16a + flag;
    hint = 0;
    if (v1 == 16)
        hint = 1;
    else if (v1 == 15)
        hint = 1;
    else if (v1 == 1)
        hint = 1;
    if (v1 < 0)
        v1 = *(int *)(self + 0x7a0);
    if (hint)
        tbl = DAT_002c61a0;
    else
        tbl = DAT_002c619c;
    FUN_0001ca58((int)DAT_0030ebf4, DAT_002e961c, param_2, flag, tbl);
    FUN_001b0ef8(self, idx, 0, 0, 0);
    *(int *)(self + 0x788) = *(int *)(self + idx * 4);
}
// near miss: 78-80/79 words; structure recovered but two codegen choices stay different:
// (1) retail puts *param_1 in s1 and the slot index in s0, ours the other way round (the whole
// body then differs only by register names); (2) retail selects the flag-test branch as `beqzl"
// (likely) with the 0x79c load in the delay slot, ours as a plain `bnezl` over an inverted
// block. Facts pinned: the seed step and the `% 2` on the masked high half, the two-arm 0x79c
// load (retail really loads it twice), `idx = param_2 * 2 + 0x16a + flag` (add of flag LAST),
// and the 0x2c61a0/0x2c619c string choice from v1 == 16 || 15 || 1.
// near miss from lane fm6 (unreviewed)
