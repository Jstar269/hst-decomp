/* HSTMATCH module=hstp_trans_main.prx start=0x000646f4 end=0x000647e0 symbol=FUN_000646f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad0[4];
    void *f4;
    float f8;
    float fc;
    float f10;
    char pad1[0xc];
    struct Vec4 v1;
    struct Vec4 v2;
    unsigned char b64;
    unsigned char b65;
    char pad2[2];
    float f68;
    char pad3[8];
    unsigned char b80;
    unsigned char b81;
    unsigned char b82;
    unsigned char b83;
    float f84;
};

extern void FUN_00051d40(void *, int);

void FUN_000646f4(struct Obj *self, const struct Vec4 *p1, const struct Vec4 *p2, int count,
                 float f1, unsigned char b1, float f2, unsigned char b2)
{
    self->v1.x = p1->x;
    self->v1.y = p1->y;
    self->v1.z = p1->z;
    self->v1.w = p1->w;
    self->v2.x = p2->x;
    self->v2.y = p2->y;
    self->v2.z = p2->z;
    self->v2.w = p2->w;
    float fc = (float)count;
    self->f8 = fc;
    self->fc = fc;
    self->f10 = -1.0f;
    FUN_00051d40(self->f4, 0);
    self->b64 = b1;
    self->b65 = 0;
    if (f2 < 0.0f) {
        f2 = 4000.0f;
    }
    self->f68 = f2;
    self->b80 = 0;
    self->b81 = 0;
    self->b82 = 1;
    self->b83 = b2;
    self->f84 = f1;
}
