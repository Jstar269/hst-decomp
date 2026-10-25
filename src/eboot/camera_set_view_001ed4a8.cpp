/* HSTMATCH module=EBOOT.BIN start=0x001ed4a8 end=0x001ed87c symbol=FUN_001ed4a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct V4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct M4 {
    V4 r0, r1, r2, r3;
};

struct Entry {
    float f0;
    float angA;
    float angB;
    float dist;
    float f10;
    float height;
    float f18;
    float f1c;
    float f20;
};

struct Cam {
    char pad0[0x40];
    V4 eye;
    char pad50[0x60 - 0x50];
    V4 target;
    char pad70[0x80 - 0x70];
    float m80;
    float m84;
    float m88;
    char pad8c[0x94 - 0x8c];
    int m94;
    char pad98[0x9c - 0x98];
    Entry ent[2];

    int sel;
};

struct Ctx {
    char pad[0x521];
    unsigned char flip;
};

extern "C" {
extern M4 DAT_002bc410;
Ctx *FUN_001ee200(void);
void FUN_0004d280(M4 *, M4 *, float);
void FUN_00022518(V4 *, const V4 *);
void FUN_000224f8(V4 *, const V4 *, const V4 *);
void FUN_00022570(M4 *, M4 *, const M4 *);
void FUN_00022498(V4 *, const V4 *, float);
void FUN_00022418(V4 *, const V4 *, const V4 *);
void FUN_000609f8(Cam *);
void FUN_0006107c(Cam *, const V4 *, float);
}

inline V4 Direction(const V4 &v)
{
    V4 r;
    FUN_00022518(&r, &v);
    r.w = 0.0f;
    return r;
}

inline V4 operator*(const V4 &v, float s)
{
    V4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

inline V4 operator+(const V4 &a, const V4 &b)
{
    V4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}

extern "C" void FUN_001ed4a8(Cam *self, const V4 *pos, const V4 *dir, int idx)
{
    V4 p = *pos;
    V4 d = *dir;
    self->m94 = 0;
    self->sel = idx;
    Entry *e = &self->ent[idx];
    self->m80 = e->f10;
    self->m84 = e->f18;
    self->m88 = e->f1c;
    p.y += e->height;
    self->target = p;
    M4 rot = DAT_002bc410;
    if (FUN_001ee200()->flip)
        FUN_0004d280(&rot, &rot, e->angB);
    else
        FUN_0004d280(&rot, &rot, e->angA);
    M4 m = DAT_002bc410;
    m.r2 = d;
    FUN_00022518(&m.r1, &m.r1);
    m.r1.w = 0.0f;
    FUN_000224f8(&m.r0, &m.r1, &m.r2);
    FUN_00022518(&m.r0, &m.r0);
    m.r0.w = 0.0f;
    FUN_000224f8(&m.r2, &m.r0, &m.r1);
    m.r3 = m.r3;
    FUN_00022570(&m, &m, &rot);
    self->eye = p + Direction(m.r2) * e->dist;
    FUN_000609f8(self);
    FUN_0006107c(self, &DAT_002bc410.r1, e->f20);
    FUN_000609f8(self);
}
