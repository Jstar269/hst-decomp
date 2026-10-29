/* HSTMATCH module=EBOOT.BIN start=0x000a8080 end=0x000a817c symbol=FUN_000a8080 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the first call takes the object (FUN_000b3c68(self)) - the argument Ghidra dropped - so a0 is used directly and its home copy moves behind a1's. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

/* Object with an index at 0x154, a value at 0x440 and two positions at 0x580 and 0x5a0. */
struct SelfObj {
    char pad0[0x154];
    int unk154;             /* 0x154 */
    char pad158[0x440 - 0x158];
    int unk440;             /* 0x440 */
    char pad444[0x580 - 0x444];
    Vec4 pos_a;             /* 0x580 */
    char pad590[0x5a0 - 0x590];
    Vec4 pos_b;             /* 0x5a0 */
};

struct GameSub {
    char pad0[0x268];
    int unk268;             /* 0x268 */
};

struct GameObj {
    char pad0[0x88];
    GameSub *sub;           /* 0x88 */
};

extern "C" {
extern GameObj *DAT_003386b0;
extern float DAT_003411cc[];
extern int FUN_000b3c68(SelfObj *);
extern float FUN_00163d68(int, int);
extern Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
extern Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
extern float sqrtf(float);
}

/* Returns (limit - a base value from the game object) minus the horizontal distance from pos to the product of
   the two positions, divided by a scale from the context (reduced when the value at 0x440 is positive). */
extern "C" int FUN_000a8080(SelfObj *self, const Vec4 *pos, int limit)
{
    int base = DAT_003386b0->sub->unk268;
    int remaining = limit - base;
    float scale = (float)FUN_00163d68(FUN_000b3c68(self), self->unk154) * 0.01f;
    Vec4 b, a, d;

    if (self->unk440 > 0)
        scale = scale * (0.01f * DAT_003411cc[self->unk440]);
    FUN_00022450(&a, &self->pos_a, &self->pos_b);
    b = a;
    FUN_00022434(&d, pos, &b);
    return remaining - (int)(sqrtf(d.x * d.x + d.z * d.z) / scale);
}
