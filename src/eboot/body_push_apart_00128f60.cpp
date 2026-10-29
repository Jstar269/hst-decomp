/* HSTMATCH module=EBOOT.BIN start=0x00128f60 end=0x00129214 symbol=FUN_00128f60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the squared reach is built as `float reach = 0.001f; reach += dia;` so MWCC does not CSE it with the later `dia + 0.001f` argument; names and types await human review. */
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

/* Body types that take part in the push (Type() results). */
#define BODY_TYPE_PUSHABLE_A 2
#define BODY_TYPE_PUSHABLE_B 3

/* Pushes pos away from every other active body of the pushable types that is within reach (two radii apart),
   keeping the point `height` above the body's origin for the distance test; returns 1 when any body moved it. */
extern "C" int FUN_00128f60(Obj *self, Vec4 *pos, float height)
{
    if (self != 0 && self->active == 0)
        return 0;
    BodyList &bodies = DAT_0034a114->bodies;
    int hit = 0;
    for (BodyIt it = bodies.begin(); it != bodies.end(); ++it) {
        Body *b = *it;
        if (b == static_cast<Body *>(self))
            continue;
        if ((b->Type() == BODY_TYPE_PUSHABLE_A || b->Type() == BODY_TYPE_PUSHABLE_B) && b->active != 0) {
            Obj *other = static_cast<Obj *>(b);
            float radius = DAT_002da3c0;
            Vec4 lift(0.0f, height - (radius + 0.001f), 0.0f, 0.0f);
            Vec4 other_pos = *other->Pos() + lift;
            Vec4 delta = other_pos - (*pos + lift);
            float dist_sq = FUN_000224d8(&delta, &delta);
            float diameter = radius * 2.0f;
            float reach = 0.001f;
            reach += diameter;
            if (dist_sq > reach * reach)
                continue;
            FUN_00022518(&delta, &delta);
            delta.w = 0.0f;
            FUN_00022498(&delta, &delta, diameter + 0.001f);
            *pos = other_pos - delta;
            FUN_00022434(pos, pos, &lift);
            hit = 1;
        }
    }
    return hit;
}
