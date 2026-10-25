/* HSTMATCH module=EBOOT.BIN start=0x001cef8c end=0x001cf264 symbol=FUN_001cef8c lang=c++ */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

extern "C" {
extern float DAT_002ea2d4;
extern float DAT_002ea2d8;
void FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
void FUN_00022518(Vec4 *, const Vec4 *);
float FUN_0000c5bc(float);
int FUN_00127870(int);
bool FUN_00127a20(int);
}

inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}

inline Vec4 Direction(const Vec4 &v)
{
    Vec4 r;
    FUN_00022518(&r, &v);
    r.w = 0.0f;
    return r;
}

inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

struct Body {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual const Vec4 *Pos();
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
    char pad[0xdc];
};

struct Ball : Shape, Body {
};

struct Ctrl {
    char pad[0xf0];
    int id;
};

struct Player {
    char pad[0x58];
    Ctrl *ctrl;
    int CtrlId() const { return ctrl != 0 ? ctrl->id : -1; }
};

struct Net {
    char pad[0x50];
    Vec4 normal;
};

struct Post {
    char pad[0x70];
    Net *net;
};

struct Model {
    char pad[0x20];
    Vec4 dir;
};

struct Cone {
    char pad[0x20];
    Vec4 dir;
    Vec4 pos;
    float angle;
};

extern "C" {
extern Ball *DAT_0034a118;
Player *FUN_00288a84(Body *);
Post *FUN_00288af0(Body *);
Model *FUN_00093818(Player *);
}

extern "C" bool FUN_001cef8c(Cone *self, Body *o)
{
    if (o->active != 0) {
        bool ok = o->Type() == 3;
        if (!ok)
            ok = o->Type() == 5;
        if (!ok)
            ok = o->Type() == 4;
        if (ok && o != static_cast<Body *>(DAT_0034a118)) {
            Vec4 dir = Direction(*o->Pos() - self->pos);
            float c = FUN_0000c5bc(Clamp(FUN_000224d8(&self->dir, &dir), DAT_002ea2d4, DAT_002ea2d8));
            if (c < self->angle) {
                bool pl = o->Type() == 2;
                if (!pl)
                    pl = o->Type() == 3;
                if (pl) {
                    Player *p = FUN_00288a84(o);
                    if (!FUN_00127870(p->CtrlId())) {
                        if (!FUN_00127a20(p->CtrlId())) {
                            if (FUN_000224d8(&FUN_00093818(p)->dir, &self->dir) >= 0.0f)
                                return false;
                        }
                    } else
                        return true;
                } else if (o->Type() == 4) {
                    Post *q = FUN_00288af0(o);
                    if (FUN_000224d8(&q->net->normal, &self->dir) >= 0.0f)
                        return false;
                    if (FUN_000224d8(&q->net->normal, &dir) >= 0.0f)
                        return false;
                }
                return true;
            }
        }
    }
    return false;
}
// NEAR (lane ol2): 182/182 words, 2 differ at +0x204: retail tests FUN_00127a20's result with a plain
// `bnez v0,<shared li v0,1 block>; nop`, ours threads it into `bnezl v0,END; li v0,1`. Everything else exact.
// Ruled out: && form, empty-then/else-if form, explicit `return true` (59 differ), bool local (60), bool/int
// prototypes, `< 0 return true` (119). The A test needed the `if(!A){..}else return true;` shape.
// near miss from lane ol2 (unreviewed)
