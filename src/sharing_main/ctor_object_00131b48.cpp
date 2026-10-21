/* HSTMATCH module=hstp_trans_main.prx start=0x00131b48 end=0x00131e9c symbol=FUN_00131b48 lang=c++ */
/* Clone of src/eboot/ctor_object_001268d8.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: member stores written as float/int word stores through two views of `this` (the lwc1/swc1 copies of the constant vectors and the lw/sw zero stores), the 0x22418 result is returned BY VALUE from an inline wrapper (`self->v1d0 = Sub(a, b)`: retail's batched f3,f2,f1,f0 copy and the lui hoisting follow); names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Obj { char pad[0x1d0]; Vec4 v1d0; };
static inline Vec4 Sub(float *a, float *b);
extern "C" {
extern float DAT_002cc260, DAT_002cc264, DAT_002cc268, DAT_002cc26c;
extern float DAT_002cc270, DAT_002cc274, DAT_002cc278, DAT_002cc27c;
extern float DAT_002cc280, DAT_002cc284, DAT_002cc288, DAT_002cc28c;
extern float DAT_002cc290, DAT_002cc294, DAT_002cc298, DAT_002cc29c;
extern float DAT_0038141c, DAT_00381424;
extern char DAT_003b131c[];
extern char DAT_003b1330[];
void FUN_000934c8(void);
void FUN_00297ebc(void *p);
void FUN_00022440(Vec4 *out, float *a, float *b);
void FUN_000dba70(void *p);
void FUN_00137748(void *p);
void FUN_001333a8(void *p);
}

static inline Vec4 Sub(float *a, float *b)
{
    Vec4 r;
    FUN_00022440(&r, a, b);
    return r;
}

extern "C" void *FUN_00131b48(void *self)
{
    int *w = (int *)self;
    float *f = (float *)self;
    FUN_000934c8();
    FUN_00297ebc(w + 0x38);
    *(void **)self = DAT_003b131c;
    *(void **)(w + 0x38) = DAT_003b1330;
    w[0x54] = 0;
    w[0x55] = 0;
    w[0x58] = 0;
    w[0x59] = 0;
    w[0x5a] = 0;
    w[0x5b] = 0;
    f[0x5c] = DAT_002cc280;
    f[0x5d] = DAT_002cc284;
    f[0x5e] = DAT_002cc288;
    f[0x5f] = DAT_002cc28c;
    f[0x60] = DAT_002cc260;
    f[0x61] = DAT_002cc264;
    f[0x62] = DAT_002cc268;
    f[0x63] = DAT_002cc26c;
    w[0x64] = 14;
    w[0x65] = 14;
    w[0x66] = 0;
    w[0x68] = 0;
    w[0x69] = 0;
    w[0x6a] = 0;
    w[0x6b] = 0;
    f[0x6c] = DAT_002cc290;
    f[0x6d] = DAT_002cc294;
    f[0x6e] = DAT_002cc298;
    f[0x6f] = DAT_002cc29c;
    f[0x70] = DAT_002cc290;
    f[0x71] = DAT_002cc294;
    f[0x72] = DAT_002cc298;
    f[0x73] = DAT_002cc29c;
    ((Obj *)self)->v1d0 = Sub(&DAT_002cc290, &DAT_002cc280);
    *(char *)(w + 0x78) = 0;
    w[0x79] = 0;
    w[0x7a] = 0;
    float n3 = -DAT_002cc27c;
    float n2 = -DAT_002cc278;
    float n1 = -DAT_002cc274;
    f[0x7c] = -DAT_002cc270;
    f[0x7d] = n1;
    f[0x7e] = n2;
    f[0x7f] = n3;
    f[0x80] = DAT_002cc280;
    f[0x81] = DAT_002cc284;
    f[0x82] = DAT_002cc288;
    f[0x83] = DAT_002cc28c;
    f[0x84] = DAT_002cc260;
    f[0x85] = DAT_002cc264;
    f[0x86] = DAT_002cc268;
    f[0x87] = DAT_002cc26c;
    *(char *)(w + 0x88) = 1;
    *((char *)w + 0x221) = 1;
    w[0x89] = 0;
    f[0x8c] = DAT_002cc290;
    f[0x8d] = DAT_002cc294;
    f[0x8e] = DAT_002cc298;
    f[0x8f] = DAT_002cc29c;
    n3 = -DAT_002cc27c;
    n2 = -DAT_002cc278;
    n1 = -DAT_002cc274;
    f[0x90] = -DAT_002cc270;
    f[0x91] = n1;
    f[0x92] = n2;
    f[0x93] = n3;
    w[0x94] = 0;
    *(char *)(w + 0x95) = 0;
    FUN_000dba70(w + 0x96);
    f[200] = DAT_0038141c;
    f[0xc9] = DAT_00381424;
    w[0xca] = 0x3f800000;
    *(char *)(w + 0xcb) = 0;
    *((char *)w + 0x32d) = 0;
    w[0xcc] = 0;
    w[0xcd] = -1;
    *(char *)(w + 0xce) = 0;
    *((char *)w + 0x339) = 0;
    w[0xcf] = 0;
    w[0xd0] = 0;
    w[0xd1] = 0;
    w[0xd2] = 0;
    *(char *)(w + 0xd3) = 0;
    w[0xd4] = -1;
    w[0xd5] = 0;
    w[0xd6] = 0;
    w[0xd7] = 0;
    w[0xd8] = 0;
    FUN_00137748(w + 0xdc);
    *(char *)(w + 0x104) = 1;
    w[0x105] = 0;
    w[0x106] = 0;
    w[0x107] = 0;
    *(char *)(w + 0xd9) = 0;
    *((char *)w + 0x365) = 0;
    *((char *)w + 0x366) = 0;
    *((char *)w + 0x367) = 0;
    *(char *)(w + 0xda) = 0;
    *((char *)w + 0x369) = 0;
    FUN_001333a8(self);
    return self;
}
