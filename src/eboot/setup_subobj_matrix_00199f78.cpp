/* HSTMATCH module=EBOOT.BIN start=0x00199f78 end=0x0019a19c symbol=FUN_00199f78 lang=c++ */
/* Hand-written reconstruction from the disassembly (callee of obj_setup_vcalls_00199e0c.cpp and caller of VFPU matrix multiply); exact match verified; names and types await human review. */
struct V4 {
    float x, y, z, w;
    V4() {}
};

struct M4 {
    V4 r0, r1, r2, r3;
};

/* Object that owns a transform matrix and a scale value. */
struct Target {
    char pad[0x30];
    M4 mtx;            /* 0x30 */
    char pad2[8];
    float scale;       /* 0x78 */
};

struct Screen {
    char pad[4];
    Target **target;   /* 0x04 handle of the object whose matrix is rebuilt */
    char pad2[0x5c - 8];
    float scale;       /* 0x5c */
    M4 mtx;            /* 0x60 */
};

extern "C" {
extern const M4 DAT_002bc410;
void FUN_00022570(M4 *, M4 *, const M4 *);
void FUN_00103480(Screen *);
}

/* Reset the target's matrix to identity with the screen centre (240, 136) as translation, then scale it and apply the screen matrix. */
extern "C" void FUN_00199f78(Screen *self)
{
    M4 scale_mat = DAT_002bc410;
    scale_mat.r0.x = self->scale;
    scale_mat.r1.y = self->scale;

    Target *target = *self->target;
    M4 *m = (M4 *)target;
    if (target != 0) {
        m = (M4 *)((char *)m + 48);
    }
    *m = DAT_002bc410;

    (*self->target)->mtx.r3.x = 240.0f;
    (*self->target)->mtx.r3.y = 136.0f;
    (*self->target)->scale = self->scale;

    FUN_00022570(&(*self->target)->mtx, &(*self->target)->mtx, &scale_mat);
    FUN_00022570(&(*self->target)->mtx, &(*self->target)->mtx, &self->mtx);
    FUN_00103480(self);
}
