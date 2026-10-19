/* HSTMATCH module=EBOOT.BIN start=0x0021fb9c end=0x0021fd1c symbol=setup_effect_matrix_0021fb9c lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Copy the default 4x4 matrix, replace the translation row with the position argument, and dispatch to effect systems. */

struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    struct Vec4 r[4];
};

extern const struct Mat4 DAT_002bc410;

extern "C" {
extern void FUN_00055044(int, const struct Mat4 *);
extern unsigned char FUN_00057b58(float, int, int, int);
extern void FUN_00058f38(float, int, int);
extern void FUN_00058ec4(float, int, int);
extern void FUN_00058ddc(int, unsigned char, int);
extern void FUN_00059084(int, int);
}

struct Obj {
    char pad[0x8c];
    int target;
};

extern "C" void setup_effect_matrix_0021fb9c(struct Obj *self, const struct Vec4 *pos)
{
    struct Vec4 local_pos = *pos;
    struct Mat4 mat;
    for (int i = 0; i < 4; i++) {
        mat.r[i] = DAT_002bc410.r[i];
    }
    mat.r[3] = local_pos;
    FUN_00055044(self->target, &mat);
    FUN_00057b58(0.0f, self->target, 0, 0);
    FUN_00058f38(0.0f, self->target, -1);
    FUN_00058ec4(1.0f, self->target, -1);
    FUN_00058ddc(self->target, 0, -1);
    FUN_00059084(self->target, -1);
}
