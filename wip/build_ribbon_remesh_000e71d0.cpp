/* HSTMATCH module=EBOOT.BIN start=0x000e71d0 end=0x000e7494 symbol=FUN_000e71d0 lang=c++ */
/* NEAR MISS: 177/177 words (exact length), 89 differ, first at +0x20. Frame is now retail's 320 bytes.
   THE 32-BYTE FRAME OBJECT IS SOLVED. Retail's sp+0x120 slot is an aggregate whose first member is the
   materialised &DAT_002c0ef0, and MWCC keeps it in memory only when the type is a CLASS WITH A USER CTOR
   *AND* A USER DESTRUCTOR:  struct Mtl { void *p; int pad[7]; Mtl() {} ~Mtl() {} };  Mtl m;  m.p = &DAT_002c0ef0;
   gives exactly retail's `lui 0x2c; addiu 3824; sw v0,288(sp)` ... `lw a1,288(sp)` and the 32 extra frame
   bytes (only word 0 is ever written). Ruled out at the same site: a plain void* local (rematerialised,
   frame 288), void* volatile (spills, but the slot moves to 0x12c and every other local shifts +0xc),
   void*[8], a plain 32-byte holder struct with the pointer at +0, a reference, a declaration-time
   initialiser, the same struct with only a ctor (still folded), and aggregate `= { &DAT }` (that builds the
   object in .data and needs data= in the header). This alone moved 171 -> 177 words with the frame right.
   Layout: locals are allocated in REVERSE declaration order from the frame top, so the declarations must
   read `m, mat2, va, vb, res, q, tmpA, tmpB, cubic, mat1`: sp+0x30 e74e4 dst (16-float matrix), 0x70 cubic,
   0x80/0x90 the two 22498 results, 0xa0 the 22434 result, 0xb0 the 22548 result, 0xc0/0xd0 the two copies,
   0xe0 e74d4 dst, 0x120 the Mtl aggregate.
   Also required: `#pragma opt_strength_reduction off` (otherwise the i*0x2f0 index becomes a walking byte
   offset), `if (it->f20 <= 0.0f) continue;` for retail's `c.le.s $f1,$f0 / bc1tl` (the `>`/`0.0f <`
   spellings give `c.ngt.s`/`c.lt.s`), and the do-while with `static inline bool Ne(Rec*,Rec*)` for the
   value-form `!=` (only the back edge materialises it; the entry test folds to a single beq in every spelling
   tried).
   What is left: the schedule of the `lw pts; addu` pair before the first 22498 call (retail keeps it after the
   Mtl store, we hoist it above the 1.0f/count division) and the loop's counter colouring (retail i in s2 and
   the record pointer in s3; ours the other way round). Names provisional. */
#pragma opt_strength_reduction off

typedef unsigned char u8;

struct Vec4 {
    float x, y, z, w;
};

struct Rec {
    char pad0[0x10];
    Vec4 v;
    float f20;
    char pad1[0x2f0 - 0x24];
};

struct Mtl {
    void *p;
    int pad[7];
    Mtl() {}
    ~Mtl() {}
};

struct Owner {
    char pad0[0x3c];
    char *pts;      /* 0x3c, stride 0x20 */
    char pad1[8];
    Rec *recs;      /* 0x48, stride 0x2f0 */
    int count;      /* 0x4c */
    char pad2[0xc];
    int k;          /* 0x5c */
    int n;          /* 0x60 */
    unsigned int f64;   /* 0x64 */
    char pad3[8];
    char sub70[0x60];   /* 0x70 */
    u8 flag;            /* 0xd0 */
};

extern "C" {
    extern char DAT_002c0ef0;
    extern Vec4 *FUN_00022434(Vec4 *, Vec4 *, Vec4 *);
    extern float FUN_000224d8(Vec4 *, Vec4 *);
    extern void FUN_00022e44(float);
    extern void FUN_00022498(Vec4 *, Vec4 *, float);
    extern void FUN_00022548(Vec4 *, void *, Vec4 *);
    extern void *FUN_000e74e4(void *, Vec4 *, Vec4 *, Vec4 *, Vec4 *);
    extern void FUN_000e74d4(void *, void *, void *);
    extern void FUN_000e75f4(Owner *, Rec *, void *, int);
}

static inline Rec *End(Owner *p) { return (Rec *)((char *)p->recs + p->count * 0x2f0); }
static inline bool Ne(Rec *a, Rec *b) { return a != b; }

extern "C" void FUN_000e71d0(Owner *p)
{
    Mtl m;
    float mat2[16];
    Vec4 va;
    Vec4 vb;
    Vec4 res;
    Vec4 q;
    Vec4 tmpA;
    Vec4 tmpB;
    Vec4 cubic;
    float mat1[16];
    int a, b, count, i, idx;
    float s, s2;

    if (!p->flag) return;
    if (p->f64 < 4) return;

    a = ((p->n + p->k - 1) % p->k) * 0x20;
    b = ((p->n + p->k - 4) % p->k) * 0x20;
    FUN_00022434(&q, (Vec4 *)(p->pts + a), (Vec4 *)(p->pts + b));
    FUN_00022e44(FUN_000224d8((Vec4 *)(p->pts + a + 0x10), (Vec4 *)(p->pts + a + 0x10)));

    count = p->count;
    if (count <= 0) return;
    s = 1.0f / (float)count;

    m.p = &DAT_002c0ef0;
    FUN_00022498(&tmpA, (Vec4 *)(p->pts + b + 0x10), 0.1f);
    va = tmpA;
    FUN_00022498(&tmpB, (Vec4 *)(p->pts + a + 0x10), 0.1f);
    vb = tmpB;
    FUN_000e74d4(mat2, m.p, FUN_000e74e4(mat1, (Vec4 *)(p->pts + b), (Vec4 *)(p->pts + a), &va, &vb));

    for (i = 0; i < count; i++) {
        p->recs[i].f20 = (float)(i + 1) * s;
        cubic.w = 1.0f;
        s2 = s * i;
        cubic.x = s2;
        cubic.y = s2 * s2;
        cubic.z = cubic.y * s2;
        FUN_00022548(&res, mat2, &cubic);
        p->recs[i].v = res;
    }

    idx = 0;
    Rec *it = p->recs;
    if (Ne(it, End(p))) {
        do {
            if (it->f20 <= 0.0f) continue;
            FUN_000e75f4(p, it, p->sub70, idx);
            idx++;
        } while (Ne(++it, End(p)));
    }
}
// near miss from lane ds2 (unreviewed)
