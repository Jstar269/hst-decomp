/* HSTMATCH module=EBOOT.BIN start=0x000c35d0 end=0x000c3728 symbol=FUN_000c35d0 lang=c++ */
struct Vec4 { float x, y, z, w; };
struct Mat4 { Vec4 r[4]; };
struct Obj { char pad[0xd0]; Mat4 basis; };
extern "C" Vec4 *FUN_00022518(Vec4 *dst, const Vec4 *src);
extern "C" Vec4 *FUN_000224f8(Vec4 *dst, const Vec4 *a, const Vec4 *b);

extern "C" void FUN_000c35d0(Obj *param_1, float *param_2)
{
    if (param_2[0] != 0.0f || param_2[2] != 0.0f) {
        Mat4 m;
        FUN_00022518(&m.r[2], (Vec4 *)param_2);
        m.r[2].w = 0.0f;
        m.r[1].x = 0.0f; m.r[1].y = 1.0f; m.r[1].z = 0.0f; m.r[1].w = 0.0f;
        FUN_00022518(&m.r[2], &m.r[2]);
        m.r[2].w = 0.0f;
        FUN_000224f8(&m.r[0], &m.r[1], &m.r[2]);
        FUN_00022518(&m.r[0], &m.r[0]);
        m.r[0].w = 0.0f;
        FUN_000224f8(&m.r[1], &m.r[2], &m.r[0]);
        m.r[3] = m.r[3];
        Vec4 t; t = m.r[0]; param_1->basis.r[0] = t; t = m.r[1]; param_1->basis.r[1] = t;
        t = m.r[2]; param_1->basis.r[2] = t; t = m.r[3]; param_1->basis.r[3] = t;
        param_1->basis.r[3].x = 0.0f; param_1->basis.r[3].y = 0.0f; param_1->basis.r[3].z = 0.0f; param_1->basis.r[3].w = 0.0f;
    }
}
// near miss from lane bp1018ar1-1 (unreviewed)
