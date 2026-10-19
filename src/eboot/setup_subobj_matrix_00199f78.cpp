/* HSTMATCH module=EBOOT.BIN start=0x00199f78 end=0x0019a19c symbol=FUN_00199f78 lang=c++ */
/* Hand-written reconstruction from the disassembly (callee of obj_setup_vcalls_00199e0c.cpp and caller of VFPU matrix multiply); exact match verified; names and types await human review. */
struct V4 {
    float x, y, z, w;
    V4() {}
};

struct M4 {
    V4 r0, r1, r2, r3;
};

struct SubObj {
    char pad[0x30];
    M4 mtx;
    char pad2[8];
    float scale;
};

struct Self {
    char pad[4];
    SubObj **sub;
    char pad2[0x5c - 8];
    float scale;
    M4 mtx;
};

extern "C" {
extern const M4 DAT_002bc410;
void FUN_00022570(M4 *, M4 *, const M4 *);
void FUN_00103480(Self *);
}

extern "C" void FUN_00199f78(Self *self)
{
    M4 scale_mat = DAT_002bc410;
    scale_mat.r0.x = self->scale;
    scale_mat.r1.y = self->scale;

    SubObj *s = *self->sub;
    M4 *m = (M4 *)s;
    if (s != 0) {
        m = (M4 *)((char *)m + 48);
    }
    *m = DAT_002bc410;

    (*self->sub)->mtx.r3.x = 240.0f;
    (*self->sub)->mtx.r3.y = 136.0f;
    (*self->sub)->scale = self->scale;

    FUN_00022570(&(*self->sub)->mtx, &(*self->sub)->mtx, &scale_mat);
    FUN_00022570(&(*self->sub)->mtx, &(*self->sub)->mtx, &self->mtx);
    FUN_00103480(self);
}
