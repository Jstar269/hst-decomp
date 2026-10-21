/* HSTMATCH module=EBOOT.BIN start=0x002a7a08 end=0x002a7b3c symbol=FUN_002a7a08 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rec { char pad0[4]; short h4; short pad6; short h8; };
struct Thing { char pad[224]; float f224; };
struct Obj {
    char pad0[0x1d0];
    Rec *f1d0;
    Rec *f1d4;
    char pad1[0x358 - 0x1d8];
    int f358;
    Thing *f35c;
    char pad2[0x166c - 0x360];
    int f166c;
    int pad3;
    int f1674;
    char pad4[0x1688 - 0x1678];
    int f1688;
    int f168c;
    int f1690;
};
extern int DAT_0034179c;
extern "C" {
void FUN_002a6e34(Obj *);
void FUN_001b1c44(int *, int);
void FUN_0010b8cc(int, int, int);
float FUN_0000bf34(float);
float fabsf(float);
void FUN_00103128(Obj *);

static inline void Shift(Rec *r, float v)
{
    short nv = (short)v;
    short old = r->h4;
    r->h4 = nv;
    r->h8 += (short)(nv - old);
}

void FUN_002a7a08(Obj *self)
{
    int a = self->f1674;
    int b = self->f166c;
    FUN_002a6e34(self);
    if (a != self->f1674 || b != self->f166c) {
        FUN_001b1c44(&DAT_0034179c, 1);
        FUN_0010b8cc(self->f358, self->f1674, 0);
    }
    self->f35c->f224 = (float)self->f166c;
    float amp = 6.0f * fabsf(FUN_0000bf34(0.2f * (float)self->f1688));
    Shift(self->f1d0, (float)self->f168c - amp);
    Shift(self->f1d4, (float)self->f1690 + amp);
    self->f1688 = self->f1688 + 1;
    FUN_00103128(self);
}
}
