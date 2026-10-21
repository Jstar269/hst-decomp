/* HSTMATCH module=EBOOT.BIN start=0x001c821c end=0x001c85a8 symbol=FUN_001c821c lang=c++ */
struct Vec4 { float x, y, z, w; };

struct Zone {
    int id;
    char pad4[0xc];
    Vec4 pos;
    float sx, sy, sz;
    char pad2c[4];
};

struct ZIt {
    Zone *p;
    ZIt() {}
    ZIt(Zone *q) : p(q) {}
    ZIt &operator++() { ++p; return *this; }
    Zone *operator->() const { return p; }
};
inline bool operator==(const ZIt &a, const ZIt &b) { return a.p == b.p; }
inline bool operator!=(const ZIt &a, const ZIt &b) { return !(a == b); }

struct ZoneVec {
    Zone *data;
    int count;
    ZIt begin() { return ZIt(data); }
    ZIt end() { return ZIt(data + count); }
};

struct Game {
    char pad0[0x8e0];
    ZoneVec zones;
    char pad8e8[0x1320 - 0x8e8];
    char sub[4];
    void *f1324;
};

struct Cam {
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
    virtual Vec4 *GetPos();
};

struct Info {
    int pad0;
    int f4;
    struct A { char pad[8]; int f8; } *f8;
    struct B { char pad[0x60]; char **f60; int f64; } *fc;
};

struct Obj {
    char pad0[0xc4];
    int fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    int fdc;
    unsigned char fe0;
    char pade1;
    unsigned char fe2;
    char pade3[0xec - 0xe3];
    int fec;
    char padf0[0xf7 - 0xf0];
    unsigned char ff7;
    unsigned char ff8;
    char padf9[0x114 - 0xf9];
    char f114;
};

extern "C" {
extern Game *DAT_0033b574;
extern Cam *DAT_0034a118;
extern unsigned char DAT_0034a11c;
extern void *DAT_003415ac;
extern char DAT_002eaa1c[];
extern char DAT_002eaa14[];
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];
extern char DAT_0034179c[];
void FUN_00022434(Vec4 *out, Vec4 *a, Vec4 *b);
int FUN_0014c3d8(void *p);
Info *FUN_0018c9f4(int n);
void FUN_00114168(void *a, int b, char *s, int c, int d);
void FUN_0010b8cc(void *a, int b, int c);
void FUN_001cd88c(void *a, int b, int c);
void FUN_001c2498(void *a);
int FUN_00287418(void *p);
void *FUN_00287460(void *p);
int FUN_00014d64(void *a, char *s);
void FUN_001b4848(float f, void *p);
void FUN_001b359c(float f, void *p);
void FUN_0014d0a8(int n);
void FUN_002869cc(void *p, char *s, int n);
void FUN_001cc830(Obj *o);
float fabsf(float);
}

extern "C" int FUN_001c821c(Obj *self)
{
    if (self->ff7 == 0) {
        bool keep;
        unsigned char hit;
        ZoneVec *zv = &DAT_0033b574->zones;
        ZIt z;
        if (zv->count != 0) {
            keep = false;
            hit = 0;
            for (z = zv->begin(); z != zv->end(); ++z) {
                Vec4 d;
                FUN_00022434(&d, DAT_0034a118->GetPos(), &z->pos);
                if (fabsf(d.x) < z->sx * 0.5f && fabsf(d.y - 0.4f) < z->sy * 0.5f && fabsf(d.z) < z->sz * 0.5f) {
                    int id = z->id;
                    if (id >= 0 && id < 10) {
                        if (FUN_0014c3d8(DAT_0033b574->f1324) == 0) {
                            if (self->ff8 == 0) {
                                if (z->id == 0) {
                                    void *w = (void *)self->fcc;
                                    Info *v = FUN_0018c9f4(0x11);
                                    char *s;
                                    if (v->f4 == 0) s = DAT_002c0e20;
                                    else if (v->f8->f8 < 9) s = DAT_002c0e1c;
                                    else if (v->fc->f64 < 1) s = DAT_002c0e18;
                                    else s = *v->fc->f60;
                                    FUN_00114168(DAT_003415ac, 1, s, 0, 0);
                                    FUN_0010b8cc(**(void ***)((char *)DAT_003415ac + 0x58), 1, 0);
                                    FUN_001cd88c(w, 9, 1);
                                    FUN_001c2498(w);
                                    self->ff8 = 1;
                                } else {
                                    self->fd4 = self->fcc;
                                    self->fd8 = z->id - 1;
                                    self->fdc = -1;
                                    self->fe2 = 0;
                                    if (DAT_0033b574 == 0) {
                                        self->fe0 = 0;
                                    } else if (FUN_00287418(DAT_0033b574->sub) == 0) {
                                        self->fe0 = 0;
                                    } else {
                                        void *t = FUN_00287460(DAT_0033b574->sub);
                                        if (t != 0) self->fe0 = FUN_00014d64(t, DAT_002eaa14) != 0;
                                    }
                                    FUN_001b4848(0.2f, DAT_0034179c);
                                    FUN_001b359c(0.2f, DAT_0034179c);
                                    self->fc4 = 3;
                                    self->fc8 = 0;
                                }
                                return 1;
                            }
                            keep = true;
                        }
                    } else if (id >= 10) {
                        FUN_0014d0a8(DAT_0034a11c == 0);
                        self->fec = z->id;
                        FUN_002869cc(DAT_0033b574->sub, DAT_002eaa1c, 1);
                        FUN_0014d0a8(1);
                        hit = 1;
                    }
                }
            }
            DAT_0034a11c = hit;
            if (self->ff8 != 0 && !keep) self->ff8 = 0;
        }
    }
    if (self->f114 != 0) FUN_001cc830(self);
    return 0;
}
// PARKED (lane sn2, ~10 compiles): 229 of 227 words; ~67 words differ after aligning. Structure verified: the area/zone scan (|dx| < sx/2, |dy-0.4| < sy/2, |dz| < sz/2 with
// FUN_00022434 = vec sub of the virtual-slot-37 position and the zone centre), id 0..9 -> menu zone (id==0: text lookup via 0x18c9f4(17) with the three string cases, else
// state fields fd4/fd8/fdc/fe0/fe2 + "event" lookup), id >= 10 -> "areain", loop with a class iterator whose `!=` is !(a==b) (xor/sltiu/xori), end recomputed from the vector
// each pass. Open: (1) retail s-regs s4 self, s3 keep, s2 hit, s1 &zones, s0 zone (ours has s0/s1 swapped after the declaration order tried), (2) the Vec4 d sits at sp+32 in
// retail (ours 44: the ZIt begin()/end() temporaries bound to const refs take 12 bytes of slots; by-value operator!= instead costs 11 more words), (3) the id==0 text
// branch needs `FUN_00114168/0x10b8cc` argument shapes, (4) frame 64 vs 48.
// near miss from lane sn2 (unreviewed)
