/* HSTMATCH module=EBOOT.BIN start=0x000dcd6c end=0x000dd524 symbol=FUN_000dcd6c lang=c++ */
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

extern Game *DAT_003386b0;
extern unsigned char DAT_003386b8;
extern Kinds DAT_003417b8;
extern void *DAT_0033b460;

extern "C" {
Player *FUN_0008882c(Game *);
Vec4 *FUN_00093838(void *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_000ddf10(Obj *, int);
int FUN_000ddd64(Obj *, Vec4 *, int);
void FUN_0011a504(void *, int, int, float);
}

inline Vec4 operator-(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_00022434(&r, &a, &b); return r; }
inline Vec4 operator*(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_00022450(&r, &a, &b); return r; }

struct Vec2 { float x, z; Vec2(float a, float b) : x(a), z(b) {} float LenSq() const { return x * x + z * z; } };

static inline bool AnyNine()
{
    Kinds *k = &DAT_003417b8;
    for (unsigned i = 0; i < 2; i++)
        if (k->kind[i] == 9)
            return true;
    return false;
}

extern "C" void FUN_000dcd6c(Obj *self, int force, int side)
{
    if (self->m3c != 3 && DAT_003386b8) {
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
                            self->m9c = DAT_003386b0->players[self->player]->side ^ 1;
                            FUN_0011a504(DAT_0033b460, 1, 0, 0.0f);
                        } else
                            self->m5c = 1;
                    } else {
                        self->m5f = 1;
                        self->m5c = 1;
                        self->m9c = DAT_003386b0->players[self->player]->side ^ 1;
                    }
                }
            } else if (self->m90 == 1 && self->m61 && self->mac == 1 && self->m94 != side) {
                int id = self->m98;
                self->m63 = 0;
                if (id == FUN_0008882c(DAT_003386b0)->id) {
                    if (self->m8c == 1)
                        DAT_003386b0->counters->n1--;
                    if (self->m8c == 2)
                        DAT_003386b0->counters->n2--;
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
                if (FUN_000ddf10(self, 1)) {
                    if (self->m61) {
                        int id = self->m98;
                        self->m63 = 0;
                        if (id == FUN_0008882c(DAT_003386b0)->id) {
                            if (self->m8c == 1)
                                DAT_003386b0->counters->n1--;
                            if (self->m8c == 2)
                                DAT_003386b0->counters->n2--;
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
                            self->m9c = DAT_003386b0->players[self->player]->side ^ 1;
                            FUN_0011a504(DAT_0033b460, 1, 0, 0.0f);
                        } else
                            self->m5c = 1;
                    } else {
                        self->m5f = 1;
                        self->m5c = 1;
                        self->m9c = DAT_003386b0->players[self->player]->side ^ 1;
                    }
                }
            } else {
                if (FUN_000ddf10(self, 0)) {
                    self->m64 = 1;
                    self->m78 = self->m98;
                } else {
                    self->m5c = 1;
                    self->m9c = self->ball->side ^ 1;
                    if (self->ball->pos.z * DAT_003386b0->players[self->ball->owner]->scale.z > 0.0f || force)
                        self->m84 = 1;
                }
            }
            if (self->m64) {
                Player *pl = FUN_0008882c(DAT_003386b0);
                Ball *b = self->ball;
                if (pl->side == b->side && !self->m61) {
                    Vec4 p = b->pos;
                    Vec4 t = *FUN_00093838(DAT_003386b0->players[b->side ^ 1]->target);
                    Vec4 d = p - t;
                    if (Vec2(d.x, d.z).LenSq() >= 49.0f || self->m90 == 1)
                        self->m71 = 1;
                }
            } else {
                Player *pl = FUN_0008882c(DAT_003386b0);
                Ball *b = self->ball;
                if (pl->side != b->side) {
                    Vec4 p = b->pos;
                    Vec4 t = *FUN_00093838(FUN_0008882c(DAT_003386b0)->target);
                    Vec4 d = p - t;
                    if (Vec2(d.x, d.z).LenSq() < 2.25f)
                        self->m72 = 1;
                }
            }
        } else if (self->mac == 2) {
            self->m5c = 1;
            self->m9c = self->ball->side;
            Player *me = FUN_0008882c(DAT_003386b0);
            Player *cur = FUN_0008882c(DAT_003386b0);
            if (self->m9c != cur->side) {
                Vec4 *t = FUN_00093838(me->target);
                Ball *b = self->ball;
                float bz = b->Pos().z;
                if (fabsf(bz) < fabsf(t->z)) {
                    Vec4 p = b->Pos();
                    Vec4 v;
                    Vec4 s = DAT_003386b0->players[b->owner]->scale;
                    v = p * s;
                    if (FUN_000ddd64(self, &v, self->m90 == 1))
                        self->m73 = 1;
                } else if (b->m23c == 0 && b->m238 == 2)
                    self->m74 = 1;
            }
        }
    }
}
