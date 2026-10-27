/* HSTMATCH module=hstp_trans_main.prx start=0x00051138 end=0x0005121c symbol=FUN_00051138 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Installs a new data block and, when it changed, rebuilds the objects derived from it; the guarded
   rebuild of +0x1a01c uses the +0x30 sub-record through a pointer local (MWCC then forms its address once
   in the first bc1t delay slot and reads +0x14 through it, as retail does). */
typedef struct {
    float v[4];
    float f10;
    float f14;
    float f18;
    float f1c;
} Sub30;

typedef struct {
    char pad0[0x30];
    Sub30 s30;
    char f50[0x80];
    char fd0[0x10];
} Data;

typedef struct {
    char pad[0x1a010];
    Data *cur;
    int f1a014;
    int f1a018;
    int f1a01c;
} Obj;

extern int FUN_0003f90c(Obj *self, char *a, char *b);
extern int FUN_00035638(Obj *self, Data *d);
extern int FUN_00034234(Obj *self, Sub30 *s);
extern void FUN_00051394(Obj *self);
extern void FUN_0005121c(Obj *self);

void FUN_00051138(Obj *self, Data *d)
{
    Sub30 *s;

    if (self->cur != d) {
        self->cur = d;
        self->f1a014 = FUN_0003f90c(self, self->cur->f50, self->cur->fd0);
        self->f1a018 = FUN_00035638(self, self->cur);
        self->f1a01c = 0;
        s = &self->cur->s30;
        if (s->f1c != 0.0f && s->f1c != s->f14) {
            self->f1a01c = FUN_00034234(self, s);
        }
        FUN_00051394(self);
        FUN_0005121c(self);
    }
}
