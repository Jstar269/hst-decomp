/* HSTMATCH module=hstp_trans_main.prx start=0x00135e88 end=0x00135ed8 symbol=FUN_00135e88 lang=c99 */
/* Clone of src/eboot/mat4_apply_angle_0012aa1c.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { float m[16]; } Mat4;
typedef struct {
    unsigned char pad0[0x1b0];
    float trans[4];
    unsigned char pad1[0x24];
    float angle;
} Self;

extern Mat4 DAT_002cc260;
extern Mat4 *mat4_rot_y_004d2cc(Mat4 *, const Mat4 *, float);
extern Mat4 *mat4_copy_004d270(Mat4 *, const Mat4 *, const float *);
extern void FUN_00095358(Self *, const Mat4 *);

void FUN_00135e88(Self *s)
{
    Mat4 m;

    mat4_rot_y_004d2cc(&m, &DAT_002cc260, s->angle);
    mat4_copy_004d270(&m, &m, s->trans);
    FUN_00095358(s, &m);
}
