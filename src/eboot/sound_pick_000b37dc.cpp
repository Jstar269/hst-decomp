/* HSTMATCH module=EBOOT.BIN start=0x000b37dc end=0x000b3b90 symbol=FUN_000b37dc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the sound id lives in a one-int struct (SoundId) so MWCC keeps the default-case `id == 0xd0` test unfolded (`move v0,s0; bne s0,v0`), and the two clamp operands are named floats declared first so their const& temporaries take the top frame slots. */
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

struct SoundId { int id; };
extern "C" int FUN_000b37dc(Player *pl, int unused, int kind, int flag)
{
    float za, zc;
    SoundId r;
    r.id = 0xd0;
    CVec v = DAT_003386b0->ball->vel;
    float spd = FUN_00022e44(FUN_000224d8(&v, &v));
    switch (kind) {
    case 1:
        r.id = 0x5c;
        break;
    case 2:
        if (spd * 3.6f >= 130.0f)
            r.id = 0x5c;
        break;
    case 11:
        r.id = 0x5f;
        break;
    case 12:
        r.id = 0x5e;
        break;
    default: {
        SampleList &h = DAT_003386b0->ball->samples;
        if (r.id == 0xd0) {
            if (h.Count() > 0) {
                CVec d = Sub(h.at(0).pos, pl->m5a0);
                CVec a = d;
                float k = -0.199999988f;
                float s = a.x < 0.0f ? -1 : 1;
                a.x -= k * s;
                za = a.z - k;
                a.z = Max(DAT_002d4778, za);
                if (!FUN_000ddd64(DAT_00338b44, &a, 0)) {
                    CVec c = d;
                    float k2 = 1.5f;
                    float s2 = c.x < 0.0f ? -1 : 1;
                    c.x -= k2 * s2;
                    zc = c.z - k2;
                    c.z = Max(DAT_002d477c, zc);
                    float p = FUN_000ddd64(DAT_00338b44, &c, 0) ? 0.0f : 0.5f;
                    if (pl->Rand() < p)
                        r.id = 0x5e;
                }
            }
        }
        break;
    }
    }
    if (r.id == 0xd0) {
        if (flag || pl->Rand() < 1.0f / 3.0f)
            r.id = 0x5d;
    }
    return r.id;
}
