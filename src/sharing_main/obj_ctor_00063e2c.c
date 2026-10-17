/* HSTMATCH module=hstp_trans_main.prx start=0x00063e2c end=0x00063ed0 symbol=FUN_00063e2c lang=c99 */
/* Clone of src/eboot/obj_ctor_00062f68.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *DAT_003b0378;
extern void *__nw__FUi(unsigned int);
extern void *FUN_000518d4(void *);
extern void FUN_00051d38(void *, float);

struct Obj {
    void *vptr;
    void *sub;
    int f8;
    int fc;
    float f10;
    int pad[3];
    int f20[8];
    char f40;
    char f41;
    char pad2[2];
    float f44;
};

typedef struct Obj Obj;

Obj *FUN_00063e2c(Obj *self)
{
    self->vptr = &DAT_003b0378;
    self->sub = 0;
    void *p = __nw__FUi(72);
    if (p) p = FUN_000518d4(p);
    self->sub = p;
    FUN_00051d38(p, 203000.0f);
    self->f8 = 0;
    self->fc = 0;
    self->f10 = -1.0f;
    self->f20[0] = 0;
    self->f20[1] = 0;
    self->f20[2] = 0;
    self->f20[3] = 0;
    self->f20[4] = 0;
    self->f20[5] = 0;
    self->f20[6] = 0;
    self->f20[7] = 0;
    self->f40 = 0;
    self->f41 = 0;
    self->f44 = 4000.0f;
    return self;
}
