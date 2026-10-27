/* HSTMATCH module=EBOOT.BIN start=0x000a8080 end=0x000a817c symbol=FUN_000a8080 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the first call takes the object (FUN_000b3c68(self)) - the argument Ghidra dropped - so a0 is used directly and its home copy moves behind a1's. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern int DAT_003386b0;
extern float DAT_003411cc[];
extern int FUN_000b3c68(char *);
extern float FUN_00163d68(int, int);
extern Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
extern Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
extern float sqrtf(float);
}

extern "C" int FUN_000a8080(char *self, const Vec4 *pos, int limit)
{
    int base = *(int *)(*(int *)(DAT_003386b0 + 0x88) + 0x268);
    int remaining = limit - base;
    float scale = (float)FUN_00163d68(FUN_000b3c68(self), *(int *)(self + 0x154)) * 0.01f;
    Vec4 b, a, d;

    if (*(int *)(self + 0x440) > 0)
        scale = scale * (0.01f * DAT_003411cc[*(int *)(self + 0x440)]);
    FUN_00022450(&a, (const Vec4 *)(self + 0x580), (const Vec4 *)(self + 0x5a0));
    b = a;
    FUN_00022434(&d, pos, &b);
    return remaining - (int)(sqrtf(d.x * d.x + d.z * d.z) / scale);
}
