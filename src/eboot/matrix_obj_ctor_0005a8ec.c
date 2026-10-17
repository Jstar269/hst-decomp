/* HSTMATCH module=EBOOT.BIN start=0x0005a8ec end=0x0005aa44 symbol=FUN_0005a8ec lang=c99 */
/* Clone of src/sharing_main/matrix_obj_ctor_0005b6bc.c (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (adapted from the sibling constructor src/sharing_main/matrix_obj_ctor_0005b814.c, same body without the trailing init call; matching idiom: the pool capacity is read through the inline getter Cap() inside Reserve(), so the second load is not CSE'd); names and types await human review. */
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

extern Mat4 DAT_002bc410;
extern char DAT_0030702c;
extern char DAT_0030703c;
extern Pool DAT_00331364;
extern void FUN_0005aff8(Pool *, int);

static inline unsigned int Cap(const Pool *p)
{
    return p->f8;
}

static inline void Reserve(Pool *p, unsigned int n)
{
    if (Cap(p) < n) {
        FUN_0005aff8(p, n);
    }
}

Obj *FUN_0005a8ec(Obj *param_1)
{
    unsigned int i;
    param_1->vptr = &DAT_0030703c;
    if (DAT_00331364.f8 == 0) {
        Reserve(&DAT_00331364, 0x400);
    }
    param_1->m.r0 = DAT_002bc410.r0;
    param_1->m.r1 = DAT_002bc410.r1;
    param_1->m.r2 = DAT_002bc410.r2;
    param_1->m.r3 = DAT_002bc410.r3;
    param_1->f50 = 0;
    param_1->f54 = 0;
    param_1->f58 = 0;
    param_1->f5c = 0;
    i = 0;
    do {
        param_1->f64[i] = 0;
    } while (++i < 2);
    param_1->vptr = &DAT_0030702c;
    return param_1;
}
