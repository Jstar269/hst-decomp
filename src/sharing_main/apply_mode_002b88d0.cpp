/* HSTMATCH module=hstp_trans_main.prx start=0x002b88d0 end=0x002b8b2c symbol=FUN_002b88d0 lang=c++ */
/* Clone of src/eboot/apply_mode_002a9114.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: the row index into the 12-byte table is `(unsigned char)((b30c4 != 0) ^ 1)` (retail sltu/xori/andi 0xff); the name buffers at +0x103d are 63-byte names after a flag byte in 64-byte slots. */
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

struct Slot {
    char flag;
    char name[63];
};

struct VC {
    virtual void s0();
    virtual void s1(int);
};

struct Self {
    char pad0[0x210];
    W *f210;
    W *f214;
    W *f218;
    char pad21c[0x80];
    Ent ent[5];
    char pad314[0xb04];
    W *objs[5][26];
    char pad1020[0x14];
    VC *f1034;
    VC *f1038;
    Slot slot[5][26];
    char pad30bc[4];
    int f30c0;
    unsigned char b30c4;
    unsigned char b30c5;
    char pad30c6[0x2a];
    Tab tab[2];
};

extern "C" {
void FUN_00105470(W *, int);
void FUN_00108dac(Self *);
void FUN_00113a50(W *);
void FUN_002b8b2c(Self *, int, int);
int FUN_002b910c(Self *, int);
}

extern "C" void FUN_002b88d0(Self *self, int mode, int flag)
{
    self->f30c0 = mode;
    for (int i = 0; i < 5; i++) {
        switch (mode) {
        case 0:
        case 1:
            self->ent[i].a->f78 = 0.0f;
            self->ent[i].b->f78 = 1.0f;
            self->ent[i].c->f78 = 1.0f;
            FUN_00105470(self->f210, 1);
            FUN_00105470(self->f214, 1);
            break;
        case 2:
            self->ent[i].a->f78 = 1.0f;
            self->ent[i].b->f78 = 0.0f;
            self->ent[i].c->f78 = 1.0f;
            FUN_00105470(self->f210, 0);
            FUN_00105470(self->f214, 0);
            break;
        }
        if (FUN_002b910c(self, i) == 0) {
            self->ent[i].a->f78 = 0.0f;
            self->ent[i].b->f78 = 0.0f;
            self->ent[i].c->f78 = 0.0f;
        }
    }
    FUN_00108dac(self);
    if (flag != 0) {
        FUN_002b8b2c(self, self->b30c5, flag != 0);
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
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 26; k++) {
            W *o = self->objs[j][k];
            if (o != 0) {
                o->ff8 = self->slot[j][k].name;
                o->f138 = 1;
                FUN_00113a50(o);
            }
        }
    }
}
