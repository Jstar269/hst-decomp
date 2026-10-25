/* HSTMATCH module=EBOOT.BIN start=0x000a8080 end=0x000a817c symbol=FUN_000a8080 lang=c++ */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern int DAT_003386b0;
extern float DAT_003411cc[];
extern int FUN_000b3c68(void);
extern float FUN_00163d68(int, int);
extern Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
extern Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
extern float sqrtf(float);
}

extern "C" int FUN_000a8080(char *self, const Vec4 *pos, int limit)
{
    int base = *(int *)(*(int *)(DAT_003386b0 + 0x88) + 0x268);
    int remaining = limit - base;
    float scale = (float)FUN_00163d68(FUN_000b3c68(), *(int *)(self + 0x154)) * 0.01f;
    Vec4 b, a, d;

    if (*(int *)(self + 0x440) > 0)
        scale = scale * (0.01f * DAT_003411cc[*(int *)(self + 0x440)]);
    FUN_00022450(&a, (const Vec4 *)(self + 0x580), (const Vec4 *)(self + 0x5a0));
    b = a;
    FUN_00022434(&d, pos, &b);
    return remaining - (int)(sqrtf(d.x * d.x + d.z * d.z) / scale);
}
// NEAR (63 words, 2 differ): the body and 80-byte frame match. Only the two argument-copy moves
// at 0x000a80a0/0x000a80a4 are reversed: retail saves pos from a1 to s1, then self from a0 to s2;
// this source saves self first. The exact tail uses sqrtf as an intrinsic, rest = limit - base
// immediately after the pointer-chain load, b/a/d Vec4 locals in that declaration order, and
// scale * (0.01f * table[count]). Pointer aliases, register parameters, and alternate local order
// did not change the two-word prologue difference.
// Final revisit: wrapping the reconstruction in an inline C++ member and calling it from the address-named wrapper keeps 2 differences.
// near miss from lane lnm1 (unreviewed)
