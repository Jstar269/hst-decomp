/* HSTMATCH module=EBOOT.BIN start=0x001c25b0 end=0x001c2714 symbol=FUN_001c25b0 lang=c++ */
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));

struct Obj {
    char pad0[4];
    int f4;
    char pad8[0xa9];
    unsigned char fb1;
    char padb2[2];
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    char padc4[0xc];
    float fd0, fd4, fd8, fdc;
};

struct Game {
    char pad[0x1320];
};

extern "C" {
extern int DAT_002ea2f0;
extern int DAT_002ea300;
extern int DAT_002ea304;
extern Game *DAT_0033b574;
int FUN_001c39f8(int);
void FUN_001cd88c(Obj *, int, int);
void FUN_001c2498(Obj *);
void FUN_002879e0(float, void *, int, int, int, int);
}

static inline const int &Max(const int &a, const int &b) { return a < b ? b : a; }

extern "C" void FUN_001c25b0(Obj *o, int a1, int a2, int a3, const Vec4 *p)
{
    if (o->f4 != 6) {
        o->fb4 = o->f4;
    }
    o->fb8 = a1;
    o->fbc = a2;
    if (FUN_001c39f8(o->fb8) != 0) {
        o->fc0 = Max(a3, DAT_002ea300 + DAT_002ea2f0);
    } else {
        o->fc0 = a3;
    }
    Vec4 zero;
    const Vec4 *src;
    if (p != 0) {
        src = p;
    } else {
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;
        zero.w = 0.0f;
        src = &zero;
    }
    o->fd0 = src->x;
    o->fd4 = src->y;
    o->fd8 = src->z;
    o->fdc = src->w;
    o->fb1 = 0;
    FUN_001cd88c(o, 6, 1);
    FUN_001c2498(o);
    if (FUN_001c39f8(o->fb8) != 0) {
        FUN_002879e0(0.0f, (char *)DAT_0033b574 + 0x1320, 0, DAT_002ea2f0,
                     Max(a3 - (DAT_002ea2f0 + DAT_002ea300), DAT_002ea304), 0);
    }
}

// NEAR MISS, 1 word off (retail 0x1c26b8 is `subu a0,a0,a2` where this gives `addu v1,a2,v1`).
// This form `a3 - (DAT_002ea2f0 + DAT_002ea300)` has retail's registers (a3 in a0, DAT_002ea300 in v1) but the wrong
// operation sequence. The natural chain `(a3 - DAT_002ea2f0) - DAT_002ea300` gives the right operations but 4 words of
// register naming (ours: a3 chain in v1, DAT_002ea300 in v0, result in a0; retail: whole chain in a0, DAT_002ea300 in v1).
// Ruled out for the chain (all 4 words off): named locals (also 'rest -= x' compound forms), cached DAT_002ea2f0/300 in
// locals in either order, unsigned/short global types, an inline Sub3(a,b,c) helper, `a3 + -x + -y`, locals declared at
// the function top. Matching facts: Max returns `const int &` (a < b ? b : a) so operands get stack slots (sum at sp+60,
// chain value at sp+56 only when both are NAMED temps/args in that creation order), Vec4 needs aligned(16) for the
// zero vector at sp+32 (frame 64), `const Vec4 *src; if (p != 0) src = p; else {zero stores; src = &zero;}` gives
// retail's beqzl layout (`if (p == 0)` gives bnezl).
