/* HSTMATCH module=hstp_trans_main.prx start=0x0022ab4c end=0x0022ad10 symbol=FUN_0022ab4c lang=c++ */
/* Clone of src/eboot/ease_widgets_setup_0021b5d8.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the f84 sub-object pointer is read once into a local; the three-widget loop clamps DAT_003f34a0 with an inline `Clamp(const float &v, const float &lo, const float &hi)` returning `v < lo ? lo : (!(v > hi) ? v : hi)` by value (retail reloads lo/hi in the branch slots). */

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
    extern float DAT_003f3490;
    extern float DAT_003f3494;
    extern float DAT_003f34a0;
    extern int DAT_0039835c;
    extern int DAT_00398504;
    extern float DAT_00398560;
    extern float DAT_00398564;

    void FUN_0022ad48();
    int FUN_0020d1e0(int, int, int);
    void FUN_000143b0(void *, int, int);
    void FUN_00113a50(Target *);
    void FUN_000224c0(Vec4 *out, const Vec4 *in, float s);
    void FUN_00108dac(Self *);

    void FUN_0022ab4c(Self *self, int p2, unsigned char p3);
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

static inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_000224c0(&r, &v, s);
    return r;
}

void FUN_0022ab4c(Self *self, int p2, unsigned char p3) {
    self->f5c = p2;
    self->f60 = p3;
    self->f64 = DAT_0039835c;
    self->f198 = 1;
    FUN_0022ad48();

    int val = DAT_00398504 + self->f5c;
    Sub84 *s84 = self->f84;
    s84->f24 = val;
    s84->f28 = val;

    int uVar2 = FUN_0020d1e0(19, 1, 0);
    int uVar3 = FUN_0020d1e0(12, 0, self->f5c);
    FUN_000143b0(&self->f98, uVar2, uVar3);

    Target *target = self->f90;
    target->f_f8 = &self->f98;
    target->f138 = 0;
    FUN_00113a50(target);

    Target *t = self->f90;
    t->f118 = 0x80000000;
    Vec4 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 128.0f;
    t->v120 = Scale(v, 0.008f);

    for (int i = 0; i < 3; i++) {
        self->p[i]->f60 = DAT_003f3490;
        self->p[i]->f64 = DAT_003f3494;
        self->p[i]->f78 = Clamp(DAT_003f34a0, DAT_00398560, DAT_00398564);
    }

    FUN_00108dac(self);
    self->p[2]->SetVisible((self->f60 != 0) ^ 1);
}
