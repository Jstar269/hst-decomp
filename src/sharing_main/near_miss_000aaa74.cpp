/* HSTMATCH module=hstp_trans_main.prx start=0x000aaa74 end=0x000aab70 symbol=FUN_000aaa74 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/near_miss_000a8080.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern int DAT_003e19f0;
extern float DAT_003ea50c[];
extern int FUN_000b6e80(char *);
extern float FUN_001703f0(int, int);
extern Vec4 *FUN_00022478(Vec4 *, const Vec4 *, const Vec4 *);
extern Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
extern float sqrtf(float);
}

extern "C" int FUN_000aaa74(char *self, const Vec4 *pos, int limit)
{
    int base = *(int *)(*(int *)(DAT_003e19f0 + 0x88) + 0x268);
    int remaining = limit - base;
    float scale = (float)FUN_001703f0(FUN_000b6e80(self), *(int *)(self + 0x154)) * 0.01f;
    Vec4 b, a, d;

    if (*(int *)(self + 0x440) > 0)
        scale = scale * (0.01f * DAT_003ea50c[*(int *)(self + 0x440)]);
    FUN_00022478(&a, (const Vec4 *)(self + 0x580), (const Vec4 *)(self + 0x5a0));
    b = a;
    FUN_0002245c(&d, pos, &b);
    return remaining - (int)(sqrtf(d.x * d.x + d.z * d.z) / scale);
}
