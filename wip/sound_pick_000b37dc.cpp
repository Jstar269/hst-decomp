/* HSTMATCH module=EBOOT.BIN start=0x000b37dc end=0x000b3b90 symbol=FUN_000b37dc lang=c++ */
struct CVec {
    float x, y, z, w;
    CVec() {}

} __attribute__((aligned(16)));

struct Sample { char pad0[0x10]; CVec pos; };
struct SampleList { char pad0[0xc]; Sample *data; int size;
    int Count() { return size; }
    Sample &at(unsigned i) { if (i >= (unsigned)size) i = size - 1; return data[i]; }
};

struct Ball {
    char pad0[0x20];
    CVec vel;
    char pad30[0x26c - 0x30];
    SampleList samples;
};

struct Player {
    char pad0[0x168];
    unsigned seed;
    char pad16c[0x5a0 - 0x16c];
    CVec m5a0;
    float Rand()
    {
        seed = seed * 0x343fd + 0x269ec3;
        return (float)((seed >> 16) & 0x7fff) * (1.0f / 32768.0f);
    }
};

struct Game {
    char pad0[0x88];
    Ball *ball;
};

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" {
extern Game *DAT_003386b0;
extern void *DAT_00338b44;
extern float DAT_002d4778;
extern float DAT_002d477c;
float FUN_000224d8(const CVec *, const CVec *);
float FUN_00022e44(float);
CVec *FUN_00022450(CVec *, const CVec *, const CVec *);
int FUN_000ddd64(void *, const CVec *, int);
}

static inline CVec Sub(const CVec &a, const CVec &b) { CVec r; FUN_00022450(&r, &a, &b); return r; }

extern "C" int FUN_000b37dc(Player *pl, int unused, int kind, int flag)
{
    int snd = 0xd0;
    CVec v = DAT_003386b0->ball->vel;
    float spd = FUN_00022e44(FUN_000224d8(&v, &v));
    switch (kind) {
    case 1:
        snd = 0x5c;
        break;
    case 2:
        if (spd * 3.6f >= 130.0f)
            snd = 0x5c;
        break;
    case 11:
        snd = 0x5f;
        break;
    case 12:
        snd = 0x5e;
        break;
    default: {
        Ball *b = DAT_003386b0->ball;
        if (snd == 0xd0) {
            SampleList &h = b->samples;
            if (h.Count() > 0) {
                CVec d = Sub(h.at(0).pos, pl->m5a0);
                CVec a = d;
                float k = -0.199999988f;
                float s = a.x < 0.0f ? -1 : 1;
                a.x -= k * s;
                a.y = Max(DAT_002d4778, a.y - k);
                if (!FUN_000ddd64(DAT_00338b44, &a, 0)) {
                    CVec c = d;
                    float k2 = 1.5f;
                    float s2 = c.x < 0.0f ? -1 : 1;
                    c.x -= k2 * s2;
                    c.y = Max(DAT_002d477c, c.y - k2);
                    float p = FUN_000ddd64(DAT_00338b44, &c, 0) ? 0.0f : 0.5f;
                    if (pl->Rand() < p)
                        snd = 0x5e;
                }
            }
        }
        break;
    }
    }
    if (snd == 0xd0) {
        if (flag)
            snd = 0x5d;
        else if (pl->Rand() < 1.0f / 3.0f)
            snd = 0x5d;
    }
    return snd;
}
// NEAR 2: retail keeps an unfolded `move v0,s0; bne s0,v0` (snd==0xd0 test in default) with ball loaded to v1 before it;
// MWCC folds our test. Tried &&-merge, copy local, split init. Everything else matches.
// near miss from lane ol2 (unreviewed)
