/* HSTMATCH module=hstp_trans_main.prx start=0x001c4584 end=0x001c473c symbol=FUN_001c4584 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/enter_state_001b68c4.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_00391590;
extern void *DAT_003e1e84;
extern void *DAT_003e47a0;
extern void *DAT_003eaad8;

extern int FUN_000e2c0c(void *, int);
extern int FUN_000e2708(void *, int);
extern int FUN_000e30f8(void *);
extern int FUN_001259ac(void *);
extern void FUN_001c21a8(void *);
extern void FUN_001c2280(void *, float, float);
extern void FUN_001c23fc(void *, int);
extern void FUN_001c63e4(void *);
extern void FUN_001c6408(void *);
extern void FUN_001c6440(void *, int);
extern void FUN_001c64d4(void *, int, int);
extern void FUN_001c6834(void *, int, int);
extern void FUN_001c71e4(void *, void *, void *, void *);
}

struct Obj {
    char pad0[0x50];
    int f50;
    char pad54[0x78 - 0x54];
    unsigned char f78;
    char pad79;
    unsigned char f7a;
    unsigned char f7b;
    char pad7c[0x84 - 0x7c];
    int f84;
    int f88;
    void *f8c;
    char pad90[0xe8 - 0x90];
    int fe8;
    int fec;
    char fF0[4];
    char fF4[4];
    int fF8;
};

extern "C" void FUN_001c4584(Obj *self)
{
    if (FUN_000e2c0c(DAT_003e1e84, -1)) {
        FUN_001c23fc(&DAT_003eaad8, 0x23);
        FUN_001c6440(self, 1);
    } else if (FUN_000e2708(DAT_003e1e84, -1)) {
        FUN_001c23fc(&DAT_003eaad8, 0x22);
        FUN_001c6440(self, 1);
    } else if (self->f50 < 0) {
        FUN_001c21a8(&DAT_003eaad8);
        FUN_001c64d4(self, 0, 1);
    } else if (FUN_000e30f8(DAT_003e1e84) && self->f78 == 0) {
        FUN_001c21a8(&DAT_003eaad8);
        FUN_001c64d4(self, 0, 1);
        FUN_001c2280(&DAT_003eaad8, 0.0f, 0.0f);
    }

    if (FUN_000e30f8(DAT_003e1e84) && self->f7a != 0) {
        FUN_001c6834(self, 150, 0);
        self->f7a = 0;
    }

    if (DAT_003e47a0 != 0 && FUN_001259ac(DAT_003e47a0)) {
        self->f8c = DAT_00391590;
    }

    int local_var;
    int local_fF8;
    void *local_fF4;
    local_fF4 = (char *)self + 0xf4;
    local_fF8 = self->fF8;
    FUN_001c71e4(&local_var, self->fF0, &local_fF8, &local_fF4);

    self->f7b = 0;
    FUN_001c6408(self);
    self->f84 = 0;
    self->f88 = 0;
    self->fe8 = 0xd0;
    self->fec = 0xd0;
    FUN_001c63e4(self);
}
