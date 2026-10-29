/* HSTMATCH module=EBOOT.BIN start=0x000c35d0 end=0x000c3728 symbol=FUN_000c35d0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float v[4]; };
struct Mat4 { Vec4 r[4]; };
struct Quad { float x, y, z, w; };
struct Obj { char pad[0xd0]; Mat4 basis; };
extern "C" Vec4 *FUN_00022518(Vec4 *dst, const Vec4 *src);
extern "C" Vec4 *FUN_000224f8(Vec4 *dst, const Vec4 *a, const Vec4 *b);

/* Builds an orthonormal basis (up = y axis, forward = the horizontal direction dir) into the object's basis matrix, with a cleared last row. */
extern "C" void FUN_000c35d0(Obj *self, float *dir)
{
    if (dir[0] != 0.0f || dir[2] != 0.0f) {
        Mat4 m;
        FUN_00022518(&m.r[2], (Vec4 *)dir);
        m.r[2].v[3] = 0.0f;
        m.r[1].v[0] = 0.0f; m.r[1].v[1] = 1.0f; m.r[1].v[2] = 0.0f; m.r[1].v[3] = 0.0f;
        FUN_00022518(&m.r[2], &m.r[2]);
        m.r[2].v[3] = 0.0f;
        FUN_000224f8(&m.r[0], &m.r[1], &m.r[2]);
        FUN_00022518(&m.r[0], &m.r[0]);
        m.r[0].v[3] = 0.0f;
        FUN_000224f8(&m.r[1], &m.r[2], &m.r[0]);
        *(Quad *)&m.r[3] = *(Quad *)&m.r[3];
        self->basis.r[0] = m.r[0];
        self->basis.r[1] = m.r[1];
        self->basis.r[2] = m.r[2];
        self->basis.r[3] = m.r[3];
        self->basis.r[3].v[0] = 0.0f; self->basis.r[3].v[1] = 0.0f; self->basis.r[3].v[2] = 0.0f; self->basis.r[3].v[3] = 0.0f;
    }
}
