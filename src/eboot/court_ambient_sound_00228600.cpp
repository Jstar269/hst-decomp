/* HSTMATCH module=EBOOT.BIN start=0x00228600 end=0x002289a4 symbol=FUN_00228600 lang=c++ data=0x002f2ab8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (11 strings, 0x002f2ab8-0x002f2b4c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Prop kinds, named after the sound each one starts (the string it passes). */
enum {
    PROP_KIND_ROCK = 1,
    PROP_KIND_PET = 2,
    PROP_KIND_GRASS = 4,
    PROP_KIND_BRANCH = 5,
    PROP_KIND_BAMBOO_SHOOT = 7,
    PROP_KIND_CAN = 9,
    PROP_KIND_IRREGULAR = 11,
    PROP_KIND_WATER = 13,
    PROP_KIND_GIMMICK = 15,
    PROP_KIND_18 = 18,
    PROP_KIND_ROCK_23 = 23,
    PROP_KIND_ROCK_24 = 24,
    PROP_KIND_ROCK_25 = 25
};

/* A player counts as close when the distance to the prop's centre is below this. */
#define NEAR_DISTANCE 1.5f

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Player {
    char pad[0x5bc];
    void *body;
};

struct Ctx {
    char pad0[0x70];
    Player *players[4];
};

/* Court prop: centre point, kind, a counter, an active flag and the current sound handle. */
struct Court {
    char pad0[0x110];
    Vec4 center;
    char pad120[0x428 - 0x120];
    int kind;
    int pad42c;
    int count;
    unsigned char active;
    char pad435[0x450 - 0x435];
    int sound;
};

extern "C" {
extern Ctx *DAT_003386b0;
extern char DAT_0034179c[];
extern char DAT_002f2b4c[];
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00093838(void *);
int FUN_001b1f7c(void *, int);
int FUN_001b28f0(void *, char *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

/* Starts the ambient sound that belongs to the prop's kind (when active, or when the held sound handle has ended). */
extern "C" void FUN_00228600(Court *self, int quiet)
{
    switch (self->kind) {
    case PROP_KIND_ROCK:
    case PROP_KIND_ROCK_23:
    case PROP_KIND_ROCK_24:
    case PROP_KIND_ROCK_25:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_rock1");
        break;
    case PROP_KIND_PET:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_pet1");
        if (self->count > 0 && !FUN_001b1f7c(DAT_0034179c, self->sound))
            self->sound = FUN_001b28f0(DAT_0034179c, "court_pet2");
        break;
    case PROP_KIND_GRASS:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_grass");
        break;
    case PROP_KIND_IRREGULAR:
        if (self->active) {
            Vec4 pos = self->center;
            int variant = 1;
            for (int i = 0; i < 4; i++) {
                Player *p = DAT_003386b0->players[i];
                if (p) {
                    Vec4 other = *FUN_00093838(p->body);
                    Vec4 d;
                    d = Sub(pos, other);
                    if (FUN_00022e44(FUN_000224d8(&d, &d)) < NEAR_DISTANCE)
                        variant = 2;
                }
            }
            if (variant == 1)
                FUN_001b28f0(DAT_0034179c, "court_irregular");
            else
                FUN_001b28f0(DAT_0034179c, "court_slip");
        }
        break;
    case PROP_KIND_CAN:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_can2");
        break;
    case PROP_KIND_BRANCH:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_branch");
        break;
    case PROP_KIND_BAMBOO_SHOOT:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_takenoko2");
        break;
    case PROP_KIND_GIMMICK:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, "court_gimmic");
        break;
    case PROP_KIND_WATER:
        if (!FUN_001b1f7c(DAT_0034179c, self->sound))
            self->sound = FUN_001b28f0(DAT_0034179c, "court_water");
        break;
    case PROP_KIND_18:
        if (quiet == 0 && !FUN_001b1f7c(DAT_0034179c, self->sound))
            self->sound = FUN_001b28f0(DAT_0034179c, DAT_002f2b4c);
        break;
    }
}
