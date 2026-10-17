/* HSTMATCH module=hstp_trans_main.prx start=0x001096ac end=0x001098a0 symbol=FUN_001096ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: base vtable and fields initialized, two 16-float matrices copied from DAT_002cc260 row-by-row with null-checked offset for the first matrix; exact match verified; names and types await human review. */

typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Mat4 { Vec4 r0, r1, r2, r3; } Mat4;

typedef struct Obj {
    void *vptr;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    char f1c;
    char pad1d[3];
    int f20;
    char f24;
    char pad25[11];
    Mat4 m1;
    int f70;
    int f74;
    int f78;
    int f7c;
    Mat4 m2;
    unsigned int fc0;
} Obj;

extern Mat4 DAT_002cc260;
extern char DAT_003b0e38;
extern char DAT_003b0a68;

Obj *FUN_001096ac(Obj *param_1, unsigned int param_2)
{
    param_1->vptr = &DAT_003b0e38;
    param_1->f4 = 0;
    param_1->f8 = 0;
    param_1->fc = 0;
    param_1->f10 = 0;
    param_1->f14 = 0;
    param_1->f18 = 0;
    param_1->f1c = 0;
    param_1->f20 = 0x47c35000;
    param_1->f24 = 0;

    param_1->vptr = &DAT_003b0a68;
    param_1->f70 = 0;
    param_1->f74 = -1;
    param_1->f78 = 0x3f800000;
    param_1->f7c = 0x3f800000;
    param_1->fc0 = param_2;

    Mat4 *m1 = (Mat4 *)param_1;
    if (param_1 != 0) {
        m1 = (Mat4 *)((char *)m1 + 48);
    }
    m1->r0 = DAT_002cc260.r0;
    m1->r1 = DAT_002cc260.r1;
    m1->r2 = DAT_002cc260.r2;
    m1->r3 = DAT_002cc260.r3;

    param_1->m2.r0 = DAT_002cc260.r0;
    param_1->m2.r1 = DAT_002cc260.r1;
    param_1->m2.r2 = DAT_002cc260.r2;
    param_1->m2.r3 = DAT_002cc260.r3;

    return param_1;
}
