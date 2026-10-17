/* HSTMATCH module=hstp_trans_main.prx start=0x0005b9c4 end=0x0005bb74 symbol=FUN_0005b9c4 lang=c99 */
/* Clone of src/eboot/matrix_obj_ctor_0005aa44.c (hstclone.py tag u6fr2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the pool capacity is read through the inline getter Cap() inside Reserve(), so the second load is not CSE'd); names and types await human review. */
typedef struct Vec4 { float x, y, z, w; } Vec4;
typedef struct Mat4 { Vec4 r0, r1, r2, r3; } Mat4;

typedef struct Obj {
    void *vptr;
    int pad4[3];
    Mat4 m;
    unsigned int f50;
    unsigned int f54;
    unsigned int f58;
    unsigned int f5c;
    int pad60;
    unsigned int f64[2];
} Obj;

typedef struct Pool {
    int f0;
    int f4;
    unsigned int f8;
} Pool;

extern Mat4 DAT_002cc260;
extern char DAT_003b02e8;
extern char DAT_003b0308;
extern Pool DAT_003da6a4;
extern void FUN_0005bc80(Pool *, int);
extern void FUN_0005b224(Obj *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

static inline unsigned int Cap(const Pool *p)
{
    return p->f8;
}

static inline void Reserve(Pool *p, unsigned int n)
{
    if (Cap(p) < n) {
        FUN_0005bc80(p, n);
    }
}

Obj *FUN_0005b9c4(Obj *param_1, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
    unsigned int i;
    param_1->vptr = &DAT_003b0308;
    if (DAT_003da6a4.f8 == 0) {
        Reserve(&DAT_003da6a4, 0x400);
    }
    param_1->m.r0 = DAT_002cc260.r0;
    param_1->m.r1 = DAT_002cc260.r1;
    param_1->m.r2 = DAT_002cc260.r2;
    param_1->m.r3 = DAT_002cc260.r3;
    param_1->f50 = 0;
    param_1->f54 = 0;
    param_1->f58 = 0;
    param_1->f5c = 0;
    i = 0;
    do {
        param_1->f64[i] = 0;
    } while (++i < 2);
    param_1->vptr = &DAT_003b02e8;
    FUN_0005b224(param_1, a1, a2, a3, a4, a5);
    return param_1;
}
