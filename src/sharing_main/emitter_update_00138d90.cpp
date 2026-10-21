/* HSTMATCH module=hstp_trans_main.prx start=0x00138d90 end=0x00139064 symbol=FUN_00138d90 lang=c++ */
/* Clone of src/eboot/emitter_update_0012d890.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Cfg {
    unsigned f0;
    int f4;
    unsigned f8;
    int fc;
    int f10;
    int f14;
    unsigned char f18;
    char pad19[7];
    float f20;
    float f24;
};
struct Emit {
    Vec4 pos;
    float f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    unsigned char f24;
    char pad25[3];
    int f28;
    int pad2c;
};
struct It {
    Emit *p;
    It(Emit *q) : p(q) {}
    Emit &operator*() const { return *p; }
    It &operator++() { ++p; return *this; }
};
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }
struct Obj {
    char pad0[0x8c8];
    Cfg *cfgs;
    char pad8cc[8];
    Emit *data;
    int size;
    It begin() { return It(data); }
    It end() { return It((Emit *)((char *)data + size * 0x30)); }
};
class World {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual const Vec4 *GetPos();
};

extern World *DAT_003f3450;
extern Vec4 DAT_002cc290;
extern int DAT_003eaad8;

extern "C" {
unsigned int FUN_0001342c(void);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Emit *);
void FUN_001c01a0(float, int *, int *, float);
int FUN_001c0010(int *, int);
int FUN_001c0990(float, float, int *, unsigned, float, float, Emit *, int);
void FUN_001c02d4(float, float, float, float, int *, int *, Emit *, int, int, int);

static inline void Start(Emit *e, Cfg *c)
{
    unsigned name = (c->f0 & 1) ? c->f8 : (unsigned)c + 1;
    e->f28 = FUN_001c0990(c->f20, c->f24, &DAT_003eaad8, name, 0.0f, e->f10, e, 0);
}

static inline bool Eq(Emit *a, Emit *b) { return a == b; }
static inline bool Ne(Emit *a, Emit *b) { return !Eq(a, b); }
struct Rng { unsigned s; int Step() { s = s * 0x343fd + 0x269ec3; return (int)((s >> 16) & 0x7fff); } };
void FUN_00138d90(Obj *self)
{
    Emit *e;
    Cfg *c;
    Rng rng;
    const Vec4 *pp;
    rng.s = FUN_0001342c();
    if (DAT_003f3450 != 0) {
        pp = DAT_003f3450->GetPos();
    } else {
        pp = &DAT_002cc290;
    }
    Vec4 g;
    g.x = pp->x;
    g.y = pp->y;
    g.z = pp->z;
    g.w = pp->w;
    for (e = self->begin().p; Ne(e, self->end().p); e = e + 1) {
        c = (Cfg *)((char *)self->cfgs + e->f14 * 0x28);
        Vec4 d;
        FUN_0002245c(&d, &g, e);
        if (d.x * d.x + d.z * d.z > e->f10 * e->f10) {
            FUN_001c01a0(0.0f, &DAT_003eaad8, &e->f28, 0.0f);
        } else {
            if (e->f24 != 0) {
                if (e->f18 == 0) {
                    e->f1c = c->fc + rng.Step() % (c->f10 - c->fc);
                }
                if (e->f18 == e->f1c || c->f18 != 0) {
                    Start(e, c);
                    e->f24 = 0;
                    e->f20 = 1;
                    e->f18 = 0;
                } else {
                    e->f18 = e->f18 + 1;
                }
            } else {
                if (FUN_001c0010(&DAT_003eaad8, e->f28) == 0) {
                    if (e->f20 < c->f14) {
                        Start(e, c);
                        e->f20 = e->f20 + 1;
                    } else {
                        e->f24 = 1;
                    }
                }
            }
            if (c->f18 != 0) {
                FUN_001c02d4(c->f20, c->f24, 0.0f, e->f10, &DAT_003eaad8, &e->f28, e, 0, 0, 0);
            }
        }
    }
}
}
