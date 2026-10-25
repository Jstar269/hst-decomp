/* HSTMATCH module=EBOOT.BIN start=0x0008f948 end=0x0008fbc8 symbol=FUN_0008f948 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of FUN_0008fcd8 (same local config copy, written as explicit member-copy-ctor calls); here the last FUN_000c24f0 argument is (float)n / 30.0f and the follow-up call is FUN_0008e984(self, 2). */

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
extern char *DAT_003386b0;
extern void FUN_000c24f0(Self *, Vec4 *, Vec4 *, float, float, float, int *, float);
extern void FUN_000550c8(void *, Vec4 *);
extern void FUN_00091080(void *, int, Tag);
extern void *FUN_0004c644(void *, void *);
extern void *FUN_00058694(void *, void *);
extern void *FUN_0008fcc8(void *, void *);
extern void *FUN_0008fbc8(void *, void *);
extern void FUN_0008dba8(void *, int, char, int, Vec4);
extern void FUN_0008e984(void *, int);
extern void FUN_000c2aa0(float, float, Cfg *, int);
extern void *FUN_000c24a8(void *, int);
}

extern "C" void FUN_0008f948(Self *self, Vec4 *p2, Vec4 *p3, int n)
{
    int tmp;
    Vec4 v2 = *p2;
    Vec4 v3 = *p3;
    Cfg cfg;
    Vec4 v;
    int i;

    tmp = self->cfg.i.v;
    FUN_000c24f0(self, &v2, &v3, 0.0f, 0.0f, 0.0f, &tmp, (float)n / 30.0f);

    self->f284 = 0;
    self->f288 = 0;
    self->f268 = 0;

    v = self->cfg.a;
    FUN_000550c8(&self->f290, &v);

    FUN_00091080(&self->l1[0], self->l1[1], Tag());
    FUN_00091080(&self->l2[0], self->l2[1], Tag());

    cfg.vtbl = &__vt__10C_000c24a8;
    cfg.f4 = self->cfg.f4;
    FUN_0004c644(&cfg.a, &self->cfg.a);
    FUN_0004c644(&cfg.b, &self->cfg.b);
    FUN_0004c644(&cfg.c, &self->cfg.c);
    FUN_0004c644(&cfg.d, &self->cfg.d);
    FUN_00058694(&cfg.e, &self->cfg.e);
    FUN_00058694(&cfg.f, &self->cfg.f);
    FUN_00058694(&cfg.g, &self->cfg.g);
    cfg.h[0] = self->cfg.h[0];
    cfg.h[1] = self->cfg.h[1];
    cfg.h[2] = self->cfg.h[2];
    cfg.h[3] = self->cfg.h[3];
    cfg.h[4] = self->cfg.h[4];
    cfg.h[5] = self->cfg.h[5];
    cfg.h[6] = self->cfg.h[6];
    cfg.h[7] = self->cfg.h[7];
    cfg.h[8] = self->cfg.h[8];
    FUN_0008fcc8(&cfg.i, &self->cfg.i);
    FUN_0008fbc8(&cfg.j, &self->cfg.j);
    cfg.k = self->cfg.k;
    cfg.count = self->cfg.count;

    i = 0;
    while (1) {
        Vec4 lv = cfg.a;
        FUN_0008dba8(&self->l1[0], i, 1, cfg.f4, lv);
        if (cfg.count > 0)
            break;
        i++;
        FUN_000c2aa0(1.0f, 0.0f, &cfg, 0);
    }

    FUN_0008e984(self, 2);
    if (*(int *)(DAT_003386b0 + 0x3c) == 7)
        self->f264 = 1;
    FUN_000c24a8(&cfg, -1);
}
