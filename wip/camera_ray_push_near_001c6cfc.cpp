/* HSTMATCH module=EBOOT.BIN start=0x001c6cfc end=0x001c6f70 symbol=FUN_001c6cfc lang=c++ */
typedef unsigned int uint;

struct Tag {};

struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Cam {
    char pad0[0x20];
    Vec4 v20;
    Vec4 v30;
};

struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40(Vec4 *data, int count, int flag); // offset 0xa8
};

extern "C" {
extern Obj *DAT_0034a118;
Cam *FUN_00093818(Obj *g);
void FUN_00048f08(Vec4 *out, const Vec4 *in);
int FUN_001caee4(int p2, int p3, Vec4 *out, Vec4 *buf);
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022498(float s, Vec4 *out, const Vec4 *v);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_0012ca08(void *vec, const Vec4 *val, Tag);
void FUN_000e88e4(void *vec, int flag);
}

struct VectorVec4 {
    Vec4 *data;
    uint size;
    uint capacity;

    void push_back(const Vec4 &val)
    {
        if (size < capacity) {
            Vec4 *dst = &data[size];
            if (dst != 0) {
                *dst = val;
            }
            size++;
        } else {
            FUN_0012ca08(this, &val, Tag());
        }
    }
};

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

static inline Vec4 Norm(Vec4 v)
{
    Vec4 r;
    FUN_00048f08(&r, &v);
    return r;
}

static inline Vec4 Scale(float s, const Vec4 &v)
{
    Vec4 r;
    FUN_00022498(s, &r, &v);
    return r;
}

static inline Vec4 Add(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}

extern "C" void FUN_001c6cfc(float scale, int p2, int p3)
{
    if (DAT_0034a118 != 0) {
        Cam *cam = FUN_00093818(DAT_0034a118);
        Vec4 d;
        FUN_00048f08(&d, &cam->v20);
        if (p3 != 0) {
            Vec4 a;
            Vec4 b;
            if (FUN_001caee4(p2, 0, &a, &b) != 0) {
                Vec4 n;
                Vec4 u;
                u = Sub(a, cam->v30);
                FUN_00048f08(&n, &u);
                d = n;
            } else {
                d.w = -d.w;
                d.z = -d.z;
                d.y = -d.y;
                d.x = -d.x;
            }
        }
        VectorVec4 vec;
        vec.data = 0;
        vec.size = 0;
        vec.capacity = 0;
        vec.push_back(cam->v30);
        vec.push_back(Add(cam->v30, Scale(scale, d)));
        DAT_0034a118->m40(vec.data, 2, 0);
        FUN_000e88e4(&vec, 0);
    }
}
// NEAR 0x001c6cfc: 156/157 words, about 30 differ. Frame, all slots, calls, negate block (order w,z,y,x) and Sub/Norm copies match.
// Differs only in the tail: (1) Scale-result copy to sp+80 is loaded x,y,z in mine, z,x,y in retail; (2) sum copy to sp+96 is z,x,y in mine, x,y,z in retail;
// (3) retail reloads val.x from sp+96 for the second push_back (no forwarding) and computes a1=sp+96 before the size test; mine forwards $f2 (one word short).
// Ruled out: Add(const&, Vec4) by value (double copy), push_back(Vec4) by value, named sc/sum locals (slots move), copy-ctor temps, Norm(Sub()) nesting (extra copy).
// Matched idioms: FUN_00093818(DAT_0034a118) (global loaded to a0), Vec4 t; FUN(&t..); Vec4 u; u = Sub(..) gives z,x,y copy and slot 112.
// near miss from lane sn8 (unreviewed)
