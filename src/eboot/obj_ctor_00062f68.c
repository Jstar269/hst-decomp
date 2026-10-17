/* HSTMATCH module=EBOOT.BIN start=0x00062f68 end=0x0006300c symbol=FUN_00062f68 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern void *DAT_003070ac;
extern void *__nw__FUi(unsigned int);
extern void *FUN_00050fc0(void *);
extern void FUN_00051398(void *, float);

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

Obj *FUN_00062f68(Obj *self)
{
    self->vptr = &DAT_003070ac;
    self->sub = 0;
    void *p = __nw__FUi(72);
    if (p) p = FUN_00050fc0(p);
    self->sub = p;
    FUN_00051398(p, 203000.0f);
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
