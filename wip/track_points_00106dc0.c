/* HSTMATCH module=EBOOT.BIN start=0x00106dc0 end=0x00106edc symbol=FUN_00106dc0 lang=c99 */
int FUN_00106dc0(char *self, int idx, float *a, float *b, float *c, float *d)
{
    if (idx < 0 || *(int *)(self + 0x50) == 0) {
        *a = 0;
        *b = 0;
        *c = (float)*(int *)(self + 8);
        *d = (float)*(int *)(self + 0xc);
    } else {
        *a = (float)*(unsigned short *)((idx * 8 + *(int *)(self + 0x50)));
        *b = (float)*(unsigned short *)((idx * 8 + *(int *)(self + 0x50)) + 2);
        *c = (float)*(unsigned short *)((idx * 8 + *(int *)(self + 0x50)) + 4);
        *d = (float)*(unsigned short *)((idx * 8 + *(int *)(self + 0x50)) + 6);
    }
    return 1;
}
// NEAR MISS first pass: 71/71 words, only 3 differ -- the operand order of `addu` in the three
// non-first element addresses (retail `addu v0,a1,v0`, i.e. idx*8 + base; ours `addu v0,v0,a1`).
// Everything else is exact, including the `bltzl ...; sw zero,0(a2)` early-out with the first store
// in the branch delay, both int->float conversions of self+8/self+0xc, the four unsigned-short to
// float conversions with MWCC's shift/or/double trick, and the single shared `jr ra; li v0,1`.
// Key shape: ONE return at the end (`if (bad) {...} else {...} return 1;`) -- an early `return 1`
// inside the branch adds a second `li v0,1` and two words. Element addresses must be respelled per
// element (a pointer local folds the base into a register and breaks 20+ words).
// Ruled out for the operand order: base-first, index-first, `(char*)` casts, array-index spelling.
// near miss from lane ds11 (unreviewed)
