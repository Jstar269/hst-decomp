/* HSTMATCH module=hstp_trans_main.prx start=0x002b8b2c end=0x002b8cfc symbol=FUN_002b8b2c lang=c++ */
/* Clone of src/eboot/set_flag_update_screen_002a9370.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets the flag byte at +0x30c5 and updates the screen: flag set = hide (slot-1 call with 0 on the object at +0x74,
   ent[1..4] a/b/c f78 = 0.0f, FUN_002b910c, then FUN_002b8cfc/FUN_002ba0cc when `flag`); flag clear = show
   (slot-1 call with 1, FUN_002b88d0 re-apply of the mode when `flag`, f3120 = 30, b3114 = 0). Both paths share the
   tail of FUN_002b88d0 (same Self layout; the sltu/xori/andi table-row index idiom). The ent loop is unrolled by
   the compiler. Names provisional. */
struct W {
    char pad0[0x78];
    float f78;
    char pad7c[0x7c];
    char *ff8;
    char pad0xfc[0x3c];
    int f138;
};
struct Ent {
    W *a;
    W *b;
    W *c;
    int pad[3];
};
struct Tab {
    int v;
    int pad[2];
};
struct VC {
    virtual void s0();
    virtual void s1(int);
};
struct Self {
    char pad0[0x74];
    VC *f74;
    char pad78[0x210 - 0x78];
    W *f210;
    W *f214;
    W *f218;
    char pad21c[0x80];
    Ent ent[5];
    char pad314[0xd20];
    VC *f1034;
    VC *f1038;
    char pad103c[0x30c0 - 0x103c];
    int f30c0;
    unsigned char b30c4;
    unsigned char b30c5;
    char pad30c6[0x2a];
    Tab tab[2];
    char pad3108[0xc];
    unsigned char b3114;
    char pad3115[0xb];
    int f3120;
};

extern "C" {
void FUN_00105470(W *, int);
void FUN_00108dac(Self *);
void FUN_002b88d0(Self *, int, int);
void FUN_002b8cfc(Self *);
int FUN_002b910c(Self *, int);
void FUN_002ba0cc(Self *, int);
}

extern "C" void FUN_002b8b2c(Self *self, int v, int flag)
{
    self->b30c5 = v;
    if (self->b30c5 != 0) {
        self->f74->s1(0);
        for (int i = 1; i < 5; i++) {
            self->ent[i].a->f78 = 0.0f;
            self->ent[i].b->f78 = 0.0f;
            self->ent[i].c->f78 = 0.0f;
        }
        FUN_002b910c(self, 0);
        if (flag != 0) {
            FUN_002b8cfc(self);
            FUN_002ba0cc(self, 0);
        }
    } else {
        self->f74->s1(1);
        if (flag != 0) {
            FUN_002b88d0(self, self->f30c0, 0);
        }
        self->f3120 = 30;
        self->b3114 = 0;
    }
    int a = 1;
    if (self->tab[(unsigned char)((self->b30c4 != 0) ^ 1)].v > 5) {
        if (self->b30c5 == 0) a = 0;
    }
    self->f1038->s1(a);
    int b = 1;
    if (self->tab[(unsigned char)((self->b30c4 != 0) ^ 1)].v > 5) {
        if (self->b30c5 == 0) b = 0;
    }
    FUN_00105470(self->f218, b);
    self->f1034->s1(self->b30c5);
    FUN_00108dac(self);
}
