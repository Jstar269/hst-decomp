/* HSTMATCH module=hstp_trans_main.prx start=0x000e0eb4 end=0x000e166c symbol=FUN_000e0eb4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

extern "C" float fabsf(float);

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Player {
    char pad0[0x144];
    int side;                   /* 0x144 */
    int id;                     /* 0x148 */
    char pad14c[0x5a0 - 0x14c];
    Vec4 scale;                 /* 0x5a0 */
    char pad5b0[0x5bc - 0x5b0];
    void *target;               /* 0x5bc */
};

struct Counters { char pad0[0x1ec]; int n1; char pad1f0[0x208 - 0x1f0]; int n2; };

struct Game {
    char pad0[0x70];
    Player *players[12];        /* 0x70 */
    Counters *counters;         /* 0xa0 */
};

struct Ball {
    char pad0[0x10];
    Vec4 pos;                   /* 0x10 */
    char pad20[0x230 - 0x20];
    int side;                   /* 0x230 */
    int owner;                  /* 0x234 */
    int m238;
    int m23c;
    const Vec4 &Pos() const { return pos; }
};

struct Obj {
    char pad0[0x3c];
    int m3c;
    Ball *ball;                 /* 0x40 */
    unsigned char m44;
    char pad45[0x50 - 0x45];
    int player;                 /* 0x50 */
    char pad54[0x5c - 0x54];
    unsigned char m5c, m5d, m5e, m5f;
    char pad60;
    unsigned char m61, m62, m63, m64;
    char pad65[0x71 - 0x65];
    unsigned char m71, m72, m73, m74;
    char pad75[0x78 - 0x75];
    int m78;
    char pad7c[0x84 - 0x7c];
    unsigned char m84;
    char pad85[0x8c - 0x85];
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    char pada0[0xac - 0xa0];
    int mac;
};

struct Kinds { char pad0[9]; signed char kind[2]; };

extern Game *DAT_003e19f0;
extern unsigned char DAT_003e19f8;
extern Kinds DAT_003eaaf0;
extern void *DAT_003e47a0;

extern "C" {
Player *FUN_00089f84(Game *);
Vec4 *FUN_0009575c(void *);
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022478(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_000e20fc(Obj *, int);
int FUN_000e1f50(Obj *, Vec4 *, int);
void FUN_001256d8(void *, int, int, float);
}

inline Vec4 operator-(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_0002245c(&r, &a, &b); return r; }
inline Vec4 operator*(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_00022478(&r, &a, &b); return r; }

struct Vec2 { float x, z; Vec2(float a, float b) : x(a), z(b) {} float LenSq() const { return x * x + z * z; } };

static inline bool AnyNine()
{
    Kinds *k = &DAT_003eaaf0;
    for (unsigned i = 0; i < 2; i++)
        if (k->kind[i] == 9)
            return true;
    return false;
}

extern "C" void FUN_000e0eb4(Obj *self, int force, int side)
{
    if (self->m3c != 3 && DAT_003e19f8) {
        if (self->m44 && side >= 0 && self->mac <= 0) {
            if (self->m94 == side) {
                self->m5c = 0;
                self->m9c = -1;
            } else {
                self->m5c = 0;
                self->m9c = -1;
                self->m5d = 0;
                self->m5e = 0;
                self->m5f = 0;
                self->m84 = 0;
            }
        }
    }
    if (!self->m5c) {
        if (++self->mac == 1)
            self->m63 = 0;
        if (side >= 0) {
            self->m62 = 1;
            if (self->m90 == 1 && self->m94 == side) {
                if (!self->m5c) {
                    if (self->m8c == 1) {
                        self->m5e = 1;
                        if (AnyNine()) {
                            self->m5c = 1;
                            self->m9c = DAT_003e19f0->players[self->player]->side ^ 1;
                            FUN_001256d8(DAT_003e47a0, 1, 0, 0.0f);
                        } else
                            self->m5c = 1;
                    } else {
                        self->m5f = 1;
                        self->m5c = 1;
                        self->m9c = DAT_003e19f0->players[self->player]->side ^ 1;
                    }
                }
            } else if (self->m90 == 1 && self->m61 && self->mac == 1 && self->m94 != side) {
                int id = self->m98;
                self->m63 = 0;
                if (id == FUN_00089f84(DAT_003e19f0)->id) {
                    if (self->m8c == 1)
                        DAT_003e19f0->counters->n1--;
                    if (self->m8c == 2)
                        DAT_003e19f0->counters->n2--;
                }
                self->m8c--;
                self->m5d = 1;
                self->m5c = 1;
            } else {
                self->m5c = 1;
                self->m9c = side ^ 1;
                if (self->m94 == (side ^ 1))
                    self->m78 = self->m98;
            }
        } else if (self->mac == 1) {
            if (self->m90 == 1) {
                if (FUN_000e20fc(self, 1)) {
                    if (self->m61) {
                        int id = self->m98;
                        self->m63 = 0;
                        if (id == FUN_00089f84(DAT_003e19f0)->id) {
                            if (self->m8c == 1)
                                DAT_003e19f0->counters->n1--;
                            if (self->m8c == 2)
                                DAT_003e19f0->counters->n2--;
                        }
                        self->m8c--;
                        self->m5d = 1;
                        self->m5c = 1;
                    } else {
                        self->m64 = 1;
                        self->m78 = self->m98;
                    }
                } else if (!self->m5c) {
                    if (self->m8c == 1) {
                        self->m5e = 1;
                        if (AnyNine()) {
                            self->m5c = 1;
                            self->m9c = DAT_003e19f0->players[self->player]->side ^ 1;
                            FUN_001256d8(DAT_003e47a0, 1, 0, 0.0f);
                        } else
                            self->m5c = 1;
                    } else {
                        self->m5f = 1;
                        self->m5c = 1;
                        self->m9c = DAT_003e19f0->players[self->player]->side ^ 1;
                    }
                }
            } else {
                if (FUN_000e20fc(self, 0)) {
                    self->m64 = 1;
                    self->m78 = self->m98;
                } else {
                    self->m5c = 1;
                    self->m9c = self->ball->side ^ 1;
                    if (self->ball->pos.z * DAT_003e19f0->players[self->ball->owner]->scale.z > 0.0f || force)
                        self->m84 = 1;
                }
            }
            if (self->m64) {
                Player *pl = FUN_00089f84(DAT_003e19f0);
                Ball *b = self->ball;
                if (pl->side == b->side && !self->m61) {
                    Vec4 p = b->pos;
                    Vec4 t = *FUN_0009575c(DAT_003e19f0->players[b->side ^ 1]->target);
                    Vec4 d = p - t;
                    if (Vec2(d.x, d.z).LenSq() >= 49.0f || self->m90 == 1)
                        self->m71 = 1;
                }
            } else {
                Player *pl = FUN_00089f84(DAT_003e19f0);
                Ball *b = self->ball;
                if (pl->side != b->side) {
                    Vec4 p = b->pos;
                    Vec4 t = *FUN_0009575c(FUN_00089f84(DAT_003e19f0)->target);
                    Vec4 d = p - t;
                    if (Vec2(d.x, d.z).LenSq() < 2.25f)
                        self->m72 = 1;
                }
            }
        } else if (self->mac == 2) {
            self->m5c = 1;
            self->m9c = self->ball->side;
            Player *me = FUN_00089f84(DAT_003e19f0);
            Player *cur = FUN_00089f84(DAT_003e19f0);
            if (self->m9c != cur->side) {
                Vec4 *t = FUN_0009575c(me->target);
                Ball *b = self->ball;
                float bz = b->Pos().z;
                if (fabsf(bz) < fabsf(t->z)) {
                    Vec4 p = b->Pos();
                    Vec4 v;
                    Vec4 s = DAT_003e19f0->players[b->owner]->scale;
                    v = p * s;
                    if (FUN_000e1f50(self, &v, self->m90 == 1))
                        self->m73 = 1;
                } else if (b->m23c == 0 && b->m238 == 2)
                    self->m74 = 1;
            }
        }
    }
}
