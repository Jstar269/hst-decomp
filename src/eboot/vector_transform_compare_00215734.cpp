/* HSTMATCH module=EBOOT.BIN start=0x00215734 end=0x00215888 symbol=FUN_00215734 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};

extern int DAT_003386b0;
extern "C" void FUN_00022450(Vec4 *dst, const float *src, const void *mtx);
extern "C" void FUN_00022434(Vec4 *dst, const float *src, const void *mtx);
extern "C" void FUN_000224f8(Vec4 *dst, const Vec4 *a, const Vec4 *b);
extern "C" int FUN_00215734(char *self) {
    const float *obj = (const float *)(*(int *)(DAT_003386b0 + 0x88));
    Vec4 c2, c1, r1, i3, i2, i1, o3, o2, o1;
    i3 = *(const Vec4 *)(obj + 8);
    FUN_00022450(&o3, &i3.x, self + 0x5a0);
    c2.x = o3.x;
    c2.y = 0;
    c2.z = o3.z;
    c2.w = o3.w;
    i1 = *(const Vec4 *)(obj + 4);
    FUN_00022450(&o1, &i1.x, self + 0x5a0);
    i2 = o1;
    FUN_00022434(&o2, (const float *)(self + 0x580), &i2.x);
    c1.x = o2.x;
    c1.y = 0;
    c1.z = o2.z;
    c1.w = o2.w;
    FUN_000224f8(&r1, &c1, &c2);
    return (r1.y > 0.0f) == (*(const float *)(self + 0x580) > 0.0f);
}
