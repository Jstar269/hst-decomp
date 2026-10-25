/* HSTMATCH module=EBOOT.BIN start=0x0010e1d0 end=0x0010e3b8 symbol=FUN_0010e1d0 lang=c++ */
// NEAR MISS 120/122 words.  Open delta: retail loads the position (220) AFTER
// the height test and jumps to the body with `bgtzl`, keeping one epilogue;
// this source hoists both loads and uses `blez` + `b` (2 words short).  The
// virtual call is also `lw t9,0(a0); lw t9,12(t9); jalr t9` in retail (the
// incoming a0), ours goes through the s0 copy into v0.
// Matching notes: the float at 0xe0 must be a real `float` field (lwc1, no
// cvt), the 0xd0..0xdc fields are ints (mtc1 + cvt.s.w), and the struct view
// keeps every access a displacement off one base pointer (otherwise MWCC
// materialises param+0xe0 in a second s-register and the frame grows).
extern "C" void FUN_000ffb3c(int, int);

struct SpriteBase {
    virtual void slot0();
    virtual void slot1(int);
};

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

extern "C" void FUN_0010e1d0(struct Obj0010e1d0 *o)
{
    int mid;
    int d;
    float frac;
    float off;
    short s2;
    int node;
    short s1;
    short s5;
    void (*fn)(void *, int);

    if (o->f_d8 <= 0 || o->f_dc <= 0)
        return;
    if (o->f_d8 <= o->f_dc) {
        frac = 1.0f;
        off = 0.0f;
    } else {
        frac = (float)o->f_dc / (float)o->f_d8;
        off = (float)o->f_d4 / (float)o->f_d8;
        ((SpriteBase *)o)->slot1(0);
    }
    off = (float)o->f_d0 + off * o->f_e0;
    mid = o->f_d0 + o->f_d4;
    s2 = (short)(int)(off + (float)o->f_d4 * frac);
    d = s2 - mid;
    d = d < 0 ? -d : d;
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
// near miss: 122/122 words (retail's exact size), 62 differing - all of them scheduling/register
// naming inside two blocks. Fixed since the first attempt (was 120/122):
// (1) the two guards must NOT use locals: write `if (o->f_d8 <= 0 || o->f_dc <= 0) return;` and
//     repeat `o->f_d8`/`o->f_dc` inline everywhere (retail keeps height in a2 and pos in v1, both
//     call-clobbered, and loads pos AFTER the first test). Local copies hoist both loads.
// (2) the virtual call must be a real C++ virtual (class with two virtuals, slot 1 = 0xc) so it
//     becomes `lw t9,0(a0); lw t9,12(t9); jalr t9` off the incoming a0; a C function-pointer local
//     gives `lw v0,0(s0); lw v0,12(v0); jalr v0` and costs 2 words.
// (3) compute `off` BEFORE `mid` in the source (that is what puts the `lw v1,208` / `lwc1 224` /
//     `lw v0,212` order and `addu a0,v1,v0` where retail has them).
// (4) the abs must be a ternary: `d = d < 0 ? -d : d;` -> `bgez v1; nop; negu`; the `if (d < 0)`
//     form gives `bgezl` with `slti` in the slot.
// Remaining: the off-sum temp is $f2 here vs $f1 in retail (`add.s $f0,$f2,$f0` vs `$f0,$f1,$f0`),
// and the node/s1/s5 block keeps its ints in v1/t0/a3/a2 where retail uses a0/t1/t0/a3/a2 - the
// load order `lh t0,10(t1); lh a3,6(t1); mfc1 a0,$f0; lh a2,6(t1)` is retail's.
// Also: retail reads `o->ctx` from memory twice (`lw a0,16(s0)` x2), ours CSEs it into one reg.
// near miss from lane fm8 (unreviewed)
// improved by lane bg2 (unreviewed): 91 -> 62 differing words
