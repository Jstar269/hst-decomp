/* HSTMATCH module=hstp_trans_main.prx start=0x000b5760 end=0x000b603c symbol=FUN_000b5760 lang=c++ data=0x0037af14 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x0037af14-0x0037af9f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct CVec {
    float x, y, z, w;
    CVec() {}
    CVec(const CVec &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Anim { char pad0[8]; float time; };
struct Track { int m0; Anim **anim; char pad8[0x14 - 8]; float time; char pad18[0x1c - 0x18]; float m1c; char pad20[0x34 - 0x20]; };
struct Clip { char pad0[0x10]; float m10; };
struct Effect {
    char pad0[0xa4];
    Clip *ma4;
    char pada8[0xc0 - 0xa8];
    unsigned char mc0;
    char padc1[0xf0 - 0xc1];
    Track tracks[2];
    int first;
    volatile int last;   /* retail re-reads `last` every iteration of IsActive() */
    char pad160[0x180 - 0x160];
    int m180;
    bool IsActive()
    {
        for (int i = first; i <= last; i++) {
            if (tracks[i].m1c != 0.0f) return true;
        }
        return false;
    }
};

extern "C" CVec *FUN_0009575c(struct Model *);
struct Model {
    const CVec &Pos() { return *FUN_0009575c(this); }
    char pad0[0x50];
    Effect *m50;
    char pad54[0x58 - 0x54];
    Effect *m58;
    char pad5c[0x64 - 0x5c];
    Effect *m64;
};

struct Sample { char pad0[0x10]; CVec pos; };
struct SampleList { char pad0[0xc]; Sample *data; int size;
    int Count() { return size; }
    Sample &at(unsigned i) { if (i >= (unsigned)size) i = size - 1; return data[i]; }
};

struct Ball {
    char pad0[0x10];
    CVec m10;
    char pad20[0x1d4 - 0x20];
    int m1d4;
    char pad1d8[0x230 - 0x1d8];
    int m230;
    char pad234[0x26c - 0x234];
    SampleList samples;
};

struct Player {
    char pad0[0x3c];
    int m3c;
    char pad40[0x144 - 0x40];
    int m144;
    int m148;
    char pad14c[0x168 - 0x14c];
    unsigned seed;
    char pad16c[0x1b4 - 0x16c];
    unsigned char m1b4;
    char pad1b5[0x5a0 - 0x1b5];
    CVec m5a0;
    CVec GetPos() { return m5a0; }
    unsigned char m5b0;
    unsigned char m5b1;
    char pad5b2[0x5bc - 0x5b2];
    Model *model;
    char pad5c0[0x5d0 - 0x5c0];
    Effect effect;
    float Rand()
    {
        seed = seed * 0x343fd + 0x269ec3;
        return (float)((seed >> 16) & 0x7fff) * (1.0f / 32768.0f);
    }
};

extern "C" bool DAT_003e19f8;
static inline bool IsBusy(Player *p) { return DAT_003e19f8 && p->m1b4; }
struct Game {
    char pad0[0x70];
    Player *players[6];
    Ball *ball;
    char pad8c[0xa8 - 0x8c];
    void *sound;
};

struct Field {
    char pad0[0x45];
    unsigned char m45;
    char pad46[0x90 - 0x46];
    int m90;
    bool Flag() { return m45; }
    bool IsIdle() { return !Flag(); }   /* materialises the bool (sltu; xori) as retail does */
};

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }

extern "C" {
extern Game *DAT_003e19f0;
extern Field *DAT_003e1e84;
extern float DAT_0037af10;
extern char DAT_003eaad8[];
void FUN_00059ca4(Effect *, int);
void FUN_00093a70(Model *, int, unsigned char, float, int, unsigned char, float);
void FUN_00059ac0(Effect *, unsigned char, int);
void FUN_000587ac(Effect *, int, int, float);
void FUN_00058814(Effect *, int, int, float, float, float);
void FUN_0005fe20(Effect *, float, int);
void FUN_0005ff00(Effect *, float);
int FUN_000b6164(Player *, int);
void FUN_00058b84(Effect *, Effect *);
void FUN_00059d68(Effect *, int);
void FUN_000b680c(Player *, int);
void FUN_001bfd3c(void *, int, CVec, int);
CVec *FUN_0009575c(Model *);
CVec *FUN_00022478(CVec *, const CVec *, const CVec *);
int FUN_000e1f50(Field *, CVec, int);
void FUN_000b6da8(Player *, int, int);
void FUN_001c3e7c(void *, Player *);
void FUN_001c31b4(void *, int, int, int);
}

extern "C" float fabsf(float);

/* Debug build: assertions print through the (empty) variadic debug printf and hang. */
extern const char DAT_0037a6cc[];   /* assertion message format */
extern const char DAT_0037a704[];   /* source file name */
extern "C" void FUN_00097e3c(...);
#define HST_ASSERT(cond, text, line)     do { if (!(cond)) { FUN_00097e3c(DAT_0037a6cc, text, DAT_0037a704, line); for (;;) {} } } while (0)
static inline CVec Mul(const CVec &a, CVec b) { CVec r; FUN_00022478(&r, &a, &b); return r; }

extern "C" void FUN_000b5760(Player *pl, float speed1, int id1, unsigned char c1, int id2, unsigned char c2, float speed2,
                             unsigned char extra, int flag1, int flag2, float add)
{
    HST_ASSERT((id1 >= -1 && id1 < 277) || id1 == 0x7fff, "(-1 <= no0 && no0 < eANM_NUM) || no0 == SHRT_MAX", 12145);
    HST_ASSERT((id2 >= -1 && id2 < 277) || id2 == 0x7fff, "(-1 <= no1 && no1 < eANM_NUM) || no1 == SHRT_MAX", 12146);
    if (id2 != 0x7fff) {
        if (pl->effect.IsActive())
            FUN_00059ca4(&pl->effect, -1);
    }
    if (flag1 || flag2) {
        Effect *e = pl->model->m58;
        if (e) {
            int ids[2] = { id1, id2 };
            unsigned char cs[2] = { c1, c2 };
            float sp[2] = { speed1, speed2 };
            unsigned char fl[2] = { flag1, flag2 };
            for (int i = 0; i < 2; i++) {
                if (ids[i] != 0x7fff) {
                    FUN_00059ac0(e, cs[i], i);
                    if (fl[i]) {
                        float t = e->tracks[i].anim ? (*e->tracks[i].anim)->time : 0.0f;
                        float a = e->tracks[i].time - t;
                        float b = a + add;
                        FUN_00058814(e, i, ids[i], a, b, b);
                    } else {
                        FUN_000587ac(e, i, ids[i], sp[i]);
                    }
                }
            }
        }
    } else {
        FUN_00093a70(pl->model, id1, c1, speed1, id2, c2, speed2);
    }
    Effect *o = pl->model->m50;
    if (o && o->ma4 == 0) {
        FUN_0005fe20(o, 0.0f, 0xe2);
        o->mc0 = 0;
        FUN_0005ff00(o, o->ma4 ? o->ma4->m10 : 0.0f);
    }
    if (id1 != 0x7fff) pl->m5b0 = 1;
    if (id2 != 0x7fff) pl->m5b1 = 1;
    if (id1 == 0x7fff) return;
    Effect *q = pl->model->m64;
    if (q) {
        int n = FUN_000b6164(pl, id1);
        HST_ASSERT(n >= 0 && n <= 2, "0 <= linkRacket && linkRacket <= 2", 12218);
        bool has = q->m180 != 0;
        if (n < 2) {
            if (!has) FUN_00058b84(q, pl->model->m58);
        } else {
            if (has) FUN_00058b84(q, 0);
        }
        if (id1 >= 0 && n > 0) {
            float s = Max(DAT_0037af10, speed1);
            FUN_00059ac0(q, c1, -1);
            FUN_000587ac(q, 0, id1, s);
            FUN_00059d68(q, -1);
        } else {
            FUN_000587ac(q, 0, -1, 0.0f);
        }
    }
    if (!extra) return;
    FUN_000b680c(pl, id1);
    int snd = 0xd0;
    switch (id1) {
    case 0x82:
    case 0x84:
    case 0x86:
    case 0x9c:
        if (fabsf(DAT_003e19f0->ball->m10.x - pl->model->Pos().x) < 5.0f &&
            fabsf(DAT_003e19f0->ball->m10.z - pl->model->Pos().z) < 5.0f) {
            if (pl->Rand() < 0.5f) {
                snd = 0x60;
            } else if (DAT_003e1e84->IsIdle() && (pl->m144 ^ 1) == DAT_003e19f0->ball->m230 &&
                       DAT_003e19f0->ball->m1d4 < 2) {
                SampleList &h = DAT_003e19f0->ball->samples;
                if (h.Count() > 0) {
                    Player *opp = DAT_003e19f0->players[pl->m148 ^ 1];
                    if (FUN_000e1f50(DAT_003e1e84, Mul(h.at(0).pos, opp->GetPos()), DAT_003e1e84->m90 == 1)) {
                        int side = (pl->m148 + 2) % 4;
                        if (!IsBusy(DAT_003e19f0->players[side]) && pl->Rand() < 0.3f && pl->m3c != 7)
                            FUN_000b6da8(DAT_003e19f0->players[side], 0x7a, 1);
                    }
                }
            }
        }
        FUN_001c3e7c(DAT_003e19f0->sound, pl);
        break;
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
        FUN_001bfd3c(DAT_003eaad8, 0x42, DAT_003e19f0->ball->m10, 0);
        snd = 0x61;
        break;
    }
    if (snd != 0xd0)
        FUN_001c31b4(DAT_003e19f0->sound, pl->m148, snd, 1);
}
