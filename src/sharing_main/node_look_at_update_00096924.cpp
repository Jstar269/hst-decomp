/* HSTMATCH module=hstp_trans_main.prx start=0x00096924 end=0x00096fb0 symbol=FUN_00096924 lang=c++ data=0x00378db8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00378db8-0x00378dc9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Debug-build twin of EBOOT 0x94978 (node_look_at_update_00094978.cpp) with its two asserts kept; node look-at controller (PCObject.cpp): while active (pos.w != 0; -1 = fading out) turn the controller's
   angles toward the target direction seen from the parent node (yaw/pitch limited to the DAT_ ranges, step per
   frame), then blend the node's own angles toward them by t and rebuild the node matrix keeping its row scales.
   The early-out is one `||` chain (its last operand compiles as `bnezl; b epilogue`, and the mid-function return
   leaves MWCC's dead delay-slot copies everywhere). Sign()/Clamp() take const float& (reloads), Max/Min are
   MSL-shaped const& templates (stack temporaries at 368/372), Mat4 has a memberwise copy ctor (unscheduled
   lwc1/swc1 pairs) and four Vec4 row members (implicit assignment copies each row as a batch). Names provisional. */

extern "C" void FUN_00094494(...);
extern char DAT_00378b80[];     /* assertion "%s" failed: file "%s", line %d */
extern char DAT_00378bd0[];     /* PCObject.cpp */
extern char DAT_00378d80[];     /* nodeIndex >= 0 */
#define HST_ASSERT(cond, text, line) \
    do { if (!(cond)) { FUN_00094494(DAT_00378b80, text, DAT_00378bd0, line); for (;;) {} } } while (0)

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
} __attribute__((aligned(16)));

struct Vec3 { float x, y, z; };

struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o)
    {
        r0.x = o.r0.x; r0.y = o.r0.y; r0.z = o.r0.z; r0.w = o.r0.w;
        r1.x = o.r1.x; r1.y = o.r1.y; r1.z = o.r1.z; r1.w = o.r1.w;
        r2.x = o.r2.x; r2.y = o.r2.y; r2.z = o.r2.z; r2.w = o.r2.w;
        r3.x = o.r3.x; r3.y = o.r3.y; r3.z = o.r3.z; r3.w = o.r3.w;
    }
};

struct Model;
struct Skel { char pad0[8]; Model *model; };

struct Obj {
    char pad0[0x8c];
    Skel *skel;                 /* 0x8c */
    char pad90[0x160 - 0x90];
    Mat4 *bones;                /* 0x160 */
};

struct Cam {
    Vec4 pos;                   /* 0x00, w = blend state */
    Vec3 ang;                   /* 0x10 */
    float t;                    /* 0x1c */
    int node;                   /* 0x20 */
    int parent;                 /* 0x24 */
};

extern "C" {
float fabsf(float);
int FUN_0002fea8(Model *m, int name);
void FUN_00055d60(Mat4 *out, Obj *o, int idx);
Mat4 FUN_0004d5e0(const Mat4 &m);
Vec4 *FUN_00022570(Vec4 *out, const Mat4 *m, const Vec4 *v);
void FUN_0009663c(Cam *c, Vec3 *out, const Vec4 *dir, const Vec4 &up);
void FUN_00096780(Mat4 *out, Cam *c, const Vec3 *ang);
float FUN_00022500(const Vec4 *a, const Vec4 *b);
float FUN_00022e6c(float x);
Vec4 *FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
void FUN_00059f10(Obj *o);
}

extern float DAT_00378d90;
extern float DAT_00378d94;
extern float DAT_00378d98[2][2];
extern float DAT_00378da8[2];
extern float DAT_00378db0[2];

template <class T> inline const T &Max(const T &a, const T &b) { return (a < b) ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return (b < a) ? b : a; }

inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }
inline float Lerp(float a, float b, float t) { return a + t * (b - a); }
inline int Sign(const float &v) { return v < 0.0f ? -1 : 1; }

inline int FindNode(Obj *o, int name)
{
    Model *m = o->skel->model;
    return m ? FUN_0002fea8(m, name) : -1;
}

inline float Length(const Vec4 &v) { return FUN_00022e6c(FUN_00022500(&v, &v)); }

inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_000224c0(&r, &v, s);
    return r;
}

extern "C" void FUN_00096924(Cam *cam, Obj *obj)
{
    Vec3 ang;
    Vec3 cur;

    if (cam->pos.w == 0.0f || obj == 0 || obj->skel == 0)
        return;
    int node = FindNode(obj, cam->node);
    HST_ASSERT(node >= 0, DAT_00378d80, 1745);
    int parent = FindNode(obj, cam->parent);
    HST_ASSERT(parent >= 0, "parentIndex >= 0", 1747);
    if (cam->pos.w == -1.0f) {
        cam->t = Max(DAT_00378d90, cam->t - 0.1f);
        if (cam->t <= 0.0f)
            cam->pos.w = 0.0f;
    } else {
        cam->t = Min(DAT_00378d94, cam->t + 1.0f);
        Mat4 pm;
        FUN_00055d60(&pm, obj, parent);
        Mat4 inv = FUN_0004d5e0(pm);
        Vec4 dir;
        FUN_00022570(&dir, &inv, &cam->pos);
        FUN_0009663c(cam, &ang, &dir, Vec4(0.0f, 1.0f, 0.0f, 0.0f));
        for (int i = 0; i < 2; i++) {
            (&ang.x)[i] *= 0.7f;
            if (fabsf((&ang.x)[i]) < DAT_00378da8[i]) {
                (&ang.x)[i] = Clamp((&ang.x)[i], DAT_00378d98[i][0], DAT_00378d98[i][1]);
                float s = Sign((&ang.x)[i] - (&cam->ang.x)[i]);
                (&cam->ang.x)[i] += s * DAT_00378db0[i];
                if (s > 0.0f)
                    (&cam->ang.x)[i] = (&cam->ang.x)[i] > (&ang.x)[i] ? (&ang.x)[i] : (&cam->ang.x)[i];
                else
                    (&cam->ang.x)[i] = (&cam->ang.x)[i] < (&ang.x)[i] ? (&ang.x)[i] : (&cam->ang.x)[i];
            } else {
                float s = Sign((&cam->ang.x)[i]);
                (&cam->ang.x)[i] = Clamp((&cam->ang.x)[i] + s * DAT_00378db0[i], DAT_00378d98[i][0], DAT_00378d98[i][1]);
            }
        }
        cam->ang.z *= 0.5f;
    }
    Mat4 m = obj->bones[node];
    FUN_0009663c(cam, &cur, &m.r2, m.r1);
    cur.x = Lerp(cur.x, cam->ang.x, cam->t);
    cur.y = Lerp(cur.y, cam->ang.y, cam->t);
    cur.z = Lerp(cur.z, cam->ang.z, cam->t);
    Mat4 rot;
    FUN_00096780(&rot, cam, &cur);
    float s0 = Length(m.r0);
    float s1 = Length(m.r1);
    float s2 = Length(m.r2);
    m.r0 = Scale(rot.r0, s0);
    m.r1 = Scale(rot.r1, s1);
    m.r2 = Scale(rot.r2, s2);
    obj->bones[node] = m;
    FUN_00059f10(obj);
}
