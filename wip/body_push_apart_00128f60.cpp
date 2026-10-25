/* HSTMATCH module=EBOOT.BIN start=0x00128f60 end=0x00129214 symbol=FUN_00128f60 lang=c++ */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
} __attribute__((aligned(16)));

extern "C" {
void FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
void FUN_00022518(Vec4 *, const Vec4 *);
void FUN_00022498(Vec4 *, const Vec4 *, float);
}

inline Vec4 operator+(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}

inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

inline float Sq(float x) { return x * x; }
inline void Scale(Vec4 &v, const float &s) { FUN_00022498(&v, &v, s); }

struct Body {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual int Type();
    char pad[0x50];
    unsigned char active;
};

struct Shape {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual const Vec4 *Pos();
    char pad[0xdc];
};

struct Obj : Shape, Body {
};

struct BodyIt {
    Body **p;
    BodyIt(Body **q) : p(q) {}
    Body *operator*() const { return *p; }
    BodyIt &operator++() { ++p; return *this; }
};

inline bool operator==(const BodyIt &a, const BodyIt &b) { return a.p == b.p; }
inline bool operator!=(const BodyIt &a, const BodyIt &b) { return !(a == b); }

struct BodyList {
    Body **data;
    int size;
    BodyIt begin() const { return BodyIt(data); }
    BodyIt end() { return BodyIt(data + size); }
};

struct World {
    char pad[0x40];
    BodyList bodies;
};

extern World *DAT_0034a114;
extern float DAT_002da3c0;

extern "C" int FUN_00128f60(Obj *self, Vec4 *pos, float height)
{
    if (self != 0 && self->active == 0)
        return 0;
    BodyList &l = DAT_0034a114->bodies;
    int hit = 0;
    for (BodyIt it = l.begin(); it != l.end(); ++it) {
        Body *b = *it;
        if (b == static_cast<Body *>(self))
            continue;
        if ((b->Type() == 2 || b->Type() == 3) && b->active != 0) {
            Obj *o = static_cast<Obj *>(b);
            float r = DAT_002da3c0;
            Vec4 off(0.0f, height - (r + 0.001f), 0.0f, 0.0f);
            Vec4 a = *o->Pos() + off;
            Vec4 d = a - (*pos + off);
            float lsq = FUN_000224d8(&d, &d);
            float dia = r * 2.0f;
            if (lsq > Sq(dia + 0.001f))
                continue;
            FUN_00022518(&d, &d);
            d.w = 0.0f;
            FUN_00022498(&d, &d, dia + 0.001f);
            *pos = a - d;
            FUN_00022434(pos, pos, &off);
            hit = 1;
        }
    }
    return hit;
}
// NEAR (lane ol2): 170/173 words; everything matches except retail recomputes `dia + 0.001f` (lui/ori/mtc1/add.s)
// for the FUN_00022498 argument after the normalize call, while MWCC CSEs it with the compare's sum (mov.s f12,f20),
// shifting the tail. Ruled out: Sq(float)/Sq(const float&), inline Reach(x) per use, `r = 2.0f*r` reuse, literal-first
// spelling, Scale(Vec4&, const float&), `continue` form, #pragma opt_common_subs off (156 differ).
// near miss from lane ol2 (unreviewed)
