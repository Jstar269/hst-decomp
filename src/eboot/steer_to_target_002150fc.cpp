/* HSTMATCH module=EBOOT.BIN start=0x002150fc end=0x00215630 symbol=FUN_002150fc lang=c++ */
/* Clone of src/sharing_main/steer_to_target_00223f88.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

extern "C" {
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_00022518(Vec4 *out, const Vec4 *v);
}

inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

inline Vec4 operator*(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

inline Vec4 &operator+=(Vec4 &a, const Vec4 &b)
{
    FUN_00022418(&a, &a, &b);
    return a;
}

struct Player {
    char pad0[0x144];
    u32 f144;
    int f148;
    char pad1[0x580 - 0x14c];
    Vec4 pos;
    char pad2[0x5a0 - 0x590];
    Vec4 scale;
    char pad3[0x5bc - 0x5b0];
    int f5bc;
    char pad4[0x869 - 0x5c0];
    unsigned char f869;
    unsigned char f86a;
    unsigned char f86b;
    unsigned char f86c;
    char pad5[0x880 - 0x86d];
    Vec4 target;
    Vec4 f890;
};

struct Match {
    char pad0[0x1d4];
    int f1d4;
    char pad1[0x230 - 0x1d8];
    u32 f230;
};

struct Game {
    char pad0[0x70];
    Player *players[4];
    char pad1[0x88 - 0x80];
    Match *match;
    Player *GetPlayer(int i) { return players[i]; }
};

struct Cfg {
    char pad[0x45];
    bool f45;
};

struct Out {
    char pad[0xa0];
    float fa0;
    float fa4;
    float fa8;
};

extern "C" {
extern Game *DAT_003386b0;
extern Cfg *DAT_00338b44;
extern float DAT_002efaf0;
extern float DAT_002efaf4;
extern float DAT_002efaf8;
extern float DAT_002efafc;
float *FUN_00093838(int handle);
float FUN_000a2cb4(Player *p);
float FUN_0021465c(float a, float b, float c, Player *p);
}

static inline bool F45Clear() { return !DAT_00338b44->f45; }

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" void FUN_002150fc(Player *self, Out *out)
{
    Player *other;

    if (DAT_003386b0->match->f1d4 >= 2) {
        self->f869 = 0;
    }
    if (self->f869 != 0) {
        other = DAT_003386b0->GetPlayer((self->f148 + 2) % 4);
        if (self->f86a != 0) {
            if (self->f144 == DAT_003386b0->match->f230) {
                self->target.x = -DAT_003386b0->GetPlayer(self->f144 ^ 1)->pos.x * 0.5f;
            } else {
                self->f86a = 0;
            }
        }
        if (self->f86b != 0) {
            if (self->f144 == DAT_003386b0->match->f230) {
                if (F45Clear()) {
                    Player *p1;
                    Player *p2;
                    float *f2p;
                    float *f1p;
                    float *f0p;
                    float *f3p;
                    u32 u = self->f144 ^ 1;
                    p1 = DAT_003386b0->GetPlayer(u);
                    p2 = DAT_003386b0->GetPlayer(u + 2);
                    f0p = FUN_00093838(other->f5bc);
                    f1p = FUN_00093838(self->f5bc);
                    f2p = FUN_00093838(p2->f5bc);
                    f3p = FUN_00093838(p1->f5bc);
                    if ((*f3p - *f2p) * (*f1p - *f0p) < 0.0f) {
                        p1 = p2;
                    }
                    self->target.x = self->scale.x * *FUN_00093838(p1->f5bc);
                    if (self->pos.x > other->pos.x) {
                        self->target.x = Clamp(self->target.x, DAT_002efaf0, DAT_002efaf4);
                    } else {
                        self->target.x = Clamp(self->target.x, DAT_002efaf8, DAT_002efafc);
                    }
                } else {
                    self->target.x = self->scale.x * *FUN_00093838(DAT_003386b0->GetPlayer(self->f144 ^ 1)->f5bc);
                }
            } else {
                self->f86b = 0;
            }
        }
        if (self->f86c != 0) {
            if (self->f144 == DAT_003386b0->match->f230) {
                Player *c;
                float sign;
                if (F45Clear()) {
                    u32 u = self->f144 ^ 1;
                    Player *p2;
                    c = DAT_003386b0->GetPlayer(u);
                    p2 = DAT_003386b0->GetPlayer(u + 2);
                    c = c->pos.z > p2->pos.z ? c : p2;
                    sign = self->pos.x > other->pos.x ? 1.0f : -1.0f;
                } else {
                    c = DAT_003386b0->GetPlayer(self->f144 ^ 1);
                    sign = 0.0f;
                }
                self->target.x = self->scale.x * FUN_0021465c(self->target.x * self->scale.x,
                                                              self->target.z * self->scale.z,
                                                              sign * self->scale.x, c);
            } else {
                self->f86c = 0;
            }
        }
        Vec4 t = self->target;
        if (self->f890.w > 0.0f) {
            t += self->f890 * self->f890.w;
            self->f890.w -= 1.0f;
        }
        Vec4 d = t - self->pos;
        float lenSq = d.x * d.x + d.z * d.z;
        if (lenSq > 0.009999999f) {
            float r = FUN_000a2cb4(self) * 0.5f * 1.1f;
            if (lenSq > r * r) {
                d.y = 0.0f;
                FUN_00022518(&d, &d);
                d.w = 0.0f;
                out->fa0 = d.x;
                out->fa8 = d.z;
            }
        } else if (self->f86b == 0 && self->f86c == 0 && self->f86a == 0) {
            self->f869 = 0;
        }
    }
}
