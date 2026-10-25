/* HSTMATCH module=hstp_trans_main.prx start=0x000918d8 end=0x00091b48 symbol=FUN_000918d8 lang=c++ */
/* Clone of src/eboot/FUN_0008fcd8.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the local config object is a copy construction written out as explicit calls to the member copy constructors (0x4c644, 0x58694, 0x8fcc8, 0x8fbc8) with the vtable store first; FUN_000c5cc0's declared parameter order is (Self*,Vec4*,Vec4*,float,float,float,int*,float), which orders the argument setup like retail. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { float m[16]; } __attribute__((aligned(16)));
struct M144 { float m[36]; } __attribute__((aligned(16)));
struct Four { int v; };
struct Tag { };

struct Cfg {
    void *vtbl;
    int f4;
    int pad[2];
    Vec4 a, b, c, d;
    Mat4 e, f, g;
    float h[9];
    Four i;
    M144 j;
    unsigned char k;
    int count;
};

struct Self {
    Cfg cfg;
    char pad1[0x264 - sizeof(Cfg)];
    int f264;
    int f268;
    int l1[3];
    int l2[3];
    unsigned char f284;
    char pad2[3];
    int f288;
    char pad3[4];
    char f290;
};

extern "C" {
extern char __vt__10C_000c24a8;
extern char *DAT_003e19f0;
extern void FUN_000c5cc0(Self *, Vec4 *, Vec4 *, float, float, float, int *, float);
extern void FUN_00055be8(void *, Vec4 *);
extern void FUN_00092d18(void *, int, Tag);
extern void *FUN_0004c898(void *, void *);
extern void *FUN_0005931c(void *, void *);
extern void *FUN_000918c8(void *, void *);
extern void *FUN_000917c8(void *, void *);
extern void FUN_0008f3b8(void *, int, char, int, Vec4);
extern void FUN_000903c8(void *, int);
extern void FUN_000c6270(float, float, Cfg *, int);
extern void *FUN_000c5c78(void *, int);
}

extern "C" void FUN_000918d8(Self *self, Vec4 *p2, Vec4 *p3)
{
    int tmp;
    Vec4 v2 = *p2;
    Vec4 v3 = *p3;
    Cfg cfg;
    Vec4 v;
    int i;

    tmp = self->cfg.i.v;
    FUN_000c5cc0(self, &v2, &v3, 0.0f, 0.0f, 0.0f, &tmp, 0.0f);

    self->f284 = 0;
    self->f288 = 0;
    self->f268 = 0;

    v = self->cfg.a;
    FUN_00055be8(&self->f290, &v);

    FUN_00092d18(&self->l1[0], self->l1[1], Tag());
    FUN_00092d18(&self->l2[0], self->l2[1], Tag());

    cfg.vtbl = &__vt__10C_000c24a8;
    cfg.f4 = self->cfg.f4;
    FUN_0004c898(&cfg.a, &self->cfg.a);
    FUN_0004c898(&cfg.b, &self->cfg.b);
    FUN_0004c898(&cfg.c, &self->cfg.c);
    FUN_0004c898(&cfg.d, &self->cfg.d);
    FUN_0005931c(&cfg.e, &self->cfg.e);
    FUN_0005931c(&cfg.f, &self->cfg.f);
    FUN_0005931c(&cfg.g, &self->cfg.g);
    cfg.h[0] = self->cfg.h[0];
    cfg.h[1] = self->cfg.h[1];
    cfg.h[2] = self->cfg.h[2];
    cfg.h[3] = self->cfg.h[3];
    cfg.h[4] = self->cfg.h[4];
    cfg.h[5] = self->cfg.h[5];
    cfg.h[6] = self->cfg.h[6];
    cfg.h[7] = self->cfg.h[7];
    cfg.h[8] = self->cfg.h[8];
    FUN_000918c8(&cfg.i, &self->cfg.i);
    FUN_000917c8(&cfg.j, &self->cfg.j);
    cfg.k = self->cfg.k;
    cfg.count = self->cfg.count;

    i = 0;
    while (1) {
        Vec4 lv = cfg.a;
        FUN_0008f3b8(&self->l1[0], i, 1, cfg.f4, lv);
        if (cfg.count > 0)
            break;
        i++;
        FUN_000c6270(1.0f, 0.0f, &cfg, 0);
    }

    FUN_000903c8(self, 3);
    if (*(int *)(DAT_003e19f0 + 0x3c) == 7)
        self->f264 = 1;
    FUN_000c5c78(&cfg, -1);
}
// hstclone (tag c162207) twin of src/eboot/FUN_0008fcd8.cpp: MISSING_SYMBOLS __vt__10C_000c24a8 has no hstp_trans_main.prx line.
// Next: find the Sharing vtable this function stores (the address the EBOOT twin's 0x00307424 maps to), append the symbol to symbols/hstp_trans_main.prx.txt, re-run hstmatch.
