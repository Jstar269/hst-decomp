/* HSTMATCH module=hstp_trans_main.prx start=0x002b69a8 end=0x002b6adc symbol=FUN_002b69a8 lang=c++ */
/* Clone of src/eboot/set_mode_panel_002a7218.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_003f46a0;
extern int DAT_003f46a4;
extern "C" {
void FUN_002b718c(Self *, int);
void FUN_002b6dac(Self *);
void FUN_002b6adc(Self *);
int FUN_0020d1e0(int, int, int);
void FUN_000143b0(int *, int, char *);
void FUN_0011988c(int, int *, int);
void FUN_00108dac(Self *);
}

extern "C" void FUN_002b69a8(Self *self, int mode)
{
    self->mode = mode;
    switch (mode) {
    case 0: {
        self->s54->value = 1.0f;
        self->s58->value = 0.0f;
        self->s5c->value = 0.0f;
        int v = self->f1668;
        self->f1674 = v;
        FUN_002b718c(self, v);
        FUN_002b6adc(self);
        self->g358->v1(0);
        int s = FUN_0020d1e0(0x12, 0x31, 0xe);
        FUN_0011988c(DAT_003f46a0, (int *)s, 0);
        break;
    }
    case 1: {
        self->s54->value = 0.0f;
        self->s58->value = 1.0f;
        self->s5c->value = 1.0f;
        self->f1674 = 0x12;
        FUN_002b718c(self, 0x12);
        FUN_002b6dac(self);
        self->g358->v1(1);
        int s = FUN_0020d1e0(0x12, 0x31, 0xf);
        FUN_000143b0(&DAT_003f46a4, s, self->buf1361);
        FUN_0011988c(DAT_003f46a0, &DAT_003f46a4, 0);
        break;
    }
    }
    FUN_00108dac(self);
}
