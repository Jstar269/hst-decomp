/* HSTMATCH module=EBOOT.BIN start=0x0021a744 end=0x0021a9ec symbol=FUN_0021a744 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

typedef unsigned int uint;

struct Cfg8c {
    char pad[0x8b];
    signed char f8b;
};

struct ObjD {
    unsigned short pad[7];
    unsigned short f0e;
};

struct ObjC {
    ObjD *f0;
};

struct ObjB {
    char pad[0x10];
    ObjC *f10;
};

struct ObjA {
    char pad[0x54];
    ObjB *f54;
};

struct SubObj {
    virtual void Method0();
    virtual void Method1();
    virtual void Method2();
};

extern "C" {
extern Cfg8c *DAT_002cfc8c;
extern void *DAT_002efb40[];
extern ObjA *DAT_003415ac;
extern int DAT_0034179c;

bool FUN_001fe080(void *, int, int);
void FUN_001b1c44(void *, int);
void FUN_0010b980(void *, int, int);
void *FUN_001fea10(int, int, void *);
void FUN_00110a78(void *, void *, int);
void FUN_000ffb3c(void *, int);
void FUN_00103128(void *);
}

struct UISelection {
    char pad0[0x54];
    unsigned char f54;          /* 0x54 */
    char pad1[0x64 - 0x55];
    void *f64[7];               /* 0x64 (100) */
    void *f80[7];               /* 0x80 (128) */
    void *f9c[7];               /* 0x9c (156) */
    char pad_bc[0xbc - (0x9c + 7*4)];
    void *fbc;                  /* 0xbc (188) */
    char pad2[0xe0 - 0xc0];
    SubObj *fe0;                /* 0xe0 (224) */
    void *fe4;                  /* 0xe4 (228) */
    int fe8;                    /* 0xe8 (232) */
    int fec[7];                 /* 0xec (236) */
    int f108;                   /* 0x108 (264) */
    int f10c;                   /* 0x10c (268) */
    int f110;                   /* 0x110 (272) */
};

extern "C" void FUN_0021a744(UISelection *self)
{
    int old = self->fe8;
    bool b1 = FUN_001fe080(&self->f10c, 16, 0);
    bool b2 = FUN_001fe080(&self->f110, 64, 0);

    if (b1) {
        int next = self->fe8 - 1;
        self->fe8 = next;
        if (next < 0) {
            self->fe8 = self->f108 - 1;
        } else if (next == 0) {
            self->f10c = -1;
        }
    } else if (b2) {
        int next = self->fe8 + 1;
        self->fe8 = next;
        if (next >= self->f108) {
            self->fe8 = 0;
        } else if (next == self->f108 - 1) {
            self->f110 = -1;
        }
    } else {
        if ((((int)DAT_002cfc8c->f8b << 28) >> 30 == 0) && self->f54 == 0) {
            self->f54 = 1;
            FUN_001b1c44(&DAT_0034179c, 3);
        }
    }

    if (old != self->fe8) {
        FUN_001b1c44(&DAT_0034179c, 1);
        FUN_0010b980(self->fe4, self->fe8, 0);
        if (self->fe0 != 0) {
            void *item_str = FUN_001fea10(18, 33, DAT_002efb40[self->fec[self->fe8]]);
            FUN_00110a78(self->fe0, item_str, 0);
        }
    }

    for (int i = 0; i <= 6; i++) {
        if (self->fec[i] != 7) {
            FUN_000ffb3c(self->f64[i], i == self->fe8);
        } else {
            FUN_000ffb3c(self->f64[i], 1);
        }
    }

    for (int i = 7; i <= 13; i++) {
        if (self->fec[i - 7] != 7) {
            FUN_000ffb3c(self->f80[i - 7], (i - 7) != self->fe8);
        } else {
            FUN_000ffb3c(self->f80[i - 7], 1);
        }
    }

    for (int i = 14; i <= 20; i++) {
        FUN_000ffb3c(self->f9c[i - 14], (i - 14) != self->fe8);
    }

    FUN_000ffb3c(self->fbc, ((DAT_003415ac->f54->f10->f0->f0e & 3) != 0) ^ 1);

    if (self->fe0 != 0) {
        self->fe0->Method2();
    }

    FUN_00103128(self);
}
