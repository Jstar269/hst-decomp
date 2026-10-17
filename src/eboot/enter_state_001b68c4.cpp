/* HSTMATCH module=EBOOT.BIN start=0x001b68c4 end=0x001b6a7c symbol=FUN_001b68c4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_002e99d4;
extern void *DAT_00338b44;
extern void *DAT_0033b460;
extern void *DAT_0034179c;

extern int FUN_000dea20(void *, int);
extern int FUN_000de51c(void *, int);
extern int FUN_000def0c(void *);
extern int FUN_0011a7d8(void *);
extern void FUN_001b3f1c(void *);
extern void FUN_001b413c(void *, float, float);
extern void FUN_001b42b8(void *, int);
extern void FUN_001b86f8(void *);
extern void FUN_001b871c(void *);
extern void FUN_001b8754(void *, int);
extern void FUN_001b87e8(void *, int, int);
extern void FUN_001b8b48(void *, int, int);
extern void FUN_001b94f8(void *, void *, void *, void *);
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

extern "C" void FUN_001b68c4(Obj *self)
{
    if (FUN_000dea20(DAT_00338b44, -1)) {
        FUN_001b42b8(&DAT_0034179c, 0x23);
        FUN_001b8754(self, 1);
    } else if (FUN_000de51c(DAT_00338b44, -1)) {
        FUN_001b42b8(&DAT_0034179c, 0x22);
        FUN_001b8754(self, 1);
    } else if (self->f50 < 0) {
        FUN_001b3f1c(&DAT_0034179c);
        FUN_001b87e8(self, 0, 1);
    } else if (FUN_000def0c(DAT_00338b44) && self->f78 == 0) {
        FUN_001b3f1c(&DAT_0034179c);
        FUN_001b87e8(self, 0, 1);
        FUN_001b413c(&DAT_0034179c, 0.0f, 0.0f);
    }

    if (FUN_000def0c(DAT_00338b44) && self->f7a != 0) {
        FUN_001b8b48(self, 150, 0);
        self->f7a = 0;
    }

    if (DAT_0033b460 != 0 && FUN_0011a7d8(DAT_0033b460)) {
        self->f8c = DAT_002e99d4;
    }

    int local_var;
    int local_fF8;
    void *local_fF4;
    local_fF4 = (char *)self + 0xf4;
    local_fF8 = self->fF8;
    FUN_001b94f8(&local_var, self->fF0, &local_fF8, &local_fF4);

    self->f7b = 0;
    FUN_001b871c(self);
    self->f84 = 0;
    self->f88 = 0;
    self->fe8 = 0xd0;
    self->fec = 0xd0;
    FUN_001b86f8(self);
}
