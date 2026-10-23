/* HSTMATCH module=EBOOT.BIN start=0x001b29b0 end=0x001b2ad8 symbol=FUN_001b29b0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern char DAT_002e9944[];
extern int DAT_002e9948[];
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
                              DAT_002e9948[i * 2];
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
// EXACT (74/74 words). Two source facts pinned the rest: the table entry expression must be
// written TWICE (FUN_00014a58(param_1, *(char**)(T+i*8), FUN_00014a40(*(char**)(T+i*8)))) --
// MWCC does not CSE it, and retail really does two `lw` from the same slot; and the loop bound
// is 3u (sltiu), not 3. The per-entry count is its OWN symbol: retail loads the count with base
// 0x2e9948 and displacement 0, not base 0x2e9944 + 4, so declare `extern int DAT_002e9948[]`
// and index it `DAT_002e9948[i * 2]`. That also fixes the v1/a0 colouring of the LCG block.
