/* HSTMATCH module=hstp_trans_main.prx start=0x002245c0 end=0x00224714 symbol=FUN_002245c0 lang=c++ */
/* Clone of src/eboot/vector_transform_compare_00215734.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};

extern int DAT_003e19f0;
extern "C" void FUN_00022478(Vec4 *dst, const float *src, const void *mtx);
extern "C" void FUN_0002245c(Vec4 *dst, const float *src, const void *mtx);
extern "C" void FUN_00022520(Vec4 *dst, const Vec4 *a, const Vec4 *b);
extern "C" int FUN_002245c0(char *self) {
    const float *obj = (const float *)(*(int *)(DAT_003e19f0 + 0x88));
    Vec4 c2, c1, r1, i3, i2, i1, o3, o2, o1;
    i3 = *(const Vec4 *)(obj + 8);
    FUN_00022478(&o3, &i3.x, self + 0x5a0);
    c2.x = o3.x;
    c2.y = 0;
    c2.z = o3.z;
    c2.w = o3.w;
    i1 = *(const Vec4 *)(obj + 4);
    FUN_00022478(&o1, &i1.x, self + 0x5a0);
    i2 = o1;
    FUN_0002245c(&o2, (const float *)(self + 0x580), &i2.x);
    c1.x = o2.x;
    c1.y = 0;
    c1.z = o2.z;
    c1.w = o2.w;
    FUN_00022520(&r1, &c1, &c2);
    return (r1.y > 0.0f) == (*(const float *)(self + 0x580) > 0.0f);
}
