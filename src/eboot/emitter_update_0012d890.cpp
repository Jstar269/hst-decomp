/* HSTMATCH module=EBOOT.BIN start=0x0012d890 end=0x0012db64 symbol=FUN_0012d890 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Cfg {
    unsigned flags;       /* bit 0: name is taken from the name field, else from the record address */
    int unk4;
    unsigned name;
    int delayMin;
    int delayMax;
    int repeats;
    unsigned char continuous;
    char pad19[7];
    float unk20;
    float unk24;
};
struct Emit {
    Vec4 pos;
    float radius;
    int cfgIndex;
    int timer;
    int delay;
    int playCount;
    unsigned char waiting;
    char pad25[3];
    int handle;
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
    Cfg *cfgs;      /* 0x8c8 table of 0x28-byte records */
    char pad8cc[8];
    Emit *items;
    int count;
    It begin() { return It(items); }
    It end() { return It((Emit *)((char *)items + count * 0x30)); }
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

extern World *DAT_0034a118;
extern Vec4 DAT_002bc440;
extern int DAT_0034179c;  /* shared manager passed to the start/stop/query helpers */

extern "C" {
unsigned int FUN_0001342c(void);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Emit *);
void FUN_001b210c(float, int *, int *, float);
int FUN_001b1f7c(int *, int);
int FUN_001b28fc(float, float, int *, unsigned, float, float, Emit *, int);
void FUN_001b2240(float, float, float, float, int *, int *, Emit *, int, int, int);

static inline void Start(Emit *e, Cfg *cfg)
{
    unsigned name = (cfg->flags & 1) ? cfg->name : (unsigned)cfg + 1;
    e->handle = FUN_001b28fc(cfg->unk20, cfg->unk24, &DAT_0034179c, name, 0.0f, e->radius, e, 0);
}

static inline bool Eq(Emit *a, Emit *b) { return a == b; }
static inline bool Ne(Emit *a, Emit *b) { return !Eq(a, b); }
struct Rng { unsigned s;  /* linear congruential generator */ int Step() { s = s * 0x343fd + 0x269ec3; return (int)((s >> 16) & 0x7fff); } };
/* Per-frame update: stop emitters outside their radius, otherwise run the repeat/delay cycle. */
void FUN_0012d890(Obj *self)
{
    Emit *e;
    Cfg *cfg;
    Rng rng;
    const Vec4 *src;
    rng.s = FUN_0001342c();
    if (DAT_0034a118 != 0) {
        src = DAT_0034a118->GetPos();
    } else {
        src = &DAT_002bc440;
    }
    Vec4 listener;
    listener.x = src->x;
    listener.y = src->y;
    listener.z = src->z;
    listener.w = src->w;
    for (e = self->begin().p; Ne(e, self->end().p); e = e + 1) {
        cfg = (Cfg *)((char *)self->cfgs + e->cfgIndex * 0x28);
        Vec4 delta;
        FUN_00022434(&delta, &listener, e);
        if (delta.x * delta.x + delta.z * delta.z > e->radius * e->radius) {
            FUN_001b210c(0.0f, &DAT_0034179c, &e->handle, 0.0f);
        } else {
            if (e->waiting != 0) {
                if (e->timer == 0) {
                    e->delay = cfg->delayMin + rng.Step() % (cfg->delayMax - cfg->delayMin);
                }
                if (e->timer == e->delay || cfg->continuous != 0) {
                    Start(e, cfg);
                    e->waiting = 0;
                    e->playCount = 1;
                    e->timer = 0;
                } else {
                    e->timer = e->timer + 1;
                }
            } else {
                if (FUN_001b1f7c(&DAT_0034179c, e->handle) == 0) {
                    if (e->playCount < cfg->repeats) {
                        Start(e, cfg);
                        e->playCount = e->playCount + 1;
                    } else {
                        e->waiting = 1;
                    }
                }
            }
            if (cfg->continuous != 0) {
                FUN_001b2240(cfg->unk20, cfg->unk24, 0.0f, e->radius, &DAT_0034179c, &e->handle, e, 0, 0, 0);
            }
        }
    }
}
}
