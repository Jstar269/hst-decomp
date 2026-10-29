/* HSTMATCH module=EBOOT.BIN start=0x000b8e2c end=0x000b91fc symbol=FUN_000b8e2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the player query is ONE && expression into a bool; the old f78 is loaded in both arms (`pos.y = self->f78`, the register Ghidra shares with the player y); the second f78 read goes through an identical-layout ObjB alias and the body re-reads `target` through a volatile view so neither is CSE'd with the compare (retail reloads both); `float s = F(..) * K; (c = G)->f200 = s;` keeps the multiply before the pointer load; names and types await human review. */
struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r0, r1, r2, r3; };

struct Cam {
    char pad0[0x1d0];
    Vec4 v1d0;
    Vec4 v1e0;
    Vec4 v1f0;
    float f200;
    float f204;
    float f208;
    char pad20c[8];
    float f214;
};

struct Entry { char pad[0x88]; float v; char pad2[0x18 - 0x8 - 4]; };

struct Obj {
    char pad0[0x3c];
    unsigned char f3c;
    unsigned char f3d;
    char pad3e[0x50 - 0x3e];
    Vec4 v50;
    char pad60[4];
    int f64;
    char pad68[0x78 - 0x68];
    float f78;
    char pad7c[0x88 - 0x7c];
    float tab[1];
};
struct ObjB {
    char pad0[0x3c];
    unsigned char f3c;
    unsigned char f3d;
    char pad3e[0x50 - 0x3e];
    Vec4 v50;
    char pad60[4];
    int f64;
    char pad68[0x78 - 0x68];
    float f78;
    char pad7c[0x88 - 0x7c];
    float tab[1];
};

struct Player {
    char pad0[0x10];
    Vec4 v10;
    char pad20[0x1d4 - 0x20];
    int f1d4;
    char pad1d8[0x22c - 0x1d8];
    int f22c;
    int f230;
    char pad234[0x23c - 0x234];
    int f23c;
};

struct Game {
    char pad0[0x88];
    Player *f88;
};

extern "C" {
extern Cam *DAT_003313c4;
extern Game *DAT_003386b0;
extern float DAT_002d49d4;
extern float DAT_002d49d8;
void FUN_000b8250(Mat4 *m, Obj *self);
float FUN_0000c000(float x);
float FUN_0005c318(Cam *c);
void FUN_0004d374(Mat4 *out, Vec4 *a, Vec4 *b, Vec4 *c);
void FUN_00022548(Vec4 *out, Mat4 *m, Vec4 *in);
float FUN_0000c6dc(float y, float x);
void FUN_0005bbf0(Cam *c, int a, int b, float *p, float *q, int d, int e);
float FUN_0000b8a8(float x);
void FUN_0004d280(float f, Mat4 *a, Mat4 *b);
}

static inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
static inline const float &Min(const float &a, const float &b) { return a < b ? a : b; }

extern "C" void FUN_000b8e2c(Obj *self)
{
    Mat4 m;
    FUN_000b8250(&m, self);
    DAT_003313c4->v1d0 = m.r3;
    DAT_003313c4->v1e0 = m.r2;
    DAT_003313c4->v1f0 = m.r1;
    Cam *c = DAT_003313c4;
    float t = self->tab[self->f64 * 6];
    c->f200 = t;
    c->f214 = FUN_0000c000(0.008726646f * t);
    DAT_003313c4->f204 = 1.0f;
    DAT_003313c4->f208 = 3000.0f;
    bool changed = false;
    float cur = 0.008726646f * FUN_0005c318(DAT_003313c4);
    float target = cur;
    Player *p = DAT_003386b0->f88;
    bool use;
    Vec4 pos;
    int fa = self->f3c;
    int fb = self->f3d;
    if (fa != 0 && fb != 0) {
        pos = self->v50;
        use = true;
    } else {
        pos = p->v10;
        use = p->f22c == 4 && p->f230 >= 0 && p->f1d4 == 0 && p->f23c != 1;
    }
    if (use) {
        Vec4 v;
        Mat4 mm;
        v = pos;
        v.y = v.y - 1.0f;
        FUN_0004d374(&mm, &m.r3, &m.r2, &m.r1);
        FUN_00022548(&v, &mm, &v);
        float a = FUN_0000c6dc(-v.y, v.z);
        target = Max(target, a);
        pos.y = self->f78;
    } else {
        pos.y = self->f78;
    }
    if (pos.y != target) {
        ObjB *alt = (ObjB *)self;
        target = alt->f78 + DAT_002d49d4 * (*(volatile float *)&target - alt->f78);
        self->f78 = target;
        target = target - cur;
        float h = target * 0.5f;
        h = Min(DAT_002d49d8, h);
        float rest = target - h;
        float ang = FUN_0000c000(cur + h);
        float p0, p1;
        FUN_0005bbf0(DAT_003313c4, 0, 0, &p0, &p1, 0, 0);
        float s = FUN_0000b8a8(ang * (p0 / p1)) * 114.59156f;
        (c = DAT_003313c4)->f200 = s;
        c->f214 = FUN_0000c000(c->f200 * 0.008726646f);
        FUN_0004d280(rest, &m, &m);
        changed = true;
        DAT_003313c4->v1e0 = m.r2;
        DAT_003313c4->v1f0 = m.r1;
    }
    if (!changed) self->f78 = cur;
}
