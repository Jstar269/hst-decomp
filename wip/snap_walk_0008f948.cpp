/* HSTMATCH module=EBOOT.BIN start=0x0008f948 end=0x0008fbc8 symbol=FUN_0008f948 lang=c++ */
struct Tag {};
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r[4];
};
struct Handle {
    int v;
    Handle() {}
    Handle(const Handle &o) : v(o.v) {}
};
struct Sub12 {
    int a[3];
};
struct Sub144 {
    int a[36];
};

struct Snap {
    void *vt;
    int id;
    Vec4 v10, v20, v30, v40;
    Mat4 m50, m90, md0;
    float f110, f114, f118, f11c, f120, f124, f128, f12c, f130;
    Handle h134;
    Sub12 s138;
    Sub144 s140;
    unsigned char f1d0;
    int f1d4;

    Vec4 GetPos() const { return v10; }
};

struct List {
    int a;
    int end;
    int c;
};

struct Self : Snap {
    char pad1d8[0x264 - sizeof(Snap)];
    int f264;
    int f268;
    List l26c;
    List l278;
    unsigned char f284;
    int f288;
    Vec4 f290;
};

struct Mgr {
    char pad[0x3c];
    int mode;
};

extern char DAT_00307424[];
extern Mgr *DAT_003386b0;

extern "C" {
void FUN_000c24f0(Self *self, Vec4 a, Vec4 b, Handle h, float x, float y, float z, float t);
void FUN_000550c8(Vec4 *p, Vec4 v);
void FUN_00091080(List *l, int pos, Tag t);
void FUN_0004c644(Vec4 *d, const Vec4 *s);
void FUN_00058694(Mat4 *d, const Mat4 *s);
void FUN_0008fcc8(Handle *d, const Handle *s);
void FUN_0008fbc8(Sub144 *d, const Sub144 *s);
void FUN_0008dba8(List *l, int i, int f, int id, Vec4 v);
void FUN_000c2aa0(float a, float b, Snap *s, int f);
void FUN_0008e984(Self *self, int n);
void FUN_000c24a8(Snap *s, int f);
}

extern "C" void FUN_0008f948(Self *self, Vec4 a, Vec4 b, int frames)
{
    FUN_000c24f0(self, a, b, self->h134, 0.0f, 0.0f, 0.0f, (float)frames / 30.0f);
    self->f284 = 0;
    self->f288 = 0;
    self->f268 = 0;
    FUN_000550c8(&self->f290, self->v10);
    FUN_00091080(&self->l26c, self->l26c.end, Tag());
    FUN_00091080(&self->l278, self->l278.end, Tag());
    Snap tmp;
    tmp.vt = DAT_00307424;
    tmp.id = self->id;
    FUN_0004c644(&tmp.v10, &self->v10);
    FUN_0004c644(&tmp.v20, &self->v20);
    FUN_0004c644(&tmp.v30, &self->v30);
    FUN_0004c644(&tmp.v40, &self->v40);
    FUN_00058694(&tmp.m50, &self->m50);
    FUN_00058694(&tmp.m90, &self->m90);
    FUN_00058694(&tmp.md0, &self->md0);
    tmp.f110 = self->f110;
    tmp.f114 = self->f114;
    tmp.f118 = self->f118;
    tmp.f11c = self->f11c;
    tmp.f120 = self->f120;
    tmp.f124 = self->f124;
    tmp.f128 = self->f128;
    tmp.f12c = self->f12c;
    tmp.f130 = self->f130;
    FUN_0008fcc8(&tmp.h134, &self->h134);
    FUN_0008fbc8(&tmp.s140, &self->s140);
    tmp.f1d0 = self->f1d0;
    tmp.f1d4 = self->f1d4;
    int i = 0;
    for (;;) {
        FUN_0008dba8(&self->l26c, i, 1, tmp.id, tmp.GetPos());
        if (tmp.f1d4 > 0)
            break;
        i++;
        FUN_000c2aa0(1.0f, 0.0f, &tmp, 0);
    }
    FUN_0008e984(self, 2);
    if (DAT_003386b0->mode == 7)
        self->f264 = 1;
    FUN_000c24a8(&tmp, -1);
}
// NEAR: 152/160 words; frame 560 vs retail 576, by-value self->v10 copy for FUN_000550c8 not spilled to sp+32, tmp slot offset 16 low
// near miss from lane ol1 (unreviewed)
