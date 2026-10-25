/* HSTMATCH module=EBOOT.BIN start=0x00213b78 end=0x00213f70 symbol=FUN_00213b78 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

struct Stats {
    char pad[0x12c];
    float w[4];
    float base;
};
struct Racket {
    char pad[0x5bc];
    int kind;
};
struct Team {
    char pad[0x70];
    Racket *r[2];
};
struct Player {
    char pad[0x144];
    unsigned side;
    char pad148[0x580 - 0x148];
    Vec4 pos;
    char pad590[0x10];
    float scale5a0;
    float pad5a4;
    float scale5a8;
    char pad5ac[0x7fc - 0x5ac];
    unsigned char hold;
    char pad7fd[0x86a - 0x7fd];
    unsigned char f86a;
    unsigned char f86b;
    unsigned char f86c;
    char pad86d[3];
    float off870;
};

extern "C" {
extern float DAT_002bfccc;
extern volatile float DAT_002efac0;
extern volatile float DAT_002efac4;
extern volatile float DAT_002efac8;
extern Team *DAT_003386b0;
int FUN_000a8494(Player *, Vec4 *);
int FUN_00214044(Player *);
Stats *FUN_00215a58(Player *);
Stats *FUN_00215a20(Player *);
unsigned FUN_0001342c(void);
float *FUN_00093838(int);
float FUN_0021465c(float, float, float, Racket *);
float FUN_00213f70(Player *);
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022518(Vec4 *, const Vec4 *);
Vec4 *FUN_00022498(Vec4 *, const Vec4 *, float);
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

static inline Vec4 Scale(const Vec4 &a, float s)
{
    Vec4 r;
    FUN_00022498(&r, &a, s);
    return r;
}

static inline float Rand()
{
    return 4.656613e-10f * (float)(int)(FUN_0001342c() & ~0x7ff);
}

extern "C" Vec4 FUN_00213b78(Player *p)
{
    Vec4 v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    v.z = p->pos.z;
    if (!FUN_000a8494(p, &p->pos)) {
        if (p->hold || FUN_00214044(p)) {
            p->hold = 1;
            v.z = DAT_002bfccc;
        }
    } else {
        p->hold = 0;
    }
    if (p->hold) {
        p->f86a = 1;
    } else {
        float s = FUN_00215a58(p)->base + FUN_00215a20(p)->base;
        float t = DAT_002efac0;
        t = (DAT_002efac0 > s) ? t : s;
        if (Rand() < 0.01f * t)
            v.z = -11.8871994f;
        float total = 0.0f;
        int i;
        for (i = 0; i < 4; i++) {
            float a = FUN_00215a58(p)->w[i] + FUN_00215a20(p)->w[i];
            float m = DAT_002efac4;
            m = (DAT_002efac4 > a) ? m : a;
            total += m;
        }
        int j;
        float r = Rand();
        for (j = 0; j < 3; j++) {
            float a = FUN_00215a58(p)->w[j] + FUN_00215a20(p)->w[j];
            float m = DAT_002efac8;
            m = (DAT_002efac8 > a) ? m : a;
            r -= m / total;
            if (r < 0.0f)
                break;
        }
        switch (j) {
        case 0:
            v.x = p->pos.x;
            break;
        case 1:
            v.x = p->scale5a0 * *FUN_00093838(DAT_003386b0->r[p->side ^ 1]->kind);
            p->f86b = 1;
            break;
        case 2:
            v.x = 0.0f;
            break;
        case 3:
            v.x = p->scale5a0 * FUN_0021465c(0.0f, v.z * p->scale5a8, 0.0f, DAT_003386b0->r[p->side ^ 1]);
            p->f86c = 1;
            break;
        }
    }
    v.x += p->off870;
    Vec4 d = Sub(v, p->pos);
    d.y = 0.0f;
    FUN_00022518(&d, &d);
    d.w = 0.0f;
    float w = FUN_00213f70(p);
    float k = -w + (w + w) * 4.656613e-10f * (float)(int)(FUN_0001342c() & ~0x7ff);
    Vec4 e = Scale(d, k);
    FUN_00022418(&v, &v, &e);
    return v;
}
