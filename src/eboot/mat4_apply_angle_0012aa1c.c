/* HSTMATCH module=EBOOT.BIN start=0x0012aa1c end=0x0012aa6c symbol=FUN_0012aa1c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { float m[16]; } Mat4;
typedef struct {
    unsigned char pad0[0x1b0];
    float trans[4];
    unsigned char pad1[0x24];
    float angle;
} Self;

extern Mat4 DAT_002bc410;
extern Mat4 *mat4_rot_y_004d2cc(Mat4 *, const Mat4 *, float);
extern Mat4 *mat4_copy_004d270(Mat4 *, const Mat4 *, const float *);
extern void FUN_00093434(Self *, const Mat4 *);

void FUN_0012aa1c(Self *s)
{
    Mat4 m;

    mat4_rot_y_004d2cc(&m, &DAT_002bc410, s->angle);
    mat4_copy_004d270(&m, &m, s->trans);
    FUN_00093434(s, &m);
}
