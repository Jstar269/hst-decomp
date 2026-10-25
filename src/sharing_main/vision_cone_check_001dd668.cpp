/* HSTMATCH module=hstp_trans_main.prx start=0x001dd668 end=0x001dd940 symbol=FUN_001dd668 lang=c++ */
/* Clone of src/eboot/vision_cone_check_001cef8c.cpp (hstclone.py tag nxc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));

extern "C" {
extern float DAT_00391f2c;
extern float DAT_00391f30;
void FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
void FUN_00022540(Vec4 *, const Vec4 *);
float FUN_0000c5d4(float);
int FUN_00132ae0(int);
bool FUN_00132c90(int);
}

inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_0002245c(&r, &a, &b);
    return r;
}

inline Vec4 Direction(const Vec4 &v)
{
    Vec4 r;
    FUN_00022540(&r, &v);
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
extern Ball *DAT_003f3450;
Player *FUN_0029a220(Body *);
Post *FUN_0029a28c(Body *);
Model *FUN_0009573c(Player *);
}

extern "C" bool FUN_001dd668(Cone *self, Body *o)
{
    if (o->active != 0) {
        bool ok = o->Type() == 3;
        if (!ok)
            ok = o->Type() == 5;
        if (!ok)
            ok = o->Type() == 4;
        if (ok && o != static_cast<Body *>(DAT_003f3450)) {
            Vec4 dir = Direction(*o->Pos() - self->pos);
            float c = FUN_0000c5d4(Clamp(FUN_00022500(&self->dir, &dir), DAT_00391f2c, DAT_00391f30));
            if (c < self->angle) {
                bool pl = o->Type() == 2;
                if (!pl)
                    pl = o->Type() == 3;
                if (pl) {
                    Player *p = FUN_0029a220(o);
                    if (!FUN_00132ae0(p->CtrlId()) && !FUN_00132c90(p->CtrlId())) {
                        if (FUN_00022500(&FUN_0009573c(p)->dir, &self->dir) >= 0.0f)
                            return false;
                    }
                } else if (o->Type() == 4) {
                    Post *q = FUN_0029a28c(o);
                    if (FUN_00022500(&q->net->normal, &self->dir) >= 0.0f)
                        return false;
                    if (FUN_00022500(&q->net->normal, &dir) >= 0.0f)
                        return false;
                }
                return true;
            }
        }
    }
    return false;
}
