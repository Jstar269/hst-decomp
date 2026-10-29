/* HSTMATCH module=EBOOT.BIN start=0x001a0148 end=0x001a0bb0 symbol=FUN_001a0148 lang=c++ rodata=0x002c2e30 data=0x002e1bd8 */
/* LastConfirm_Init: lastconfirm_param.csv, lastconfirm_param_color.csv, Rule_Iromono.txt; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* "LastConfirm" menu setup (loads the lastconfirm layouts and parameter tables, fills the option vectors). The
   two pragmas reproduce retail's loops (index*4 recomputed per iteration, constant-count loops kept rolled); the
   jump table (.rodata) and the anonymous initialisers, const-ref temporaries and strings (.data) are placed. */
#include "hst/screen_obj.h"
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off
/* Empty marker argument passed by value to the vector helpers. */
struct Tag {};

enum { KIND_COUNT = 2, ITEM_COUNT = 6, HEAP_SIZE = 0x100000, HEAP_ALIGN = 0x40 };

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
void *FUN_00010184(int align, int size);
void FUN_0001bfb4(void *heap, void *p, int size);
void FUN_0001ca58(void *ld, const char *path);
void FUN_0001cb88(void *ld);
void FUN_002042c8(void);
void FUN_0017ae48(void *a, void *b, const char *path, int n);
void FUN_0017b260(void *a, void *b, const char *path, int n);
void FUN_000651b8(void *a, const char *path, int x, int y, const char *sep);
void FUN_001b2de8(void *p);
void FUN_001b2e00(void *p);
void FUN_001b3ce8(void *p, int n);
void FUN_001a61d8(IVec *v, unsigned n, const int &x, Tag t);
void FUN_001a5bcc(IVec *v, unsigned n, const int &x, Tag t);
void FUN_001a62c0(IVec *v, unsigned n, const int &x, Tag t);
void FUN_001a5c4c(IVec *v, unsigned n, const int &x);
void FUN_001a5fa0(IVecVec *v, unsigned n, const IVec &x, Tag t);
void FUN_00054554(IVec *v, int flag);
void FUN_0022ada4(int a, int b);
int FUN_0024e064(void);
int FUN_0024e158(int a);
void FUN_002ada80(int a);
}

struct Cfg {
    char pad0[0x178];
    unsigned char unk178;
};
struct Unk160b {
    char pad0[0x20];
    unsigned short unk20;
    unsigned short unk22;
};
struct Unk160a {
    char pad0[0x64];
    Unk160b *unk64;
};
struct Unk44c {
    char pad0[0x44c];
    int unk44c;
};
struct Unk1038 {
    char pad0[0x1038];
    unsigned short unk1038;
};

extern ScreenEnv *DAT_00338ac4;
extern int DAT_0034a678;
extern int DAT_0034a67c;
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];
extern char DAT_0034179c[];
extern Unk1038 *DAT_00341ccc;
extern int DAT_00341cf0;
extern int DAT_00341cf4;
extern int DAT_00341cf8;
extern int DAT_00341cfc;
extern int DAT_00341d00;
extern int DAT_00341d04;
extern int DAT_00341d08;
extern int DAT_002e1b48;
extern int DAT_002e1b4c;

struct LastConfirm {
    char pad0[0x3c];
    int unk3c;                 /* 0x3c */
    char pad40[0x4c - 0x40];
    unsigned char unk4c;       /* 0x4c */
    char pad4d[2];
    unsigned char unk4f;       /* 0x4f */
    unsigned char unk50;       /* 0x50 */
    char pad51[3];
    int unk54;                 /* 0x54 */
    char pad58[0x68 - 0x58];
    char unk68[0x88 - 0x68];   /* 0x68 */
    void *unk88;               /* 0x88 */
    char pad8c[4];
    char unk90[0xf4 - 0x90];   /* 0x90 */
    char unkf4[0x116 - 0xf4];  /* 0xf4 */
    short unk116;              /* 0x116 */
    short unk118;              /* 0x118 */
    char pad11a;
    unsigned char unk11b;      /* 0x11b */
    char pad11c;
    unsigned char unk11d;      /* 0x11d */
    unsigned char unk11e;      /* 0x11e */
    unsigned char unk11f;      /* 0x11f */
    signed char unk120;        /* 0x120 */
    signed char unk121;        /* 0x121 */
    char pad122[0x160 - 0x122];
    Unk160a *unk160;           /* 0x160 */
    char pad164[0x2a4 - 0x164];
    unsigned char unk2a4;      /* 0x2a4 */
    unsigned char unk2a5;      /* 0x2a5 */
    char pad2a6[0x2bc - 0x2a6];
    unsigned unk2bc;           /* 0x2bc */
    char pad2c0[4];
    int unk2c4;                /* 0x2c4 */
    char pad2c8[0x318 - 0x2c8];
    int unk318;                /* 0x318 */
    int unk31c;                /* 0x31c */
    char pad320[0x330 - 0x320];
    IVecVec unk330;            /* 0x330 */
    IVecVec unk33c;            /* 0x33c */
    IVec kinds;               /* 0x348 */
    IVec kind_on;               /* 0x354 */
    IVec items;               /* 0x360 */
    IVec item_on;               /* 0x36c */
    char unk378[0x390 - 0x378];/* 0x378 */
    IVecVec unk390;            /* 0x390 */
    char pad39c[0x3c4 - 0x39c];
    char unk3c4[0x3f4 - 0x3c4];/* 0x3c4 */
    char unk3f4[0x424 - 0x3f4];/* 0x3f4 */
    char unk424[8];            /* 0x424 */
    char unk42c[0x450 - 0x42c];/* 0x42c */
    char unk450[0x488 - 0x450];/* 0x450 */
    void *heap;              /* 0x488 */
};

extern "C" {
void FUN_001a13a0(LastConfirm *self);
int FUN_0022c1c4(void);
Unk44c *FUN_001feec4(void);
void FUN_001a0d78(void *p, unsigned char a, int x, int y, bool z);
void FUN_001a1068(LastConfirm *self, unsigned char a, int y, int z);
void FUN_001a9140(void *a, void *b);
void FUN_001ae974(void *a);
void FUN_001ba05c(void *a, void *b, void *c);
void FUN_001ba644(void *a, int n, void *b, void *c);
void FUN_001baac0(void *a, void *b, void *c);
void FUN_001bab98(void *a, void *b, void *c);
void FUN_0016bb00(unsigned char n);
int FUN_0016b510(void);
int FUN_0016b4f0(void);
int FUN_0016b534(void);
int FUN_0016b540(void);
void FUN_001a4588(LastConfirm *self, int a);
unsigned short FUN_001a49dc(LastConfirm *self, int a);
Unk1038 *FUN_0016bb88(void);
void FUN_001a4760(LastConfirm *self, int a);
void FUN_001a47a0(LastConfirm *self, int a);
void FUN_001a47e8(LastConfirm *self, int a);
void FUN_001a48a4(LastConfirm *self, int a);
void FUN_001a44a4(LastConfirm *self);
}

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" int FUN_001a0148(LastConfirm *self)
{
    FUN_00000020("LastConfirm");
    if (self->heap == 0) {
        void *p = FUN_00010184(HEAP_ALIGN, HEAP_SIZE);
        self->heap = p;
        FUN_0001bfb4(DAT_0030ab9c, p, HEAP_SIZE);
    }
    FUN_0001ca58(DAT_0030ebf4, "menu/lastconfirm_10.xb");
    FUN_002042c8();
    FUN_0017ae48(self->unk424, self->unk3c4, "data/menu/lastconfirm/lastconfirm_param.csv", 8);
    FUN_0017b260(self->unk42c, self->unk3f4, "data/menu/lastconfirm/lastconfirm_param_color.csv", 0x24);
    FUN_000651b8(self->unk450, "data/common/rule/Rule_Iromono.txt", 1, 0, "\t");
    FUN_001b2de8(DAT_0034179c);
    FUN_0001cb88(DAT_0030ebf4);
    FUN_0001ca58(DAT_0030ebf4, "menu/lastconfirm_11.xb");
    FUN_001b2e00(DAT_0034179c);
    FUN_0001cb88(DAT_0030ebf4);

    int kind_ids[KIND_COUNT] = {2, 3};
    FUN_001a61d8(&self->kinds, KIND_COUNT, 0, Tag());
    unsigned i = 0;
    const int *src = kind_ids;
    for (; i < KIND_COUNT; i++)
        self->kinds[i] = *src++;
    FUN_001a5bcc(&self->kind_on, self->kinds.size(), 0, Tag());
    for (unsigned i = 0; i < self->kind_on.size(); i++) {
        self->kind_on[i] = 0;
        if (!self->unk2a4 || DAT_00338ac4->unk178) {
            switch (self->kinds[i]) {
            case 3:
                if (self->unk2a4 && self->unk2a5)
                    self->kind_on[i] = 0;
                else
                    self->kind_on[i] = 1;
                break;
            case 1:
                if (!self->unk4c)
                    self->kind_on[i] = 1;
                break;
            case 2:
                self->kind_on[i] = 1;
                break;
            }
        }
    }

    int item_ids[ITEM_COUNT] = {1, 2, 3, 4, 5, 6};
    FUN_001a62c0(&self->items, ITEM_COUNT, 0, Tag());
    unsigned i2 = 0;
    const int *src2 = item_ids;
    for (; i2 < ITEM_COUNT; i2++)
        self->items[i2] = *src2++;
    bool flag = false;
    switch (DAT_0034a678) {
    case 48:
        FUN_002ada80(FUN_0024e158(FUN_0024e064()));
        break;
    case 41:
        flag = true;
        FUN_0022ada4(self->unk160->unk64->unk20, self->unk160->unk64->unk22);
        break;
    }
    FUN_001a5bcc(&self->item_on, ITEM_COUNT, 0, Tag());
    for (unsigned i = 0; i < ITEM_COUNT; i++) {
        self->item_on[i] = 0;
        if (!self->unk2a4 || DAT_00338ac4->unk178) {
            switch (self->items[i]) {
            case 1:
                if (!flag)
                    self->item_on[i] = 1;
                break;
            case 2:
                if (flag) {
                    if (self->unk116 == 0)
                        self->item_on[i] = 1;
                } else {
                    self->item_on[i] = 1;
                }
                break;
            case 3:
                if (flag) {
                    if (self->unk118 == -1)
                        self->item_on[i] = 1;
                } else {
                    self->item_on[i] = 1;
                }
                break;
            case 5:
                if (!flag)
                    self->item_on[i] = 1;
                break;
            case 4:
                if (!flag)
                    self->item_on[i] = 1;
                break;
            case 6:
                self->item_on[i] = 1;
                break;
            }
        }
    }

    FUN_001a13a0(self);
    int value54 = 0;
    bool guest = false;
    if (self->unk4f) {
        if (self->unk2a4) {
            if (DAT_00338ac4->unk178)
                value54 = FUN_0022c1c4();
            else
                value54 = FUN_001feec4()->unk44c;
        } else {
            value54 = FUN_0022c1c4();
        }
    }
    self->unk54 = value54;
    if (self->unk2a4) {
        if (!DAT_00338ac4->unk178)
            guest = true;
    }
    FUN_001a0d78(self->unk378, self->unk4f, value54, self->unk116, guest);
    int guest_flag = 0;
    if (self->unk2a4) {
        if (!DAT_00338ac4->unk178)
            guest_flag = 1;
    }
    FUN_001a1068(self, self->unk4f, self->unk118, guest_flag);

    {
        IVec tmp;
        tmp.data_ = 0;
        tmp.size_ = 0;
        tmp.cap_ = 0;
        FUN_001a5c4c(&tmp, 3, 0);
        FUN_001a5fa0(&self->unk330, 2, tmp, Tag());
        FUN_00054554(&tmp, 0);
    }
    {
        IVec tmp;
        tmp.data_ = 0;
        tmp.size_ = 0;
        tmp.cap_ = 0;
        FUN_001a5c4c(&tmp, 3, 0);
        FUN_001a5fa0(&self->unk33c, 2, tmp, Tag());
        FUN_00054554(&tmp, 0);
    }

    FUN_001a9140(self->unk90, self->unk424);
    FUN_001ae974(self->unk68);
    self->unk3c = 1;
    FUN_001ba05c(self->unk88, &self->unk160, self->unkf4);
    if (self->unk2a4) {
        if (DAT_00338ac4->unk178) {
            FUN_001ba644(self->unk88, 0, &self->unk160, self->unkf4);
            FUN_001baac0(self->unk88, &self->unk160, self->unkf4);
        } else {
            FUN_001ba644(self->unk88, 1, &self->unk160, self->unkf4);
            FUN_001baac0(self->unk88, &self->unk160, self->unkf4);
        }
    } else {
        FUN_001bab98(self->unk88, &self->unk160, self->unkf4);
    }
    for (unsigned i = 0; i < self->kind_on.size(); i++) {
        switch (self->kinds[i]) {
        case 3:
            self->unk2bc = i;
            break;
        }
    }

    int val116 = self->unk116;
    int val11d = self->unk11d;
    int val11e = self->unk11e;
    int val11f = self->unk11f;
    int val118 = self->unk118;
    int val120 = self->unk120;
    int val121 = self->unk121;
    int val318 = 0;
    int val31c = 0;
    FUN_0016bb00(0);
    if (self->unk4f)
        FUN_0016bb00(self->unk11b);
    if (val118 < 0) {
        if (FUN_0016b510())
            val118 = -1;
        else
            val118 = FUN_0016b4f0();
    }
    if (self->unk50) {
        val116 = DAT_00341ccc->unk1038;
        val118 = FUN_0016b534();
        if (FUN_0016b540())
            val118 = -1;
        val11d = DAT_00341cfc;
        val11e = DAT_00341d00;
        val11f = DAT_00341cf8;
        val318 = DAT_00341d04;
        val31c = DAT_00341d08;
        val120 = DAT_00341cf0;
        val121 = DAT_00341cf4;
    }
    FUN_001a4588(self, val116);
    if (self->unk2a4 && DAT_00338ac4->unk178) {
        unsigned short level = FUN_001a49dc(self, self->unk2c4);
        Unk1038 *o = FUN_0016bb88();
        o->unk1038 = Clamp(level, DAT_002e1b48, DAT_002e1b4c);
    }
    FUN_001a4760(self, val11d);
    FUN_001a47a0(self, val11e);
    FUN_001a47e8(self, val11f);
    FUN_001a48a4(self, val118);
    FUN_001a44a4(self);
    self->unk318 = val318;
    self->unk31c = val31c;
    for (unsigned i = 0; i < self->unk390.size(); i++) {
        for (unsigned j = 0; j < self->unk390[i].size(); j++) {
            if (val120 != 0 && val120 == self->unk390[i][j])
                self->unk330[i][j] = 1;
            else if (val121 != 0 && val121 == self->unk390[i][j])
                self->unk330[i][j] = 1;
        }
    }
    switch (DAT_0034a67c) {
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
        FUN_001b3ce8(DAT_0034179c, 10);
        break;
    }
    FUN_00000028();
    return 1;
}
