/* HSTMATCH module=hstp_trans_main.prx start=0x000935b4 end=0x00093734 symbol=FUN_000935b4 lang=c99 */
/* Clone of src/eboot/obj_take_0009191c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: plain-C struct with Vec4/Vec3/Vec2 members assigned whole (batched lwc1/swc1) and signed char at +0x74, float resets; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct { float x, y, z; } Vec3;
typedef struct { float x, y; } Vec2;
typedef struct {
    int pad0;
    Vec4 a;
    Vec3 b;
    int c20, c24, c28;
    int pad2c;
    Vec4 d;
    Vec4 e;
    Vec4 f;
    Vec2 g;
    int h68, h6c, h70;
    signed char i74;
    unsigned char i75;
    char pad76[0x80 - 0x76];
    char sub0[0x30];
    char sub1[0x30];
} Obj;

extern void FUN_00093734(void *, void *);
extern void FUN_0009378c(Obj *);
extern void FUN_00093860(Obj *);
extern void FUN_00093954(Obj *);
extern void FUN_00093ef0(Obj *);

void FUN_000935b4(Obj *dst, Obj *src)
{
    FUN_00093860(dst);
    dst->a = src->a;
    dst->b = src->b;
    dst->c20 = src->c20;
    dst->c24 = src->c24;
    dst->c28 = src->c28;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->h68 = src->h68;
    dst->h6c = src->h6c;
    dst->h70 = src->h70;
    dst->i74 = src->i74;
    dst->i75 = src->i75;
    FUN_00093734(dst->sub0, src->sub0);
    FUN_00093734(dst->sub1, src->sub1);
    dst->c28 = 0;
    dst->d.x = -1.0f;
    dst->d.y = -1.0f;
    dst->d.z = -1.0f;
    dst->d.w = -1.0f;
    dst->e.x = 0.0f;
    dst->e.y = 1.0f;
    dst->e.z = 0.0f;
    dst->e.w = 0.0f;
    FUN_00093954(dst);
    dst->i74 = 0;
    FUN_00093ef0(dst);
    FUN_0009378c(src);
    FUN_00093954(src);
}
