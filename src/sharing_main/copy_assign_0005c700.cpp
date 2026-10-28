/* HSTMATCH module=hstp_trans_main.prx start=0x0005c700 end=0x0005c85c symbol=FUN_0005c700 lang=c++ */
/* Clone of src/eboot/copy_assign_0005ba78.cpp (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (DeepSeek V4.1 Flash (Freebuff), lane dsn2); exact match verified; names and types await human review. */
/* Copy-assign of a 0x2c0-byte object that holds two growable float arrays (count1/data1 at 0x18/0x1c with
   8 floats per entry, count2/data2 at 0x20/0x24 with 16 floats per entry) and a pointer at 0x14 to its own
   0x90 buffer: releases both arrays, copies the plain data, re-points the buffer, then re-creates and refills
   each array from the source through the item getters/setters. Matching idiom: the two scalar out-params of
   FUN_0005daf4 live in the upper half of a Vec4 (declaration order), which is what gives retail's 16-byte slot
   at 0x60 and the &v[3], &v[2] argument order. */
struct Vec4 {
    float v[4];
};

struct Self {
    char pad0[0x14];
    Vec4 *vecs;                 /* 0x14: points into this object at 0x90 */
    int count1;                 /* 0x18 */
    float *data1;               /* 0x1c */
    int count2;                 /* 0x20 */
    float *data2;               /* 0x24 */
    char pad28[0x90 - 0x28];
    char buf[0x230];            /* 0x90 */
};

extern "C" {
void FUN_000009e4(void *);
void FUN_00022a70(void *, const void *, unsigned);
void FUN_0005d68c(Self *, int);
void FUN_0005d7e8(Self *, int);
void FUN_0005da74(const Self *, int, float *, float *);
void FUN_0005d768(Self *, int, float *, float *);
void FUN_0005daf4(const Self *, int, float *, float *, float *, float *, float *);
void FUN_0005d83c(Self *, int, float *, float *, float *, float, float);
}

extern "C" Self *FUN_0005c700(Self *self, const Self *src)
{
    Vec4 tail;                  /* only the last two components are filled by FUN_0005daf4 */
    Vec4 a, b;
    Vec4 c, d, e;

    if (self->data1 != 0) {
        FUN_000009e4(self->data1);
        self->data1 = 0;
    }
    if (self->data2 != 0) {
        FUN_000009e4(self->data2);
        self->data2 = 0;
    }
    FUN_00022a70(self, src, 0x2c0);
    self->vecs = (Vec4 *)self->buf;

    if (self->count1 != 0) {
        self->data1 = 0;
        FUN_0005d68c(self, src->count1);
        for (int i = 0; i < self->count1; i++) {
            FUN_0005da74(src, i, a.v, b.v);
            FUN_0005d768(self, i, a.v, b.v);
        }
    }
    if (self->count2 != 0) {
        self->data2 = 0;
        FUN_0005d7e8(self, src->count2);
        for (int i = 0; i < self->count2; i++) {
            FUN_0005daf4(src, i, c.v, d.v, e.v, &tail.v[3], &tail.v[2]);
            FUN_0005d83c(self, i, c.v, d.v, e.v, tail.v[3], tail.v[2]);
        }
    }
    return self;
}
