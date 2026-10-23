/* HSTMATCH module=EBOOT.BIN start=0x0020d82c end=0x0020da38 symbol=FUN_0020d82c lang=c99 */
extern int FUN_0001342c(void);
extern void FUN_00022450(float *, int, float *);
extern int FUN_000ddd64(void *, float *, int);
extern void FUN_0020b600(void *);
extern void *FUN_00215a58(void *);
extern void *FUN_00215a20(void *);
extern int DAT_00338b44;
extern int DAT_003386b0;
extern float DAT_002ef9c8;
extern int DAT_002ef9cc;

struct SysA {
    char pad0[0x61];
    unsigned char f61;
    char pad1[0x2e];
    int f90;
    char pad2[8];
    int f9c;
};

struct SysB {
    char pad0[0x70];
    char pad1[0x18];
    void *f88;
};

struct Sel {
    char pad0[0xc];
    int base;
    int count;
};

struct Ring {
    char pad0[0x18];
    float f18;
    char pad1[0x214];
    int f230;
    int f234;
    char pad2[0x34];
    struct Sel sel;
};

struct Player {
    char pad0[0x144];
    int f144;
    char pad1[0x460];
    float f5a8;
};

struct Target {
    char pad0[0x84];
    float f84;
};

struct Node {
    char pad0[0x5a0];
    float f5a0;
    float f5a4;
    float f5a8;
    float f5ac;
};

int FUN_0020d82c(struct Player *p)
{
    struct Ring *r;
    struct Sel *sel;
    struct Node *node;
    float out[4];
    float pos[4];
    float m[4];
    float rate;
    float fa;
    float fb;
    float d;
    int flag;
    int off;

    flag = p->f144 ^ 1;
    if (((struct SysA *)DAT_00338b44)->f9c == flag)
        return 1;
    r = (struct Ring *)((struct SysB *)DAT_003386b0)->f88;
    if (flag != r->f230)
        return 0;
    sel = &r->sel;
    if (((struct SysA *)DAT_00338b44)->f90 == 1) {
        if (((struct SysA *)DAT_00338b44)->f61 != 0)
            return 1;
    }
    if (!(p->f5a8 * r->f18 < 0.0f))
        return 0;
    fa = ((struct Target *)FUN_00215a58(p))->f84;
    fb = ((struct Target *)FUN_00215a20(p))->f84;
    d = fa + fb;
    rate = DAT_002ef9c8;
    if (DAT_002ef9c8 > d)
        rate = d;
    if (!((float)(int)(FUN_0001342c() & 0xfffff800) * 4.656613e-10f < rate * 0.01f))
        return 0;
    if (r->f234 < 0)
        return 0;
    if (sel->count <= 0)
        return 0;
    node = *(struct Node **)(DAT_003386b0 + r->f234 * 4 + 0x70);
    pos[0] = node->f5a0;
    pos[1] = node->f5a4;
    pos[2] = node->f5a8;
    pos[3] = node->f5ac;
    off = 0;
    if (sel->count == 0)
        off = -1;
    FUN_00022450(m, sel->base + off * 0x20 + 0x10, pos);
    out[0] = m[0];
    out[1] = m[1];
    out[2] = m[2];
    out[3] = m[3];
    if (FUN_000ddd64((struct SysA *)DAT_00338b44, out, ((struct SysA *)DAT_00338b44)->f90 == 1) == 0) {
        FUN_0020b600(&DAT_002ef9cc);
        return 1;
    }
    return 0;
}

// 134/131 words (3 over), ~10 real deltas, all MWCC layout/register choices:
// (1) float locals: retail keeps the clamp rate in f20 and the first callee result in
//     f21; here it is the other way round (fa f20 / rate f21) - unchanged by
//     reordering the declarations (rate first, d last) or by `rate = DAT` placement.
// (2) every `return 0` here jumps to a shared move v0,zero block (b + move), retail
//     branches straight to the final epilogue with the move in the delay slot
//     (bc1fl/bnez + move v0,zero), one word shorter per site.
// (3) `off = 0; if (sel->count == 0) off = -1;` already gives retail's addiu a1,a0,-1.
// (4) the m/pos/out stack slots only line up with out declared first (out sp+32,
//     pos sp+48, m sp+64).
// near miss from lane fm8 (unreviewed)
