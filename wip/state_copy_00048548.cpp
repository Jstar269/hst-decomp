/* HSTMATCH module=EBOOT.BIN start=0x00048548 end=0x000487bc symbol=FUN_00048548 lang=c++ */
struct Vec2 { float x, y; };
struct Vec4 { float x, y, z, w; };
struct Pair { int a, b; };

struct State {
    unsigned char b0;
    int i4;
    unsigned char b8;
    int ic;
    char pad0[0x30];
    Pair q[8];
    int f80;
    int f84;
    Vec2 v88;
    Vec4 v90;
    Vec4 va0;
    Vec4 vb0;
};

extern int DAT_002cfc8c;
extern State DAT_00311080;
extern char DAT_00311068;
extern int DAT_00311060;
extern int DAT_00311064;
extern int DAT_0031106c;
extern int DAT_00310fd0;
extern int DAT_003386b0;
extern int DAT_00338c20;

extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void FUN_0001dc7c(void *);
extern "C" void FUN_00000f74(void *, void *, void *);
extern "C" void FUN_0001dce4(void);
extern "C" int FUN_000487c8(void);
extern "C" int FUN_000fb5f4(void);
extern "C" int FUN_000889ec(void);
extern "C" int FUN_000fb734(void);

#pragma opt_unroll_loops off
extern "C" void FUN_00048548(void)
{
    State *s;
    Pair *src;
    Pair *dst;
    int n;
    int r;

    if (DAT_00311068 == 0) {
        FUN_0001dc7c(&DAT_00311080);
        FUN_00000f74(&DAT_00311080, (void *)FUN_0001dce4, &DAT_0031106c);
        DAT_00311068 = 1;
    }
    r = FUN_000487c8();
    if (r == 0) {
        s = (State *)DAT_002cfc8c;
        DAT_00311080.b0 = s->b0;
        DAT_00311080.i4 = s->i4;
        DAT_00311080.b8 = s->b8;
        DAT_00311080.ic = s->ic;
        src = s->q;
        dst = DAT_00311080.q;
        n = 8;
        do {
            *dst = *src;
            n--;
            src++;
            dst++;
        } while (0 < n);
        DAT_00311080.f80 = s->f80;
        DAT_00311080.f84 = s->f84;
        DAT_00311080.v88 = s->v88;
        DAT_00311080.v90 = s->v90;
        DAT_00311080.va0 = s->va0;
        DAT_00311080.vb0 = s->vb0;
    }
    if (DAT_00311060 != 0) {
        if (DAT_00338c20 != 0 && FUN_000fb5f4() != 0)
            DAT_00311060 = 0;
    } else {
        if (DAT_00338c20 != 0)
            FUN_000fb5f4();
    }
    s = (State *)DAT_002cfc8c;
    if ((int)(char)s->v88.x << 0x18 >> 0x1e == 0 && DAT_00310fd0 == 1 &&
        DAT_003386b0 != 0 && FUN_000889ec() != 0 &&
        (DAT_00338c20 == 0 || FUN_000fb734() != 0)) {
        DAT_00311064 = 0;
        DAT_00311060 = (DAT_00311060 != 0) ^ 1;
    }
}
// 0x00048548: 159/157 words, 104 differ (struct-typed version; the flat-globals version was
// 157/157 words with 110 differ). Structure is right: lazy-init guard, then a field copy from
// *(0x2cfc8c) into a global record at 0x311080 (byte,int,byte,int, 8 Pair copies, int,int,
// Vec2, 3x Vec4), then the 0x311060/0x338c20 state update and the 4-condition tail.
// Remaining difference is register colouring of the copy temps (ours reuses a0/f0 for the
// load-store pairs, retail keeps 2-4 live in t-regs and f1..f3) plus retail's 2+4+4+4 batched
// float copy. Ruled out: memcpy intrinsic (122 words), dst-before-src declaration, unroll off
// (kept, it is needed), separate flat globals.
// near miss from lane fm11 (unreviewed)
