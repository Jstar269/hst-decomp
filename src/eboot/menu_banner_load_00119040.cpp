/* HSTMATCH module=EBOOT.BIN start=0x00119040 end=0x0011931c symbol=FUN_00119040 lang=c++ data=0x002d9c2c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002d9c2c-0x002d9c5c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/banner_screen.h"

struct Banner {
    virtual void v0();
    virtual void v1();
    virtual void Load(char *path, char *name, int a, int b, int c, int d);
    char pad[0x8c - 4];
    void *unk8c;    /* 0x8c object handed to a helper together with a float */
};

struct Names { const char *n[ICON_COLS]; };

extern "C" {
void FUN_00000020(const char *, ...);
void FUN_00000028(...);
void FUN_0001cad0(void *, int, const char *);
void FUN_0001cb88(void *);
int FUN_000143b0(char *, const char *, ...);
Banner *FUN_00056b98(void *);
void FUN_000573a0(Banner *, int, char *, int, int);
void FUN_00053e90(float, void *, int);
void *FUN_0011a95c(void *);
void *FUN_0011b4b8(void *);
void *FUN_001ee234();
void *FUN_00065740(void *, const char *, int);
void *FUN_00000bcc(unsigned);
}

extern char DAT_0030ebf4;
extern const char DAT_002d9c5c[];
extern const char *DAT_002d95e8[];
extern const char *DAT_002d98c0[];
extern const char *DAT_002d9b2c[];
extern float DAT_002d9ba0;
extern const Names DAT_002d9c00;

enum { BANNER_SIZE = 0x1b0 }; /* bytes per banner object */

inline void *operator new[](unsigned int, void *p) { return p; }

/* Build the banner objects and their two helpers, then the icon grid. */
extern "C" void FUN_00119040(BannerScreen *self)
{
    FUN_00000020("Banner");
    char path[128];
    new (path) char[128]();
    char name[128];
    new (name) char[128]();
    FUN_0001cad0(&DAT_0030ebf4, 1, "menu/030_banner.xb");
    for (int i = 0; i < BANNER_COUNT; i++) {
        Banner *b = (Banner *)FUN_00000bcc(BANNER_SIZE);
        if (b)
            b = FUN_00056b98(b);
        self->banners[i] = b;
        FUN_000143b0(name, "data/menu/banner/%s", DAT_002d95e8[i]);
        FUN_000143b0(path, DAT_002d9c5c, name, DAT_002d98c0[i]);
        self->banners[i]->Load(path, name, 0, 0, 0, 0);
        FUN_000143b0(path, DAT_002d9c5c, name, DAT_002d9b2c[i]);
        FUN_000573a0(self->banners[i], 0, path, 0, 0);
        if (i != 1 && i != 9)
            FUN_00053e90(DAT_002d9ba0, self->banners[i]->unk8c, 0);
    }
    void *p = FUN_00000bcc(0xac);
    if (p)
        p = FUN_0011a95c(p);
    self->unk3c = p;
    void *q = FUN_00000bcc(0x10);
    if (q)
        q = FUN_0011b4b8(q);
    self->unk40 = q;
    FUN_0001cb88(&DAT_0030ebf4);
    void *res = FUN_001ee234();
    if (res) {
        Names names = DAT_002d9c00;
        for (int j = 0; j < ICON_ROWS; j++)
            for (int k = 0; k < ICON_COLS; k++)
                self->icons[j][k] = FUN_00065740(res, names.n[k], j + 1);
    }
    FUN_00000028();
}
