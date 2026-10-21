/* HSTMATCH module=hstp_trans_main.prx start=0x000c6da0 end=0x000c6ef8 symbol=FUN_000c6da0 lang=c++ */
/* Clone of src/eboot/orient_matrix_000c35d0.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float v[4]; };
struct Mat4 { Vec4 r[4]; };
struct Quad { float x, y, z, w; };
struct Obj { char pad[0xd0]; Mat4 basis; };
extern "C" Vec4 *FUN_00022540(Vec4 *dst, const Vec4 *src);
extern "C" Vec4 *FUN_00022520(Vec4 *dst, const Vec4 *a, const Vec4 *b);

extern "C" void FUN_000c6da0(Obj *param_1, float *param_2)
{
    if (param_2[0] != 0.0f || param_2[2] != 0.0f) {
        Mat4 m;
        FUN_00022540(&m.r[2], (Vec4 *)param_2);
        m.r[2].v[3] = 0.0f;
        m.r[1].v[0] = 0.0f; m.r[1].v[1] = 1.0f; m.r[1].v[2] = 0.0f; m.r[1].v[3] = 0.0f;
        FUN_00022540(&m.r[2], &m.r[2]);
        m.r[2].v[3] = 0.0f;
        FUN_00022520(&m.r[0], &m.r[1], &m.r[2]);
        FUN_00022540(&m.r[0], &m.r[0]);
        m.r[0].v[3] = 0.0f;
        FUN_00022520(&m.r[1], &m.r[2], &m.r[0]);
        *(Quad *)&m.r[3] = *(Quad *)&m.r[3];
        param_1->basis.r[0] = m.r[0];
        param_1->basis.r[1] = m.r[1];
        param_1->basis.r[2] = m.r[2];
        param_1->basis.r[3] = m.r[3];
        param_1->basis.r[3].v[0] = 0.0f; param_1->basis.r[3].v[1] = 0.0f; param_1->basis.r[3].v[2] = 0.0f; param_1->basis.r[3].v[3] = 0.0f;
    }
}
