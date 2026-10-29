/* HSTMATCH module=EBOOT.BIN start=0x000dcd6c end=0x000dd524 symbol=FUN_000dcd6c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma opt_strength_reduction off

extern "C" float fabsf(float);

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

#include "hst/types.h"
#include "hst/rule_obj.h"

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
    int unk238;
    int unk23c;
    const Vec4 &Pos() const { return pos; }
};

struct Kinds { char pad0[9]; signed char kind[2]; };
enum { KIND_NINE = 9, KIND_COUNT = 2 }; /* kind value searched for, entries checked */

extern Game *DAT_003386b0;
extern unsigned char DAT_003386b8;
extern Kinds DAT_003417b8;
extern void *DAT_0033b460;

extern "C" {
Player *FUN_0008882c(Game *);
Vec4 *FUN_00093838(void *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
int FUN_000ddf10(RuleObj *, int);
int FUN_000ddd64(RuleObj *, Vec4 *, int);
void FUN_0011a504(void *, int, int, float);
}

/* The rule object keeps its ball pointer in a word (the one comparison below casts directly: the helper changes the register choice there). */
static inline Ball *BallOf(RuleObj *r) { return (Ball *)r->unk40; }

inline Vec4 operator-(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_00022434(&r, &a, &b); return r; }
inline Vec4 operator*(const Vec4 &a, const Vec4 &b) { Vec4 r; FUN_00022450(&r, &a, &b); return r; }

struct Vec2 { float x, z; Vec2(float a, float b) : x(a), z(b) {} float LenSq() const { return x * x + z * z; } };

static inline bool AnyNine()
{
    Kinds *k = &DAT_003417b8;
    for (unsigned i = 0; i < KIND_COUNT; i++)
        if (k->kind[i] == KIND_NINE)
            return true;
    return false;
}

/* Update the rule object's flag bytes and point-winner marker for the given side (negative = none). */
extern "C" void FUN_000dcd6c(RuleObj *self, int force, int side)
{
    if (self->unk3c != 3 && DAT_003386b8) {
        if (self->active && side >= 0 && self->unkac <= 0) {
            if (self->unk94 == side) {
                self->unk5c[0] = 0;
                self->unk9c = RULE_NO_TEAM;
            } else {
                self->unk5c[0] = 0;
                self->unk9c = RULE_NO_TEAM;
                self->unk5c[1] = 0;
                self->unk5c[2] = 0;
                self->unk5c[3] = 0;
                self->unk84[0] = 0;
            }
        }
    }
    if (!self->unk5c[0]) {
        if (++self->unkac == 1)
            self->unk60[3] = 0;
        if (side >= 0) {
            self->unk60[2] = 1;
            if (self->unk90 == 1 && self->unk94 == side) {
                if (!self->unk5c[0]) {
                    if (self->unk8c == 1) {
                        self->unk5c[2] = 1;
                        if (AnyNine()) {
                            self->unk5c[0] = 1;
                            self->unk9c = DAT_003386b0->players[self->base]->side ^ 1;
                            FUN_0011a504(DAT_0033b460, 1, 0, 0.0f);
                        } else
                            self->unk5c[0] = 1;
                    } else {
                        self->unk5c[3] = 1;
                        self->unk5c[0] = 1;
                        self->unk9c = DAT_003386b0->players[self->base]->side ^ 1;
                    }
                }
            } else if (self->unk90 == 1 && self->unk60[1] && self->unkac == 1 && self->unk94 != side) {
                int id = self->unk98;
                self->unk60[3] = 0;
                if (id == FUN_0008882c(DAT_003386b0)->id) {
                    if (self->unk8c == 1)
                        DAT_003386b0->counters->n1--;
                    if (self->unk8c == 2)
                        DAT_003386b0->counters->n2--;
                }
                self->unk8c--;
                self->unk5c[1] = 1;
                self->unk5c[0] = 1;
            } else {
                self->unk5c[0] = 1;
                self->unk9c = side ^ 1;
                if (self->unk94 == (side ^ 1))
                    self->unk78 = self->unk98;
            }
        } else if (self->unkac == 1) {
            if (self->unk90 == 1) {
                if (FUN_000ddf10(self, 1)) {
                    if (self->unk60[1]) {
                        int id = self->unk98;
                        self->unk60[3] = 0;
                        if (id == FUN_0008882c(DAT_003386b0)->id) {
                            if (self->unk8c == 1)
                                DAT_003386b0->counters->n1--;
                            if (self->unk8c == 2)
                                DAT_003386b0->counters->n2--;
                        }
                        self->unk8c--;
                        self->unk5c[1] = 1;
                        self->unk5c[0] = 1;
                    } else {
                        self->unk64[0] = 1;
                        self->unk78 = self->unk98;
                    }
                } else if (!self->unk5c[0]) {
                    if (self->unk8c == 1) {
                        self->unk5c[2] = 1;
                        if (AnyNine()) {
                            self->unk5c[0] = 1;
                            self->unk9c = DAT_003386b0->players[self->base]->side ^ 1;
                            FUN_0011a504(DAT_0033b460, 1, 0, 0.0f);
                        } else
                            self->unk5c[0] = 1;
                    } else {
                        self->unk5c[3] = 1;
                        self->unk5c[0] = 1;
                        self->unk9c = DAT_003386b0->players[self->base]->side ^ 1;
                    }
                }
            } else {
                if (FUN_000ddf10(self, 0)) {
                    self->unk64[0] = 1;
                    self->unk78 = self->unk98;
                } else {
                    self->unk5c[0] = 1;
                    self->unk9c = BallOf(self)->side ^ 1;
                    if (((Ball *)self->unk40)->pos.z * DAT_003386b0->players[BallOf(self)->owner]->scale.z > 0.0f || force)
                        self->unk84[0] = 1;
                }
            }
            if (self->unk64[0]) {
                Player *pl = FUN_0008882c(DAT_003386b0);
                Ball *b = BallOf(self);
                if (pl->side == b->side && !self->unk60[1]) {
                    Vec4 p = b->pos;
                    Vec4 t = *FUN_00093838(DAT_003386b0->players[b->side ^ 1]->target);
                    Vec4 d = p - t;
                    if (Vec2(d.x, d.z).LenSq() >= 49.0f || self->unk90 == 1)
                        self->unk71[0] = 1;
                }
            } else {
                Player *pl = FUN_0008882c(DAT_003386b0);
                Ball *b = BallOf(self);
                if (pl->side != b->side) {
                    Vec4 p = b->pos;
                    Vec4 t = *FUN_00093838(FUN_0008882c(DAT_003386b0)->target);
                    Vec4 d = p - t;
                    if (Vec2(d.x, d.z).LenSq() < 2.25f)
                        self->unk71[1] = 1;
                }
            }
        } else if (self->unkac == 2) {
            self->unk5c[0] = 1;
            self->unk9c = BallOf(self)->side;
            Player *me = FUN_0008882c(DAT_003386b0);
            Player *cur = FUN_0008882c(DAT_003386b0);
            if (self->unk9c != cur->side) {
                Vec4 *t = FUN_00093838(me->target);
                Ball *b = BallOf(self);
                float bz = b->Pos().z;
                if (fabsf(bz) < fabsf(t->z)) {
                    Vec4 p = b->Pos();
                    Vec4 v;
                    Vec4 s = DAT_003386b0->players[b->owner]->scale;
                    v = p * s;
                    if (FUN_000ddd64(self, &v, self->unk90 == 1))
                        self->unk71[2] = 1;
                } else if (b->unk23c == 0 && b->unk238 == 2)
                    self->unk71[3] = 1;
            }
        }
    }
}
