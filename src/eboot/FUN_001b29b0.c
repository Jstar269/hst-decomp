/* HSTMATCH module=EBOOT.BIN start=0x001b29b0 end=0x001b2ad8 symbol=FUN_001b29b0 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
extern char DAT_002e9944[];
extern int DAT_002e9948[];
extern int DAT_0034178c;
extern unsigned char DAT_003417be;
extern int FUN_00014a40(char *);
extern int FUN_00014a58(char *, char *, int);

#define WILDCARD_COUNT 3u   /* entries in the wildcard table (8 bytes each: name, choice count) */
#define LCG_MUL 0x343fd     /* linear congruential generator constants of the global seed */
#define LCG_ADD 0x269ec3
#define RAND_MASK 0x7fff    /* 15 random bits are used */
#define INDEX_MAX 10        /* valid indices are 0..INDEX_MAX-1 */

/* Maps a name to an index: a trailing '*' selects a wildcard-table entry whose name is a prefix of the
   string and draws a random choice within it (always 0 when the global flag is set); otherwise the
   last letter gives the index ('a' = 0). Out-of-range results become 0. The seed argument is stored
   as the global random seed first. */
int FUN_001b29b0(char *name, int seed)
{
    int idx = -1;
    char last;
    int i;

    last = name[FUN_00014a40(name) - 1];
    DAT_0034178c = seed;
    if (last == '*') {
        for (i = 0; i < WILDCARD_COUNT; i++) {
            if (FUN_00014a58(name, *(char **)(DAT_002e9944 + i * 8),
                             FUN_00014a40(*(char **)(DAT_002e9944 + i * 8))) == 0) {
                if (DAT_003417be != 0) {
                    idx = 0;
                } else {
                    {
                        int rng = DAT_0034178c * LCG_MUL + LCG_ADD;
                        DAT_0034178c = rng;
                        idx = (rng >> 16 & RAND_MASK) %
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
    if (idx >= INDEX_MAX)
        idx = 0;
    return idx;
}
// EXACT (74/74 words). Two source facts pinned the rest: the table entry expression must be
// written TWICE (FUN_00014a58(name, *(char**)(T+i*8), FUN_00014a40(*(char**)(T+i*8)))) --
// MWCC does not CSE it, and retail really does two `lw` from the same slot; and the loop bound
// is 3u (sltiu), not 3. The per-entry count is its OWN symbol: retail loads the count with base
// 0x2e9948 and displacement 0, not base 0x2e9944 + 4, so declare `extern int DAT_002e9948[]`
// and index it `DAT_002e9948[i * 2]`. That also fixes the v1/a0 colouring of the LCG block.
