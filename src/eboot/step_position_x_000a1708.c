/* HSTMATCH module=EBOOT.BIN start=0x000a1708 end=0x000a1a78 symbol=FUN_000a1708 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sideways step of a player: save the position, return early while any of three state flags is set; take
   the direction from the analog x axis (FUN_000a2c58 = dead-zone test + atan2f) or from two 2-bit input
   fields, pick message ids, then move x by 0.01 * DAT_0034125c * sinf(angle) mirrored by the court side,
   clamped to [DAT_002bfcd0, limit - 0.8], let FUN_000a3460 resolve the move and accept it only when the
   resolved position equals the wanted one. Compiled as C: the materialised compare results are int (no
   andi), only the sign flag is an unsigned char. The early return puts the function in MWCC's "broken
   cleanup" mode (dead delay-slot originals). */
typedef struct Cfg Cfg;
typedef struct Node Node;
typedef struct Sub Sub;
typedef struct Input Input;
typedef struct Self Self;
typedef struct Vec4 Vec4;
struct Cfg {
    char pad[0x45];
    unsigned char f45;
    char pad1[0x58 - 0x46];
    int side;
};
struct Node {
    char pad[0xf0];
    int id;
};
struct Sub {
    char pad[0x58];
    Node *node;
};
struct Input {
    char pad[0x89];
    signed char btn0 : 2;
    signed char btn1 : 2;
    signed char btn2 : 2;
    signed char btn3 : 2;
    char pad1[0xa0 - 0x8a];
    float x;
};
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Self {
    char pad0[0x150];
    int f150;
    char pad1[0x409 - 0x154];
    unsigned char f409;
    char pad2[0x411 - 0x40a];
    unsigned char f411;
    char pad3[0x419 - 0x412];
    unsigned char f419;
    char pad4[0x424 - 0x41a];
    int f424;
    char pad5[0x580 - 0x428];
    Vec4 pos;
    Vec4 prev;
    char pad6[0x5bc - 0x5a0];
    Sub *sub;
};
extern Cfg *DAT_00338b44;
extern float DAT_0034125c;
extern float DAT_002bfcd0;

static inline float Clamp(float v, const float *lo, const float *hi)
{
    return v < *lo ? *lo : (!(v > *hi) ? v : *hi);
}

static inline int VecEqual(const Vec4 *a, const Vec4 *b)
{
    return a->x == b->x && a->y == b->y && a->z == b->z && a->w == b->w;
}

unsigned char FUN_000a2c58(float x, float y, Self *self, float *angle);
int FUN_00093b00(Sub *sub, int arg);
float FUN_0000bf34(float x); /* sinf */
void FUN_000a3460(Vec4 *out, Self *self, Vec4 *want, Vec4 *prev);
void FUN_000b237c(Self *self, float speed1, int id1, unsigned char c1, int id2, unsigned char c2, float speed2,
                  unsigned char extra, int flag1, int flag2, float add);

void FUN_000a1708(Self *self, Input *in)
{
    int ok;
    float angle;
    Sub *sub;
    int id1;
    int id2;
    int kind;

    self->prev.x = self->pos.x;
    self->prev.y = self->pos.y;
    self->prev.z = self->pos.z;
    self->prev.w = self->pos.w;
    if (self->f409 != 0 || self->f411 != 0 || self->f419 != 0) {
        return;
    }
    angle = 0.0f;
    ok = FUN_000a2c58(in->x, 0.0f, self, &angle);
    if (ok == 0) {
        float x = 0.0f;
        if (!(in->btn3 < 0)) {
            x = -1.0f;
        }
        if (!(in->btn1 < 0)) {
            x = 1.0f;
        }
        ok = FUN_000a2c58(x, 0.0f, self, &angle);
    }
    sub = self->sub;
    id1 = 0x7fff;
    id2 = 0x7fff;
    if (sub->node != 0) {
        kind = sub->node->id;
    } else {
        kind = -1;
    }
    if (self->f424 < 1 && ((kind != 0x8c && kind != 0x8e) || FUN_00093b00(sub, 0) != 0)) {
        id1 = 0x8a;
        id2 = 0x8b;
    }
    if (ok != 0) {
        float d = 0.01f * DAT_0034125c * FUN_0000bf34(angle);
        float limit;
        float hi;
        float side;
        Vec4 want;
        Vec4 out;
        if (DAT_00338b44->f45 != 0) {
            limit = 4.1148f;
        } else {
            limit = 5.4863997f;
        }
        side = (float)DAT_00338b44->side;
        want.x = self->pos.x;
        want.y = self->pos.y;
        want.z = self->pos.z;
        want.w = self->pos.w;
        want.x = side * (want.x + d);
        hi = limit - 0.79999995f;
        want.x = side * Clamp(want.x, &DAT_002bfcd0, &hi);
        FUN_000a3460(&out, self, &want, &self->prev);
        if (VecEqual(&out, &want) && self->pos.x != want.x) {
            unsigned char neg = d < 0.0f;
            self->pos.x = want.x;
            if (neg == (self->f150 == 0)) {
                id1 = 0x92;
                id2 = 0x93;
            } else {
                id1 = 0x90;
                id2 = 0x91;
            }
        }
    }
    FUN_000b237c(self, -1.0f, id1, 1, id2, 1, -1.0f, 1, 0, 0, 0.0f);
}
