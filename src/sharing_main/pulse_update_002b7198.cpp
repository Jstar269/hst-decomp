/* HSTMATCH module=hstp_trans_main.prx start=0x002b7198 end=0x002b72cc symbol=FUN_002b7198 lang=c++ */
/* Clone of src/eboot/pulse_update_002a7a08.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003eaad8;
extern "C" {
void FUN_002b65c4(Obj *);
void FUN_001bfc3c(int *, int);
void FUN_00111aa4(int, int, int);
float FUN_0000bf4c(float);
float fabsf(float);
void FUN_00108a2c(Obj *);

static inline void Shift(Rec *r, float v)
{
    short nv = (short)v;
    short old = r->h4;
    r->h4 = nv;
    r->h8 += (short)(nv - old);
}

void FUN_002b7198(Obj *self)
{
    int a = self->f1674;
    int b = self->f166c;
    FUN_002b65c4(self);
    if (a != self->f1674 || b != self->f166c) {
        FUN_001bfc3c(&DAT_003eaad8, 1);
        FUN_00111aa4(self->f358, self->f1674, 0);
    }
    self->f35c->f224 = (float)self->f166c;
    float amp = 6.0f * fabsf(FUN_0000bf4c(0.2f * (float)self->f1688));
    Shift(self->f1d0, (float)self->f168c - amp);
    Shift(self->f1d4, (float)self->f1690 + amp);
    self->f1688 = self->f1688 + 1;
    FUN_00108a2c(self);
}
}
