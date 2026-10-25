/* HSTMATCH module=EBOOT.BIN start=0x00228600 end=0x002289a4 symbol=FUN_00228600 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern char DAT_002f2ab8[];
extern char DAT_002f2ac4[];
extern char DAT_002f2ad0[];
extern char DAT_002f2adc[];
extern char DAT_002f2ae8[];
extern char DAT_002f2af8[];
extern char DAT_002f2b04[];
extern char DAT_002f2b10[];
extern char DAT_002f2b20[];
extern char DAT_002f2b30[];
extern char DAT_002f2b40[];
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

extern "C" void FUN_00228600(Court *self, int quiet)
{
    switch (self->kind) {
    case 1:
    case 23:
    case 24:
    case 25:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2ab8);
        break;
    case 2:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2ac4);
        if (self->count > 0 && !FUN_001b1f7c(DAT_0034179c, self->sound))
            self->sound = FUN_001b28f0(DAT_0034179c, DAT_002f2ad0);
        break;
    case 4:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2adc);
        break;
    case 11:
        if (self->active) {
            Vec4 pos = self->center;
            int n = 1;
            for (int i = 0; i < 4; i++) {
                Player *p = DAT_003386b0->players[i];
                if (p) {
                    Vec4 q = *FUN_00093838(p->body);
                    Vec4 d;
                    d = Sub(pos, q);
                    if (FUN_00022e44(FUN_000224d8(&d, &d)) < 1.5f)
                        n = 2;
                }
            }
            if (n == 1)
                FUN_001b28f0(DAT_0034179c, DAT_002f2ae8);
            else
                FUN_001b28f0(DAT_0034179c, DAT_002f2af8);
        }
        break;
    case 9:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2b04);
        break;
    case 5:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2b10);
        break;
    case 7:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2b20);
        break;
    case 15:
        if (self->active)
            FUN_001b28f0(DAT_0034179c, DAT_002f2b30);
        break;
    case 13:
        if (!FUN_001b1f7c(DAT_0034179c, self->sound))
            self->sound = FUN_001b28f0(DAT_0034179c, DAT_002f2b40);
        break;
    case 18:
        if (quiet == 0 && !FUN_001b1f7c(DAT_0034179c, self->sound))
            self->sound = FUN_001b28f0(DAT_0034179c, DAT_002f2b4c);
        break;
    }
}
