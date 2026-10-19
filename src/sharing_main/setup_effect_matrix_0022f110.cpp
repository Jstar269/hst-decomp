/* HSTMATCH module=hstp_trans_main.prx start=0x0022f110 end=0x0022f290 symbol=setup_effect_matrix_0022f110 lang=c++ */
/* Clone of src/eboot/setup_effect_matrix_0021fb9c.cpp (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Copy the default 4x4 matrix, replace the translation row with the position argument, and dispatch to effect systems. */

struct Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    struct Vec4 r[4];
};

extern const struct Mat4 DAT_002cc260;

extern "C" {
extern void FUN_00055b64(int, const struct Mat4 *);
extern unsigned char FUN_000587ac(float, int, int, int);
extern void FUN_00059c1c(float, int, int);
extern void FUN_00059ba8(float, int, int);
extern void FUN_00059ac0(int, unsigned char, int);
extern void FUN_00059d68(int, int);
}

struct Obj {
    char pad[0x8c];
    int target;
};

extern "C" void setup_effect_matrix_0022f110(struct Obj *self, const struct Vec4 *pos)
{
    struct Vec4 local_pos = *pos;
    struct Mat4 mat;
    for (int i = 0; i < 4; i++) {
        mat.r[i] = DAT_002cc260.r[i];
    }
    mat.r[3] = local_pos;
    FUN_00055b64(self->target, &mat);
    FUN_000587ac(0.0f, self->target, 0, 0);
    FUN_00059c1c(0.0f, self->target, -1);
    FUN_00059ba8(1.0f, self->target, -1);
    FUN_00059ac0(self->target, 0, -1);
    FUN_00059d68(self->target, -1);
}
