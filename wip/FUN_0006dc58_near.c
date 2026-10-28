/* HSTMATCH module=EBOOT.BIN start=0x0006dc58 end=0x0006ddb4 symbol=FUN_0006dc58 lang=c99 */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); names and types
   await human review. Leaf, no frame. a0 = the object (current buffer index at +84, a pointer table at +100),
   a1 = the element index (stride 28), a2 = four floats. Each component is packed to a byte: values at or above
   2^31 are offset and get the 0x8000 marker, everything else is truncated; the fourth component is pre-scaled by
   255/128. The table pointer and the index are reloaded for every byte, because the stores may alias. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Obj {
    u8 pad0[84];
    u32 cur;                     /* 84: current buffer index */
    u8 pad58[12];                /* 88..99 */
    u32 tbl[1];                  /* 100: buffer pointer table */
} Obj;

static inline int pack(float x)
{
    int t;

    if (2147483648.0f > x)
        t = (int)x;
    else
        t = (int)(x - 2147483648.0f) | (int)0xffff8000u;
    return t;
}

void FUN_0006dc58(Obj *a0, int idx, float *v)
{
    int off = idx * 28;

    *(u8 *)(a0->tbl[a0->cur] + off) = (u8)pack(v[0]);
    *(u8 *)(off + a0->tbl[a0->cur] + 1) = (u8)pack(v[1]);
    *(u8 *)(off + a0->tbl[a0->cur] + 2) = (u8)pack(v[2]);
    *(u8 *)(off + a0->tbl[a0->cur] + 3) = (u8)pack(v[3] * 1.9921875f);
}
// MEASURED STATE: 87/87 words, 7 differ. Rewritten from the disassembly (the old draft was 5/87). Shape: a0->cur
// (84) indexes a pointer table at 100, the element stride is 28, and four floats are packed to bytes with a
// 2^31 threshold: values at or above it are offset by 2^31 and OR-ed with 0xffff8000 (the 0x80 byte marker), the
// rest truncate; the fourth component is pre-scaled by 255/128. The threshold branch only comes out with retail's
// layout (trunc fall-through, fixup out of line, bc1t) when the condition is written MIRRORED, `2147483648.0f > x`
// with the truncating case in the then-block - that spelling is worth 32 words. The last 7: four `c.ngt.s` vs
// retail's `c.le.s` (same predicate, different encoding) and three `addu` operand orders.

// PHASE-3 SWEEP (2026-10-28, pass 17): 7 -> 4 differ. The three `addu` operand orders were source order, but the
// FIRST store is canonicalised the other way round: store 0 wants `base + off` (drop the `+ 0`), stores 1..3 want
// `off + base + k`. With `(off + base + k)` for all four, store 0 breaks and the other three fix (5 differ).
// The last 4 are `c.ngt.s` vs retail's `c.le.s` and are coupled to the arm layout: writing the fixup test positively
// (`2147483648.0f <= x`, fixup as the then-block) or as an early-return guard gives `c.le.s` but puts the fixup
// inline, which costs 32-36 words. The mirrored `c > x` form is the only one that yields retail's layout, and it
// always emits `c.ngt.s`. Wall: measured, 4 words, encoding<->layout coupling.
// improved by lane dsn2 (unreviewed): 5 -> 4 differing words
