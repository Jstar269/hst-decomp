/* HSTMATCH module=hstp_trans_main.prx start=0x001ad6e8 end=0x001ae17c symbol=FUN_001ad6e8 lang=c++ rodata=0x002d333c data=0x00389498 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* kak_manager.cpp (from the assert): "LastConfirm" menu setup; Sharing twin of EBOOT 0x1a0148 with the
   m_binderBuffer assert enabled. Setup (loads the lastconfirm layouts and parameter tables, fills the option vectors). The
   two pragmas reproduce retail's loops (index*4 recomputed per iteration, constant-count loops kept rolled); the
   jump table (.rodata) and the anonymous initialisers, const-ref temporaries and strings (.data) are placed. */
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
struct Tag {};

struct IVec {
    int *data_;
    unsigned size_;
    unsigned cap_;
    unsigned size() const { return size_; }
    int &operator[](unsigned i) { return data_[i]; }
};

struct IVecVec {
    IVec *data_;
    unsigned size_;
    unsigned cap_;
    unsigned size() const { return size_; }
    IVec &operator[](unsigned i) { return data_[i]; }
};

extern "C" {
void FUN_00000020(const char *name);
void FUN_00000028(void);
void FUN_001aabec(...);
void *FUN_00010184(int align, int size);
void FUN_0001bb2c(void *heap, void *p, int size);
void FUN_0001c5f4(void *ld, const char *path);
void FUN_0001c73c(void *ld);
void FUN_00212b30(void);
void FUN_0018753c(void *a, void *b, const char *path, int n);
void FUN_00187954(void *a, void *b, const char *path, int n);
void FUN_00066260(void *a, const char *path, int x, int y, const char *sep);
void FUN_001c0f18(void *p);
void FUN_001c0f30(void *p);
void FUN_001c1f44(void *p, int n);
void FUN_001b37a4(IVec *v, unsigned n, const int &x, Tag t);
void FUN_001b3198(IVec *v, unsigned n, const int &x, Tag t);
void FUN_001b388c(IVec *v, unsigned n, const int &x, Tag t);
void FUN_001b3218(IVec *v, unsigned n, const int &x);
void FUN_001b356c(IVecVec *v, unsigned n, const IVec &x, Tag t);
void FUN_000550a0(IVec *v, int flag);
void FUN_0023a6f8(int a, int b);
int FUN_0025e29c(void);
int FUN_0025e390(int a);
void FUN_002bd2a8(int a);
}

struct Cfg {
    char pad0[0x178];
    unsigned char f178;
};
struct Unk160b {
    char pad0[0x20];
    unsigned short f20;
    unsigned short f22;
};
struct Unk160a {
    char pad0[0x64];
    Unk160b *f64;
};
struct Unk44c {
    char pad0[0x44c];
    int f44c;
};
struct Unk1038 {
    char pad0[0x1038];
    unsigned short f1038;
};

extern Cfg *DAT_003e1e04;
extern int DAT_003f39a8;
extern int DAT_003f39ac;
extern char DAT_003b3e6c[];
extern char DAT_003b7ebc[];
extern char DAT_003eaad8[];
extern Unk1038 *DAT_003eb004;
extern int DAT_003eb028;
extern int DAT_003eb02c;
extern int DAT_003eb030;
extern int DAT_003eb034;
extern int DAT_003eb038;
extern int DAT_003eb03c;
extern int DAT_003eb040;
extern int DAT_0038938c;
extern int DAT_00389390;
extern const char DAT_003893a0[]; /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_003893d4[]; /* "kak_manager.cpp" */

struct LastConfirm {
    char pad0[0x3c];
    int f3c;                 /* 0x3c */
    char pad40[0x4c - 0x40];
    unsigned char f4c;       /* 0x4c */
    char pad4d[2];
    unsigned char f4f;       /* 0x4f */
    unsigned char f50;       /* 0x50 */
    char pad51[3];
    int f54;                 /* 0x54 */
    char pad58[0x68 - 0x58];
    char f68[0x88 - 0x68];   /* 0x68 */
    void *f88;               /* 0x88 */
    char pad8c[4];
    char f90[0xf4 - 0x90];   /* 0x90 */
    char ff4[0x116 - 0xf4];  /* 0xf4 */
    short f116;              /* 0x116 */
    short f118;              /* 0x118 */
    char pad11a;
    unsigned char f11b;      /* 0x11b */
    char pad11c;
    unsigned char f11d;      /* 0x11d */
    unsigned char f11e;      /* 0x11e */
    unsigned char f11f;      /* 0x11f */
    signed char f120;        /* 0x120 */
    signed char f121;        /* 0x121 */
    char pad122[0x160 - 0x122];
    Unk160a *f160;           /* 0x160 */
    char pad164[0x2a4 - 0x164];
    unsigned char f2a4;      /* 0x2a4 */
    unsigned char f2a5;      /* 0x2a5 */
    char pad2a6[0x2bc - 0x2a6];
    unsigned f2bc;           /* 0x2bc */
    char pad2c0[4];
    int f2c4;                /* 0x2c4 */
    char pad2c8[0x318 - 0x2c8];
    int f318;                /* 0x318 */
    int f31c;                /* 0x31c */
    char pad320[0x330 - 0x320];
    IVecVec v330;            /* 0x330 */
    IVecVec v33c;            /* 0x33c */
    IVec v348;               /* 0x348 */
    IVec v354;               /* 0x354 */
    IVec v360;               /* 0x360 */
    IVec v36c;               /* 0x36c */
    char f378[0x390 - 0x378];/* 0x378 */
    IVecVec v390;            /* 0x390 */
    char pad39c[0x3c4 - 0x39c];
    char f3c4[0x3f4 - 0x3c4];/* 0x3c4 */
    char f3f4[0x424 - 0x3f4];/* 0x3f4 */
    char f424[8];            /* 0x424 */
    char f42c[0x450 - 0x42c];/* 0x42c */
    char f450[0x488 - 0x450];/* 0x450 */
    void *m_binderBuffer;    /* 0x488 */
};

extern "C" {
void FUN_001ae96c(LastConfirm *self);
int FUN_0023bc78(void);
Unk44c *FUN_0020d694(void);
void FUN_001ae344(void *p, unsigned char a, int x, int y, bool z);
void FUN_001ae634(LastConfirm *self, unsigned char a, int y, int z);
void FUN_001b670c(void *a, void *b);
void FUN_001bc04c(void *a);
void FUN_001c7da4(void *a, void *b, void *c);
void FUN_001c838c(void *a, int n, void *b, void *c);
void FUN_001c8808(void *a, void *b, void *c);
void FUN_001c88e0(void *a, void *b, void *c);
void FUN_00177cc4(unsigned char n);
int FUN_001776d4(void);
int FUN_001776b4(void);
int FUN_001776f8(void);
int FUN_00177704(void);
void FUN_001b1b54(LastConfirm *self, int a);
unsigned short FUN_001b1fa8(LastConfirm *self, int a);
Unk1038 *FUN_00177d4c(void);
void FUN_001b1d2c(LastConfirm *self, int a);
void FUN_001b1d6c(LastConfirm *self, int a);
void FUN_001b1db4(LastConfirm *self, int a);
void FUN_001b1e70(LastConfirm *self, int a);
void FUN_001b1a70(LastConfirm *self);
}

#define KAK_ASSERT(c, text, line) \
    if (!(c)) { FUN_001aabec(DAT_003893a0, text, DAT_003893d4, line); while (1) {} }

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" int FUN_001ad6e8(LastConfirm *self)
{
    FUN_00000020("LastConfirm");
    if (self->m_binderBuffer == 0) {
        void *p = FUN_00010184(0x40, 0x100000);
        self->m_binderBuffer = p;
        KAK_ASSERT(self->m_binderBuffer, "m_binderBuffer", 2058);
        FUN_0001bb2c(DAT_003b3e6c, p, 0x100000);
    }
    FUN_0001c5f4(DAT_003b7ebc, "menu/lastconfirm_10.xb");
    FUN_00212b30();
    FUN_0018753c(self->f424, self->f3c4, "data/menu/lastconfirm/lastconfirm_param.csv", 8);
    FUN_00187954(self->f42c, self->f3f4, "data/menu/lastconfirm/lastconfirm_param_color.csv", 0x24);
    FUN_00066260(self->f450, "data/common/rule/Rule_Iromono.txt", 1, 0, "\t");
    FUN_001c0f18(DAT_003eaad8);
    FUN_0001c73c(DAT_003b7ebc);
    FUN_0001c5f4(DAT_003b7ebc, "menu/lastconfirm_11.xb");
    FUN_001c0f30(DAT_003eaad8);
    FUN_0001c73c(DAT_003b7ebc);

    int kinds[2] = {2, 3};
    FUN_001b37a4(&self->v348, 2, 0, Tag());
    unsigned i = 0;
    const int *src = kinds;
    for (; i < 2; i++)
        self->v348[i] = *src++;
    FUN_001b3198(&self->v354, self->v348.size(), 0, Tag());
    for (unsigned i = 0; i < self->v354.size(); i++) {
        self->v354[i] = 0;
        if (!self->f2a4 || DAT_003e1e04->f178) {
            switch (self->v348[i]) {
            case 3:
                if (self->f2a4 && self->f2a5)
                    self->v354[i] = 0;
                else
                    self->v354[i] = 1;
                break;
            case 1:
                if (!self->f4c)
                    self->v354[i] = 1;
                break;
            case 2:
                self->v354[i] = 1;
                break;
            }
        }
    }

    int items[6] = {1, 2, 3, 4, 5, 6};
    FUN_001b388c(&self->v360, 6, 0, Tag());
    unsigned i2 = 0;
    const int *src2 = items;
    for (; i2 < 6; i2++)
        self->v360[i2] = *src2++;
    bool flag = false;
    switch (DAT_003f39a8) {
    case 48:
        FUN_002bd2a8(FUN_0025e390(FUN_0025e29c()));
        break;
    case 41:
        flag = true;
        FUN_0023a6f8(self->f160->f64->f20, self->f160->f64->f22);
        break;
    }
    FUN_001b3198(&self->v36c, 6, 0, Tag());
    for (unsigned i = 0; i < 6; i++) {
        self->v36c[i] = 0;
        if (!self->f2a4 || DAT_003e1e04->f178) {
            switch (self->v360[i]) {
            case 1:
                if (!flag)
                    self->v36c[i] = 1;
                break;
            case 2:
                if (flag) {
                    if (self->f116 == 0)
                        self->v36c[i] = 1;
                } else {
                    self->v36c[i] = 1;
                }
                break;
            case 3:
                if (flag) {
                    if (self->f118 == -1)
                        self->v36c[i] = 1;
                } else {
                    self->v36c[i] = 1;
                }
                break;
            case 5:
                if (!flag)
                    self->v36c[i] = 1;
                break;
            case 4:
                if (!flag)
                    self->v36c[i] = 1;
                break;
            case 6:
                self->v36c[i] = 1;
                break;
            }
        }
    }

    FUN_001ae96c(self);
    int x = 0;
    bool guest = false;
    if (self->f4f) {
        if (self->f2a4) {
            if (DAT_003e1e04->f178)
                x = FUN_0023bc78();
            else
                x = FUN_0020d694()->f44c;
        } else {
            x = FUN_0023bc78();
        }
    }
    self->f54 = x;
    if (self->f2a4) {
        if (!DAT_003e1e04->f178)
            guest = true;
    }
    FUN_001ae344(self->f378, self->f4f, x, self->f116, guest);
    int y = 0;
    if (self->f2a4) {
        if (!DAT_003e1e04->f178)
            y = 1;
    }
    FUN_001ae634(self, self->f4f, self->f118, y);

    {
        IVec tmp;
        tmp.data_ = 0;
        tmp.size_ = 0;
        tmp.cap_ = 0;
        FUN_001b3218(&tmp, 3, 0);
        FUN_001b356c(&self->v330, 2, tmp, Tag());
        FUN_000550a0(&tmp, 0);
    }
    {
        IVec tmp;
        tmp.data_ = 0;
        tmp.size_ = 0;
        tmp.cap_ = 0;
        FUN_001b3218(&tmp, 3, 0);
        FUN_001b356c(&self->v33c, 2, tmp, Tag());
        FUN_000550a0(&tmp, 0);
    }

    FUN_001b670c(self->f90, self->f424);
    FUN_001bc04c(self->f68);
    self->f3c = 1;
    FUN_001c7da4(self->f88, &self->f160, self->ff4);
    if (self->f2a4) {
        if (DAT_003e1e04->f178) {
            FUN_001c838c(self->f88, 0, &self->f160, self->ff4);
            FUN_001c8808(self->f88, &self->f160, self->ff4);
        } else {
            FUN_001c838c(self->f88, 1, &self->f160, self->ff4);
            FUN_001c8808(self->f88, &self->f160, self->ff4);
        }
    } else {
        FUN_001c88e0(self->f88, &self->f160, self->ff4);
    }
    for (unsigned i = 0; i < self->v354.size(); i++) {
        switch (self->v348[i]) {
        case 3:
            self->f2bc = i;
            break;
        }
    }

    int a = self->f116;
    int b = self->f11d;
    int c = self->f11e;
    int d = self->f11f;
    int e = self->f118;
    int f = self->f120;
    int g = self->f121;
    int h = 0;
    int k = 0;
    FUN_00177cc4(0);
    if (self->f4f)
        FUN_00177cc4(self->f11b);
    if (e < 0) {
        if (FUN_001776d4())
            e = -1;
        else
            e = FUN_001776b4();
    }
    if (self->f50) {
        a = DAT_003eb004->f1038;
        e = FUN_001776f8();
        if (FUN_00177704())
            e = -1;
        b = DAT_003eb034;
        c = DAT_003eb038;
        d = DAT_003eb030;
        h = DAT_003eb03c;
        k = DAT_003eb040;
        f = DAT_003eb028;
        g = DAT_003eb02c;
    }
    FUN_001b1b54(self, a);
    if (self->f2a4 && DAT_003e1e04->f178) {
        unsigned short r = FUN_001b1fa8(self, self->f2c4);
        Unk1038 *o = FUN_00177d4c();
        o->f1038 = Clamp(r, DAT_0038938c, DAT_00389390);
    }
    FUN_001b1d2c(self, b);
    FUN_001b1d6c(self, c);
    FUN_001b1db4(self, d);
    FUN_001b1e70(self, e);
    FUN_001b1a70(self);
    self->f318 = h;
    self->f31c = k;
    for (unsigned i = 0; i < self->v390.size(); i++) {
        for (unsigned j = 0; j < self->v390[i].size(); j++) {
            if (f != 0 && f == self->v390[i][j])
                self->v330[i][j] = 1;
            else if (g != 0 && g == self->v390[i][j])
                self->v330[i][j] = 1;
        }
    }
    switch (DAT_003f39ac) {
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x2c:
    case 0x2d:
    case 0x2e:
    case 0x2f:
    case 0x37:
    case 0x38:
    case 0x39:
    case 0x3a:
    case 0x55:
        break;
    default:
        FUN_001c1f44(DAT_003eaad8, 10);
        break;
    }
    FUN_00000028();
    return 1;
}
