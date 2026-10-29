/* HSTMATCH module=hstp_trans_main.prx start=0x002381f0 end=0x00238610 symbol=FUN_002381f0 lang=c++ */
/* Clone of src/eboot/obj_event_transform_00228c7c.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (rewrites the s10171846g1r1-0 macro/goto near miss as a switch over the event with UpdateTransform/ResetTransform inline helpers; the identity matrix is an extern const Mat4 copied through Mat4's memberwise copy ctor, which gives the row-batched copy); exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
};

typedef struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
} Mat4;

typedef struct {
    char pad0[0x3c];
    int field_3c;           /* 0x3c */
    Vec4 pos;               /* 0x40 */
    Vec4 target_pos;        /* 0x50 */
    Mat4 matrix;            /* 0x60 */
    char pad_a0[0x10];      /* 0xa0 */
    char field_b0[0x364];   /* 0xb0 */
    void *field_414;        /* 0x414 */
    char pad_418[0xc];      /* 0x418 */
    int angle_deg;          /* 0x424 */
    int pad_428;            /* 0x428 */
    int field_42c;          /* 0x42c */
    int field_430;          /* 0x430 */
    unsigned char field_434;/* 0x434 */
    unsigned char field_435;/* 0x435 */
    unsigned char field_436;/* 0x436 */
    unsigned char field_437;/* 0x437 */
    char pad_438[0x21];     /* 0x438 */
    unsigned char field_459;/* 0x459 */
} Obj;

typedef struct {
    char pad[0x58];
    int field_58;
} GlobalSub;

typedef struct {
    char pad[0x9c];
    GlobalSub *sub;
} GlobalRoot;

extern GlobalRoot *DAT_003e19f0;
extern const Mat4 DAT_002cc260;

extern "C" void FUN_0004d64c(Mat4 *out, const Mat4 *in, float angle);
extern "C" void FUN_00055b64(void *obj, const Mat4 *m);

static inline void UpdateTransform(Obj *self)
{
    if (self->field_3c != 1) {
        self->field_3c = 1;
        self->field_434 = 1;
    }
    self->pos = self->target_pos;
    self->field_430 = 0;
    self->matrix = DAT_002cc260;
    FUN_0004d64c(&self->matrix, &self->matrix, (float)self->angle_deg * 0.017453292f);
    self->matrix.r3 = self->pos;
    FUN_00055b64(self->field_b0, &self->matrix);
    FUN_00055b64(self->field_414, &self->matrix);
}

static inline void ResetTransform(Obj *self)
{
    self->pos.y = 10.0f;
    self->matrix.r3 = self->pos;
    FUN_00055b64(self->field_b0, &self->matrix);
    FUN_00055b64(self->field_414, &self->matrix);
    self->field_435 = 0;
}

extern "C" int FUN_002381f0(Obj *self, int event)
{
    switch (event) {
    case 4:
        break;
    case 19:
        break;
    case 8:
        self->field_459 = 0;
        if (self->field_42c >= 0) {
            ResetTransform(self);
            self->field_437 = 1;
        }
        break;
    case 22:
    case 14:
        if (!self->field_437 && self->field_42c >= 0) {
            if (self->field_42c > DAT_003e19f0->sub->field_58) {
                UpdateTransform(self);
                self->field_435 = 1;
            } else if (!self->field_437) {
                ResetTransform(self);
            }
        }
        break;
    case 24:
        UpdateTransform(self);
        self->field_435 = 1;
        self->field_437 = 0;
        self->field_42c = -1;
        break;
    }
    return 0;
}
