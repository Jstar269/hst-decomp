/* HSTMATCH module=EBOOT.BIN start=0x0008fcd8 end=0x0008ff48 symbol=FUN_0008fcd8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the local config object is a copy construction written out as explicit calls to the member copy constructors (0x4c644, 0x58694, 0x8fcc8, 0x8fbc8) with the vtable store first; FUN_000c24f0's declared parameter order is (Self*,Vec4*,Vec4*,float,float,float,int*,float), which orders the argument setup like retail. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { float m[16]; } __attribute__((aligned(16)));
struct M144 { float m[36]; } __attribute__((aligned(16)));
struct Four { int v; };
struct Tag { };

/* Configuration block: vtable, four position vectors, three matrices and per-item data; copied into a local snapshot below. */
struct Cfg {
    void *vtbl;
    int unk04;
    int pad[2];
    Vec4 a, b, c, d;
    Mat4 e, f, g;
    float h[9];
    Four i;
    M144 j;
    unsigned char k;
    int count;   /* the snapshot loop ends once this is above zero */
};

struct Self {  /* the Cfg block comes first */
    Cfg cfg;
    char pad1[0x264 - sizeof(Cfg)];
    int unk264;
    int unk268;
    int listA[3];
    int listB[3];
    unsigned char unk284;
    char pad2[3];
    int unk288;
    char pad3[4];
    char unk290;
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

/* Variant of the entity start routine without a frame count: starts the object at pos with velocity vel, then steps a snapshot of its
   configuration until the count becomes positive, recording each step on the first list. */
extern "C" void FUN_0008fcd8(Self *self, Vec4 *pos, Vec4 *vel)
{
    int tmp;
    Vec4 v2 = *pos; /* by-value copies handed to the base setup */
    Vec4 v3 = *vel;
    Cfg cfg;
    Vec4 v;
    int i;

    tmp = self->cfg.i.v;
    FUN_000c24f0(self, &v2, &v3, 0.0f, 0.0f, 0.0f, &tmp, 0.0f);

    self->unk284 = 0;
    self->unk288 = 0;
    self->unk268 = 0;

    v = self->cfg.a;
    FUN_000550c8(&self->unk290, &v);

    FUN_00091080(&self->listA[0], self->listA[1], Tag());
    FUN_00091080(&self->listB[0], self->listB[1], Tag());

    cfg.vtbl = &__vt__10C_000c24a8;
    cfg.unk04 = self->cfg.unk04;
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
        FUN_0008dba8(&self->listA[0], i, 1, cfg.unk04, lv);
        if (cfg.count > 0)
            break;
        i++;
        FUN_000c2aa0(1.0f, 0.0f, &cfg, 0);
    }

    FUN_0008e984(self, 3);
    if (*(int *)(DAT_003386b0 + 0x3c) == 7)
        self->unk264 = 1;
    FUN_000c24a8(&cfg, -1);
}
