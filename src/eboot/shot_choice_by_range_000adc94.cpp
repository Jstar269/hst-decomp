/* HSTMATCH module=EBOOT.BIN start=0x000adc94 end=0x000ae050 symbol=FUN_000adc94 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

struct Ctx {
    char pad00[0x24];
    float f24;
};

struct Obj {
    char pad00[0x150];
    int hand;
    char pad154[0x4cf - 0x154];
    unsigned char side;
    char pad4d0[0x580 - 0x4d0];
    Vec4 pos;
    char pad590[0x5a0 - 0x590];
    Vec4 scale;
};

struct Rules {
    char pad[0x1d4];
    int f1d4;
};

struct Game {
    char pad[0x88];
    Rules *rules;
};

extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
extern const float DAT_002d4714;
extern const float DAT_002d4718;
extern int DAT_00341284;
extern int DAT_00341288;
extern Game *DAT_003386b0;
void FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_00022450(Vec4 *, const Vec4 *, const Vec4 *);
unsigned FUN_0001342c();
Ctx *FUN_000b3c68(Obj *);
int FUN_000aaae4(Obj *, const Vec4 &, const Vec4 &, unsigned char, int, int, unsigned char *);
int FUN_000a9f90(Obj *, const Vec4 &, const Vec4 &, unsigned char, int, int);
}

template <typename T>
static inline const T &max(const T &a, const T &b) {
    return (a < b) ? b : a;
}

template <typename T>
static inline const T &min(const T &a, const T &b) {
    return (b < a) ? b : a;
}

static inline bool check_range(const float &y, float lim) {
    if (y > lim && y < 0.0f) {
        return true;
    }
    return false;
}

static inline Vec4 Mul(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022450(&r, &a, &b);
    return r;
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

static inline Vec4 Rel(Obj *o, const Vec4 &a, const Vec4 &b, unsigned char side)
{
    Vec4 r = Sub(a, b);
    if (side == (o->hand == 0))
        r.x = max(DAT_002d46a4, r.x);
    else
        r.x = min(DAT_002d46a8, r.x);
    return r;
}

static inline float Rand()
{
    return 4.656613e-10f * (float)(int)(FUN_0001342c() & 0xfffff800);
}

/* Picks an action code (default 13) from the range value n, the input vector and the requested kind: random checks gate codes 9, 8, 10 and 0. */
extern "C" int FUN_000adc94(Obj *self, Vec4 input, int kind, int n)
{
    unsigned char flag;
    int choice = 13;
    if (!(DAT_00341284 < n)) {
        if (!(n < DAT_00341288)) {
            flag = 0;
            int level = DAT_003386b0->rules->f1d4;
            if (FUN_000aaae4(self, Mul(input, self->scale), self->pos, self->side, level, 0, &flag)) {
                if (Rand() < DAT_002d4714) {
                    if (flag) {
                        switch (kind) {
                        case 0:
                            choice = 9;
                            break;
                        case 1:
                            choice = 9;
                            break;
                        case 2:
                            choice = 0;
                            break;
                        }
                    } else {
                        switch (kind) {
                        case 0:
                            choice = 8;
                            break;
                        case 1:
                            choice = 8;
                            break;
                        case 2:
                            choice = 0;
                            break;
                        }
                    }
                }
            } else {
                if (check_range(Rel(self, Mul(input, self->scale), self->pos, self->side).y, -(FUN_000b3c68(self)->f24 * 0.01f))) {
                    if (Rand() < DAT_002d4718)
                        choice = 0;
                } else {
                    if (FUN_000a9f90(self, Mul(input, self->scale), self->pos, self->side, 1, 0) && Rand() < DAT_002d4714)
                        choice = 10;
                }
            }
        }
    }
    return choice;
}
