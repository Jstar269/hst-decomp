/* HSTMATCH module=EBOOT.BIN start=0x0010e1d0 end=0x0010e3b8 symbol=FUN_0010e1d0 lang=c99 */
// NEAR MISS 120/122 words.  Open delta: retail loads the position (220) AFTER
// the height test and jumps to the body with `bgtzl`, keeping one epilogue;
// this source hoists both loads and uses `blez` + `b` (2 words short).  The
// virtual call is also `lw t9,0(a0); lw t9,12(t9); jalr t9` in retail (the
// incoming a0), ours goes through the s0 copy into v0.
// Matching notes: the float at 0xe0 must be a real `float` field (lwc1, no
// cvt), the 0xd0..0xdc fields are ints (mtc1 + cvt.s.w), and the struct view
// keeps every access a displacement off one base pointer (otherwise MWCC
// materialises param+0xe0 in a second s-register and the frame grows).
extern void FUN_000ffb3c(int, int);

struct Obj0010e1d0 {
    char pad0[0x10];
    int ctx;
    char pad1[0xbc];
    int f_d0;
    int f_d4;
    int f_d8;
    int f_dc;
    float f_e0;
};

void FUN_0010e1d0(struct Obj0010e1d0 *o)
{
    int height;
    int pos;
    int mid;
    int d;
    float frac;
    float off;
    short s2;
    int node;
    short s1;
    short s5;
    void (*fn)(void *, int);

    height = o->f_d8;
    pos = o->f_dc;
    if (height <= 0 || pos <= 0)
        return;
    if (height <= pos) {
        frac = 1.0f;
        off = 0.0f;
    } else {
        frac = (float)pos / (float)height;
        off = (float)o->f_d4 / (float)height;
        fn = *(void (**)(void *, int))(*((int *)o) + 0xc);
        fn(o, 0);
    }
    mid = o->f_d0 + o->f_d4;
    off = (float)o->f_d0 + off * o->f_e0;
    s2 = (short)(int)(off + (float)o->f_d4 * frac);
    d = s2 - mid;
    if (d < 0)
        d = -d;
    if (d < 2)
        s2 = (short)mid;
    node = *(int *)(o->ctx + 8);
    s1 = *(short *)(node + 6);
    s5 = (short)(int)(off - (float)(short)(*(short *)(node + 10) - *(short *)(node + 6)));
    *(short *)(node + 6) = s5;
    *(short *)(node + 10) = *(short *)(node + 10) + (s5 - s1);
    node = *(int *)o->ctx;
    s1 = *(short *)(node + 6);
    *(short *)(node + 6) = s2;
    *(short *)(node + 10) = *(short *)(node + 10) + (s2 - s1);
    *(short *)(*(int *)(o->ctx + 4) + 6) = (short)(int)off;
    *(short *)(*(int *)(o->ctx + 4) + 10) = s2;
    FUN_000ffb3c(*(int *)(o->ctx + 0x10), o->f_e0 <= 0.0f);
    FUN_000ffb3c(*(int *)(o->ctx + 0xc), (float)(o->f_d8 - o->f_dc) <= o->f_e0);
}
// near miss from lane fm8 (unreviewed)
// improved by lane bg2 (unreviewed): 91 -> 62 differing words
