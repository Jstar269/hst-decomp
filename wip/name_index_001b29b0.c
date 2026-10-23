/* HSTMATCH module=EBOOT.BIN start=0x001b29b0 end=0x001b2ad8 symbol=FUN_001b29b0 lang=c99 */
extern char DAT_002e9944[];
extern int DAT_0034178c;
extern unsigned char DAT_003417be;
extern int FUN_00014a40(char *);
extern int FUN_00014a58(char *, char *, int);

int FUN_001b29b0(char *param_1, int param_2)
{
    int idx = -1;
    char last;
    int i;

    last = param_1[FUN_00014a40(param_1) - 1];
    DAT_0034178c = param_2;
    if (last == '*') {
        for (i = 0; i < 3u; i++) {
            if (FUN_00014a58(param_1, *(char **)(DAT_002e9944 + i * 8),
                             FUN_00014a40(*(char **)(DAT_002e9944 + i * 8))) == 0) {
                if (DAT_003417be != 0) {
                    idx = 0;
                } else {
                    {
                        int seed = DAT_0034178c * 0x343fd + 0x269ec3;
                        DAT_0034178c = seed;
                        idx = (seed >> 16 & 0x7fff) %
                              *(int *)(DAT_002e9944 + i * 8 + 4);
                    }
                }
                break;
            }
        }
    } else {
        idx = last - 'a';
    }
    if (idx < 0)
        idx = 0;
    if (idx >= 10)
        idx = 0;
    return idx;
}
// near miss: 74/74 words, 12 differ, all register allocation inside the LCG block: retail keeps
// the seed in a0 and the i*8 offset in v1, ours swaps the pair (same sequence, same order).
// Two source facts pinned the rest: the table entry expression must be written TWICE
// (FUN_00014a58(param_1, *(char**)(T+i*8), FUN_00014a40(*(char**)(T+i*8)))) -- MWCC does not CSE
// it, and retail really does two `lw` from the same slot; and the loop bound is 3u (sltiu), not 3.
// near miss from lane fm6 (unreviewed)
