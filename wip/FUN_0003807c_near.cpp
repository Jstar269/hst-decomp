/* HSTMATCH module=EBOOT.BIN start=0x0003807c end=0x0003815c symbol=FUN_0003807c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag g1) corrected by hand: two 0x36714 calls, packed 0x55/0x58 halves, tail call. */
extern "C" void FUN_00042054(char *obj, int size);
extern "C" int *FUN_00036714(char *a0, int a1, int a2);
extern "C" unsigned int FUN_0002c78c(int a0);
extern "C" int FUN_000419f4(int a0, int a1, unsigned int a2);
extern "C" int FUN_00041cd4(int a0, int a1, int a2, int a3, int a4, char *a5);

extern "C" int FUN_0003807c(char *self, int a1, int a2, int a3, int a4, int a5)
{
    char *base = self + 8;
    int *rec;
    unsigned int r;

    FUN_00042054(self, 20);
    rec = FUN_00036714(base, a1, a3);
    FUN_00036714((char *)rec, a2, a4);
    r = FUN_0002c78c(a5);
    unsigned int hi = (r >> 24) | 0x58000000;
    unsigned int lo = (r & 0x00ffffff) | 0x55000000;
    rec[1] = hi;
    rec[0] = lo;
    return FUN_00041cd4(FUN_000419f4((int)(rec + 2), 1, hi), 6, 0x800102, 2, 0, base);
}

// NEAR 53/56 words (lane dsn2, DeepSeek V4.1 Flash (Freebuff)); length is already right (56/56).
// Missing/wrong, all in the s-register colouring and one Allegrex idiom:
// (1) retail keeps base = a0+8 in s6 from the 2nd instruction and reuses it at the tail call; ours
//     re-derives `addiu a0,s1,8` from a saved copy of a0 (which adds one saved register and drops s6).
//     Retail's saves are s6,s3,s2,ra,s5,s4,s1,s0; ours ra,s5,s4,s3,s2,s1,s0. The ORDER of the five
//     argument saves decides it: retail saves a3(a2 reg) before a1(right-to-left argument evaluation of
//     `FUN_00036714(base, a1, a3)`), ours saves a1,a2,a3,t0,t1 in declaration order.
// (2) `(r & 0x00ffffff) | 0x55000000` must be `ins v0,zero,0x18,0x8; or v0,v0,v1`; MWCC gives
//     `sll v1,v0,8; srl v1,v1,8` for this spelling - cf. MWCC-NOTES 221/195: Allegrex `ins` for field
//     clears is emitted by the retail MWCC for `x & 0xffffff` (0x2d498), so the source spelling that
//     triggers ins (not the shift pair) is still open.
// (3) retail does a real tail call (`j 0x41cd4` + `addiu sp,sp,32` in the slot); ours emits `jal` plus a
//     normal epilogue, so MWCC's sibling-call pass did not fire here.
// Tried: no base local (inline `self+8` twice) -> same; hi/lo named locals -> 56/56 words but same 53
// differences; `(int)base` vs `base` typing fixes only the parse. Next step: get s6 by making `self+8` the
// FIRST value defined and the last used (e.g. pass it to the first call as well, or take it through a
// typed member `Sub *s = (Sub *)(self + 8);` used in both calls), then re-check whether the tail call fires.

/* Lane dsn2 addendum 2026-10-27: the `ins` half of this twin pair is a COMPILER limit, not spelling. Our MWCC
   lowers masks to sll/srl (probed in isolation), all four bitfield/union spellings are worse, and the GCC profiles
   either need a rodata pool for float constants retail materialises with lui;mtc1 or produce a different form
   (gcc402x). Same conclusion for 0x000383f4 and 0x000424a4 - see the ins bullet in docs/MWCC-NOTES.md. */
// near miss from lane dsn2 (unreviewed)
