/* HSTMATCH module=EBOOT.BIN start=0x0021b5d8 end=0x0021b79c symbol=FUN_0021b5d8 lang=c++ */

#pragma inline_depth(8)

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Slot {
    virtual void func00();
    virtual void SetVisible(int a); // offset 12 (0xc)

    char pad[0x60 - 4];
    float f60;
    float f64;
    char pad68[0x78 - 0x68];
    float f78;
};

struct Target {
    char pad[0xf8];
    void *f_f8;      // 0xf8
    char padfc[0x118 - 0xfc];
    int f118;        // 0x118
    int pad11c;
    Vec4 v120;       // 0x120
    char pad130[8];
    int f138;        // 0x138
};

struct Sub84 {
    char pad[0x24];
    int f24;
    int f28;
};

struct Self {
    char pad0[0x5c];
    int f5c;             // 0x5c (92)
    unsigned char f60;   // 0x60 (96)
    char pad61[3];
    int f64;             // 0x64 (100)
    Slot *p[3];          // 0x68 (104), 0x6c (108), 0x70 (112)
    char pad74[0x84 - 0x74];
    Sub84 *f84;          // 0x84 (132)
    char pad88[8];
    Target *f90;         // 0x90 (144)
    char pad94[4];
    char f98[0x198 - 0x98]; // 0x98 (152)
    unsigned char f198;  // 0x198 (408)
};

extern "C" {
    extern float DAT_0034a160;
    extern float DAT_0034a164;
    extern float DAT_0034a170;
    extern int DAT_002eff90;
    extern int DAT_002f0138;
    extern float DAT_002f0194;
    extern float DAT_002f0198;

    void FUN_0021b7d4();
    int FUN_001fea10(int, int, int);
    void FUN_000143b0(void *, int, int);
    void FUN_0010d4a8(Target *);
    void FUN_00022498(Vec4 *out, const Vec4 *in, float s);
    void FUN_00103480(Self *);

    void FUN_0021b5d8(Self *self, int p2, unsigned char p3);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

void FUN_0021b5d8(Self *self, int p2, unsigned char p3) {
    self->f5c = p2;
    self->f60 = p3;
    self->f64 = DAT_002eff90;
    self->f198 = 1;
    FUN_0021b7d4();

    int val = DAT_002f0138 + self->f5c;
    self->f84->f24 = val;
    self->f84->f28 = val;

    int uVar2 = FUN_001fea10(19, 1, 0);
    int uVar3 = FUN_001fea10(12, 0, self->f5c);
    FUN_000143b0(&self->f98, uVar2, uVar3);

    Target *target = self->f90;
    target->f_f8 = &self->f98;
    target->f138 = 0;
    FUN_0010d4a8(target);

    Target *t = self->f90;
    t->f118 = 0x80000000;
    Vec4 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 128.0f;
    t->v120 = Scale(v, 0.008f);

    for (int i = 0; i < 3; i++) {
        self->p[i]->f60 = DAT_0034a160;
        self->p[i]->f64 = DAT_0034a164;
        float f = (DAT_0034a170 < DAT_002f0194) ? DAT_002f0194 :
                  ((DAT_0034a170 <= DAT_002f0198) ? DAT_0034a170 : DAT_002f0198);
        self->p[i]->f78 = f;
    }

    FUN_00103480(self);
    self->p[2]->SetVisible((self->f60 != 0) ^ 1);
}
// near miss from lane ag4 (unreviewed)
