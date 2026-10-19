/* HSTMATCH module=hstp_trans_main.prx start=0x00277a98 end=0x00277af4 symbol=FUN_00277a98 lang=c99 */
/* Clone of src/eboot/mat4_compose_00266b1c.c (hstclone.py tag s10181937g11r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float m[16]; } Mat4;
typedef struct {
    unsigned char pad0[0x70];
    void *obj;                 /* 0x70 */
    unsigned char pad1[0xbc];  /* -> 0x130 */
    float trans[4];            /* 0x130 */
    unsigned char pad2[0x24];  /* -> 0x164 */
    float angle;               /* 0x164 */
    unsigned char pad3[8];     /* -> 0x170 */
    Mat4 a;                    /* 0x170 */
    Mat4 b;                    /* 0x1b0 */
} Self;

extern Mat4 *mat4_mul_0022570(Mat4 *dst, const Mat4 *l, const Mat4 *r);
extern Mat4 *mat4_rot_y_004d2cc(Mat4 *dst, const Mat4 *src, float angle);
extern Mat4 *mat4_copy_004d270(Mat4 *dst, const Mat4 *src, const float *trans);
extern Mat4 *mat4_store_0055044(void *obj, const Mat4 *src);

void FUN_00277a98(Self *s)
{
    Mat4 m;

    mat4_mul_0022570(&m, &s->a, &s->b);
    mat4_rot_y_004d2cc(&m, &m, s->angle);
    mat4_copy_004d270(&m, &m, s->trans);
    mat4_store_0055044(s->obj, &m);
}
