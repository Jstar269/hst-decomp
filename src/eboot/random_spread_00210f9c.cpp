/* HSTMATCH module=EBOOT.BIN start=0x00210f9c end=0x002111cc symbol=FUN_00210f9c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: `goto done` to the one shared return (an early `return` drops retail's unthreaded `b; nop` after the last clamp); names and types await human review. */
// Base width 4.1148 / 5.4864 (13.5 ft / 18 ft in metres) picked by the DAT_00338b44 +0x45 flag.
// With p != 0 a random roll against max(DAT_002efa88, sum of the two +0xa4 stats) * 0.01 returns
// width * p directly; otherwise the width is reduced by max(bound, short stat sum) * 0.01 (stats
// +0xaa when FUN_000a8494(s, s + 0x580) is set, +0xa8 otherwise), scaled by 2/3 and returned as
// p * w plus a random offset in [-w/2, w/2]. The clamps are inline Max helpers taking the bound by
// const reference (retail's double lwc1 of each bound); MaxI converts the short sum inside.
struct Cfg { char pad[0x45]; unsigned char f45; };
struct Stat { char pad[0xa4]; float fa4; short fa8; short faa; };
struct Plr;

extern "C" {
extern Cfg *DAT_00338b44;
extern float DAT_002efa88;
extern float DAT_002efa8c;
extern float DAT_002efa90;
unsigned int FUN_0001342c(void);
int FUN_000a8494(Plr *, char *);
Stat *FUN_00215a20(Plr *);
Stat *FUN_00215a58(Plr *);
}

static inline float Max(const float &a, const float &b)
{
    return a > b ? a : b;
}

static inline float MaxI(const float &a, int b)
{
    return a > (float)b ? a : (float)b;
}

static inline float Rand01(void)
{
    return (float)(int)(FUN_0001342c() & 0xfffff800) * 4.656613e-10f;
}

static inline float RandRange(float lo, float hi)
{
    return lo + (hi - lo) * 4.656613e-10f * (float)(int)(FUN_0001342c() & 0xfffff800);
}

extern "C" float FUN_00210f9c(Plr *s, float p)
{
    float w = DAT_00338b44->f45 != 0 ? 4.1148f : 5.4863997f;
    float m;

    if (p != 0.0f) {
        m = Max(DAT_002efa88, FUN_00215a58(s)->fa4 + FUN_00215a20(s)->fa4);
        if (Rand01() < m * 0.01f) {
            w *= p;
            goto done;
        }
    }
    if (FUN_000a8494(s, (char *)s + 0x580) != 0)
        m = MaxI(DAT_002efa8c, FUN_00215a58(s)->faa + FUN_00215a20(s)->faa);
    else
        m = MaxI(DAT_002efa90, FUN_00215a58(s)->fa8 + FUN_00215a20(s)->fa8);
    w -= m * 0.01f;
    w *= 0.6666667f;
    w = p * w + RandRange(-w * 0.5f, w * 0.5f);
done:
    return w;
}
