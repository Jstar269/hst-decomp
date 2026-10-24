/* HSTMATCH module=EBOOT.BIN start=0x00164290 end=0x0016442c symbol=FUN_00164290 lang=c99 */
// NEAR 39 (98 of 103 words): ladder value + table bonus, clamped to the table's first and
// last row and then to DAT_002e0380/384, then lerped between DAT_00341298 and DAT_00341294.
// Residue: retail keeps lo in $f2 and hi in $f0 where we use $f1/$f0, and the second
// clamp comes out as c.le.s+bc1fl against retail's c.ngt.s+bc1tl (retail branches on
// "v <= hi"); the two global loads of DAT_002e0380 that the Clamp recipe predicts are also
// still missing. Ruled out: a static inline Clamp helper (mwcc emits it out of line and
// the function lands 0x38 bytes late, MISPLACED), the arms in the other order (99/103 with
// the branch polarity reversed), and swapping the lo/hi declarations (no change).
// Levers that worked: `if (node != 0) { ... } else { v = f(a+0x58); }` is the arm order
// retail has, and DAT_0034150c must be a POINTER to an array of four pointers
// (`lw v0,5388(v0); lw a0,12(v0)`), not an array of pointers.


typedef struct {
    void *rows;
    int count;
} Table_164290;

extern Table_164290 *DAT_00341510;
extern void **DAT_0034150c;
extern float DAT_002e0380;
extern float DAT_002e0384;
extern float DAT_00341298;
extern float DAT_00341294;
extern float FUN_000d8334(void *p, int a);

float FUN_00164290(char *self, char *node)
{
    float v;
    float lo;
    float hi;

    if (node != 0) {
        if (*(short *)(node + 10) / 10 == 0x32) {
            v = *(float *)((char *)DAT_00341510->rows +
                           (DAT_00341510->count - 1) * 0x14 + 0x10);
            goto out;
        }
        v = *(float *)(self + 0x58);
    } else {
        v = *(float *)(self + 0x58);
    }
    if (node != 0) {
        if (*(short *)(node + 10) >= 0)
            v = v + *(float *)((char *)DAT_0034150c[0] +
                               *(short *)((char *)DAT_0034150c[3] +
                                          *(short *)(node + 10) * 2) * 0x22c + 0x58);
        v = v + FUN_000d8334(node, 4);
    }
    lo = *(float *)((char *)DAT_00341510->rows + 0x10);
    hi = *(float *)((char *)DAT_00341510->rows +
                    (DAT_00341510->count - 1) * 0x14 + 0x10);
    v = v < lo ? lo : (v <= hi ? v : hi);
out:
    v = v < DAT_002e0380 ? DAT_002e0380
                        : (v <= DAT_002e0384 ? v : DAT_002e0384);
    return DAT_00341298 + (v / 9.0f) * (DAT_00341294 - DAT_00341298);
}
// near miss from lane fm7 (unreviewed)
