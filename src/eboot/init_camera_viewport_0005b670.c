/* HSTMATCH module=EBOOT.BIN start=0x0005b670 end=0x0005b9d0 symbol=FUN_0005b670 lang=c99 */
/* Clone of src/sharing_main/init_camera_viewport_0005c2f8.c (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from disassembly and pseudocode; exact match verified; names and types await human review. */

extern float FUN_0000c000(float f);
extern void FUN_0005bbd4(void *self, float f0, float f1, float f2, float f3, float f4, float f5);
extern void FUN_0003521c(void *self);
extern void FUN_0005c76c(void *self, float f0, float f1, float f2, float f3);
extern void FUN_0005c854(void *self, int idx, const void *v1, const void *v2);
extern void FUN_0005c900(void *self, int val);
extern void FUN_0005ca5c(void *self, int val);
extern void FUN_000341d8(void *p);
extern void FUN_0005ce18(void *self, float f0, float f1, float f2, float f3);
extern void FUN_0005ce2c(void *self, float f0, float f1, float f2);
extern void FUN_0005bc58(void *self);

typedef struct Vec4 {
    float x, y, z, w;
} Vec4;

typedef struct Mat4 {
    Vec4 r0, r1, r2, r3;
} Mat4;

extern Mat4 DAT_002bc410;

typedef struct Obj {
    char pad_0[16];
    int f_10;
    void *f_14;
    char pad_18[0x30 - 0x18];
    char f_30[0xd0 - 0x30];
    Mat4 mat1; // 0xd0 (208)
    Mat4 mat2; // 0x110 (272)
    char pad_150[0x1d0 - 0x150];
    float f_1d0;
    float f_1d4;
    float f_1d8;
    float f_1dc;
    float f_1e0;
    float f_1e4;
    float f_1e8;
    float f_1ec;
    float f_1f0;
    float f_1f4;
    float f_1f8;
    float f_1fc;
    float f_200;
    float f_204;
    float f_208;
    int f_20c;
    int f_210;
    float f_214;
    char pad_218[0x2b0 - 0x218];
    char f_2b0;
} Obj;

Obj *FUN_0005b670(Obj *self) {
    self->f_1d0 = 0.0f;
    self->f_1d4 = 0.0f;
    self->f_1d8 = 0.0f;
    self->f_1dc = 1.0f;
    self->f_1e0 = 0.0f;
    self->f_1e4 = 0.0f;
    self->f_1e8 = 1.0f;
    self->f_1ec = 0.0f;
    self->f_1f0 = 0.0f;
    self->f_1f4 = 1.0f;
    self->f_1f8 = 0.0f;
    self->f_1fc = 0.0f;
    self->f_200 = 64.0f;

    float tan_val = FUN_0000c000(self->f_200 * 0.008726646f);
    self->f_214 = tan_val;
    self->f_204 = 0.3f;
    self->f_208 = 2000.0f;
    self->f_20c = 0xff00;
    self->f_210 = 0xff;

    FUN_0005bbd4(self, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
    FUN_0003521c(self);
    FUN_0005c76c(self, 0.5f, 0.5f, 0.5f, 1.0f);

    self->f_10 = 0;
    self->f_14 = (char *)self + 144;

    Vec4 v1;
    Vec4 v2;
    v2.x = 0.5f;
    v2.y = 0.5f;
    v2.z = 0.5f;
    v1.x = -1.0f;
    v1.z = -1.0f;
    v1.y = 1.0f;
    v2.w = 0.0f;
    v1.w = 0.0f;

    FUN_0005c854(self, 0, &v1, &v2);

    Vec4 v3;
    Vec4 v4;
    v3.x = 1.0f;
    v3.z = 1.0f;
    v3.y = -1.0f;
    v4.x = 0.0f;
    v4.y = 0.0f;
    v4.z = 0.0f;
    v4.w = 0.0f;
    v3.w = 0.0f;

    FUN_0005c854(self, 1, &v3, &v4);

    FUN_0005c900(self, 0);
    FUN_0005ca5c(self, 0);
    FUN_000341d8(&self->f_30);

    FUN_0005ce18(self, 0.0f, 0.0f, 0.0f, 1.0f);
    FUN_0005ce2c(self, 1.0f, 1.0f, 1.0f);

    self->f_2b0 = 0;

    self->mat1.r0 = DAT_002bc410.r0;
    self->mat1.r1 = DAT_002bc410.r1;
    self->mat1.r2 = DAT_002bc410.r2;
    self->mat1.r3 = DAT_002bc410.r3;

    self->mat2.r0 = DAT_002bc410.r0;
    self->mat2.r1 = DAT_002bc410.r1;
    self->mat2.r2 = DAT_002bc410.r2;
    self->mat2.r3 = DAT_002bc410.r3;

    FUN_0005bc58(self);

    return self;
}
