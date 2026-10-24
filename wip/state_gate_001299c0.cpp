/* HSTMATCH module=EBOOT.BIN start=0x001299c0 end=0x00129b74 symbol=FUN_001299c0 lang=c++ */

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Obj {
    char pad000[0x190];
    int f190;                   /* 0x190 */
    char pad194[0x1b0 - 0x194];
    Vec4 f1b0;                  /* 0x1b0 */
    Vec4 f1c0;                  /* 0x1c0 */
    char pad1d0[0x1f0 - 0x1d0];
    float f1f0[13];             /* 0x1f0 */
    float f224[3];              /* 0x224 */
    Vec4 f230;                  /* 0x230 */
    unsigned char f240[0x32c - 0x240]; /* 0x240 */
    unsigned char f32c;         /* 0x32c */
    char pad32d[0x370 - 0x32d];
    unsigned char f370[0x70];   /* 0x370 */
};

extern "C" {
extern float DAT_002da3c4;
extern float DAT_002da3c8;
extern float DAT_002da3cc;
extern float DAT_002da3d0;
extern void *DAT_0033b574;
extern int FUN_00128f60(float d, Obj *o, Vec4 *v);
extern unsigned char FUN_00129224(float a, float b, void *p, void *q, void *r);
extern int FUN_001293b4(float d, Vec4 *a, Vec4 *b, int *c);
extern void FUN_0012c7b4(void *dst, Vec4 *src);
extern int FUN_0012d75c(void *p);
}

extern "C" bool FUN_001299c0(Obj *o, int flag)
{
    int zero;
    Vec4 v;
    v = o->f1b0;

    if (flag != 0 && FUN_00128f60(DAT_002da3c8, o, &v) != 0 &&
        o->f32c != 0 && o->f190 == 0xc) {
        v = o->f1c0;
        FUN_0012c7b4(o->f370, &v);
    }

    if (DAT_0033b574 == 0)
        return true;
    if (FUN_0012d75c(DAT_0033b574) == 0)
        return true;

    bool result = FUN_00129224(DAT_002da3c4, 0.0f, &v, o->f1f0, o->f224) != 0;

    Vec4 w;
    w = o->f1c0;
    zero = 0;
    if (o->f190 != 0xc)
        FUN_001293b4(DAT_002da3c8, &v, &w, &zero);

    o->f1b0 = v;
    o->f230 = o->f1b0;
    FUN_00129224(DAT_002da3cc, DAT_002da3d0, &o->f230, o->f240, o->f224);
    return result;
}

// 107/109 words, 80 differ (mostly cascade from the three blocks below).
// Structure matches: stack layout (int zero declared first + 16-byte-aligned Vec4 -> v@0x20, w@0x10,
// zero@0x3c), the pairwise struct copies (assignment form, not initializer form), both 4-float
// copies and every call's arguments.
// What differs (each tried several spellings, mwcc always produced our form):
// 1. `o->f190 == 0xc` block: retail inverts the layout - beql v1,v0,body; lwc1(v=o->f1c0) ; b join ; nop
//    (4 words). Ours: bne v1,v0,join ; nop ; lwc1 (3 words). Tried flat && chain, 2-level and 4-level
//    nested ifs, empty else, goto-style: identical output every time.
// 2. `result = FUN_00129224(...) != 0`: retail materialises the bool with a branch (andi v0,0xff ;
//    bnez v0,L ; li s0,1 ; move s0,zero) and does the andi *before* the w=o->f1c0 copy. mwcc always
//    simplifies `!= 0` to `sltu s0,zero,v0` (2 words). Tried char / unsigned char / bool return types,
//    int result, unsigned char temp, if/else, ?: and if(call) result=true: sltu every time.
// 3. two early `return true`: retail beqzl a0,epilogue ; li v0,1 (and li v0,1 ; b epilogue ; nop after
//    the second test). Ours bnez a0,L ; nop ; b epilogue ; li v0,1. Tried if (!ptr), || chain, else-if:
//    identical output.
// Ruled out: plain Vec4 (4-byte align) - v/w/zero land at 0x30/0x20/0x1c; initializer form
// `Vec4 v = o->f1b0` - 4 loads then 4 stores instead of pairwise; DAT_0033b574 as int (mwcc uses v0
// instead of a0 for the tested value, which retail passes on to FUN_0012d75c).
// near miss from lane fm7 (unreviewed)
