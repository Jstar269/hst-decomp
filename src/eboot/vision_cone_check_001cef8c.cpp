/* HSTMATCH module=EBOOT.BIN start=0x001cef8c end=0x001cf264 symbol=FUN_001cef8c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

/* Return true when `other` (a body of one of the checked types, not the ball) lies inside the cone angle and passes the net and facing tests. */
extern "C" bool FUN_001cef8c(Cone *self, Body *other)
{
    if (other->active != 0) {
        bool candidate = other->Type() == 3;
        if (!candidate)
            candidate = other->Type() == 5;
        if (!candidate)
            candidate = other->Type() == 4;
        if (candidate && other != static_cast<Body *>(DAT_0034a118)) {
            Vec4 dir = Direction(*other->Pos() - self->pos);
            float angle_to = FUN_0000c5bc(Clamp(FUN_000224d8(&self->dir, &dir), DAT_002ea2d4, DAT_002ea2d8));
            if (angle_to < self->angle) {
                bool is_player = other->Type() == 2;
                if (!is_player)
                    is_player = other->Type() == 3;
                if (is_player) {
                    Player *player = FUN_00288a84(other);
                    if (!FUN_00127870(player->CtrlId()) && !FUN_00127a20(player->CtrlId())) {
                        if (FUN_000224d8(&FUN_00093818(player)->dir, &self->dir) >= 0.0f)
                            return false;
                    }
                } else if (other->Type() == 4) {
                    Post *post = FUN_00288af0(other);
                    if (FUN_000224d8(&post->net->normal, &self->dir) >= 0.0f)
                        return false;
                    if (FUN_000224d8(&post->net->normal, &dir) >= 0.0f)
                        return false;
                }
                return true;
            }
        }
    }
    return false;
}
