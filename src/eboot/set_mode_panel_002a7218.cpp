/* HSTMATCH module=EBOOT.BIN start=0x002a7218 end=0x002a734c symbol=FUN_002a7218 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Gfx {
    virtual void v0();
    virtual void v1(int);
};
struct Slot {
    char pad[0x78];
    float value;
};
struct Self {
    char pad0[0x54];
    Slot *s54;
    Slot *s58;
    Slot *s5c;
    char pad1[0x358 - 0x60];
    Gfx *g358;
    char pad2[0x1361 - 0x35c];
    char buf1361[0x1664 - 0x1361];
    int mode;
    int f1668;
    char pad3[0x1674 - 0x166c];
    int f1674;
};
extern int DAT_0034b354;
extern int DAT_0034b358;
extern "C" {
void FUN_002a79fc(Self *, int);
void FUN_002a761c(Self *);
void FUN_002a734c(Self *);
int FUN_001fea10(int, int, int);
void FUN_000143b0(int *, int, char *);
void FUN_00110a78(int, int *, int);
void FUN_00103480(Self *);
}

extern "C" void FUN_002a7218(Self *self, int mode)
{
    self->mode = mode;
    switch (mode) {
    case 0: {
        self->s54->value = 1.0f;
        self->s58->value = 0.0f;
        self->s5c->value = 0.0f;
        int v = self->f1668;
        self->f1674 = v;
        FUN_002a79fc(self, v);
        FUN_002a734c(self);
        self->g358->v1(0);
        int s = FUN_001fea10(0x12, 0x31, 0xe);
        FUN_00110a78(DAT_0034b354, (int *)s, 0);
        break;
    }
    case 1: {
        self->s54->value = 0.0f;
        self->s58->value = 1.0f;
        self->s5c->value = 1.0f;
        self->f1674 = 0x12;
        FUN_002a79fc(self, 0x12);
        FUN_002a761c(self);
        self->g358->v1(1);
        int s = FUN_001fea10(0x12, 0x31, 0xf);
        FUN_000143b0(&DAT_0034b358, s, self->buf1361);
        FUN_00110a78(DAT_0034b354, &DAT_0034b358, 0);
        break;
    }
    }
    FUN_00103480(self);
}
