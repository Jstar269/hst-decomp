/* HSTMATCH module=EBOOT.BIN start=0x00094978 end=0x00094fa4 symbol=FUN_00094978 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Node look-at controller (PCObject.cpp): while active (pos.w != 0; -1 = fading out) turn the controller's
   angles toward the target direction seen from the parent node (yaw/pitch limited to the DAT_ ranges, step per
   frame), then blend the node's own angles toward them by t and rebuild the node matrix keeping its row scales.
   The early-out is one `||` chain (its last operand compiles as `bnezl; b epilogue`, and the mid-function return
   leaves MWCC's dead delay-slot copies everywhere). Sign()/Clamp() take const float& (reloads), Max/Min are
   MSL-shaped const& templates (stack temporaries at 368/372), Mat4 has a memberwise copy ctor (unscheduled
   lwc1/swc1 pairs) and four Vec4 row members (implicit assignment copies each row as a batch). Names provisional. */

#define HST_ASSERT(cond, text, line) ((void)0)

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

/* Look-at controller state. */
struct LookAt {
    Vec4 pos;                   /* 0x00, w = blend state */
    Vec3 ang;                   /* 0x10 */
    float t;                    /* 0x1c blend weight toward the controller angles */
    int node;                   /* 0x20 name id of the controlled node */
    int parent;                 /* 0x24 name id of its parent node */
};

extern "C" {
float fabsf(float);
int FUN_0002fe80(Model *m, int name);
void FUN_00055240(Mat4 *out, Obj *o, int idx);
Mat4 FUN_0004d268(const Mat4 &m);
Vec4 *FUN_00022548(Vec4 *out, const Mat4 *m, const Vec4 *v);
void FUN_00094690(LookAt *c, Vec3 *out, const Vec4 *dir, const Vec4 &up);
void FUN_000947d4(Mat4 *out, LookAt *c, const Vec3 *ang);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
float FUN_00022e44(float x);
Vec4 *FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_0005922c(Obj *o);
}

#define ANGLE_DAMP 0.7f    /* damping of the target yaw and pitch */
#define ROLL_DAMP 0.5f     /* damping of the roll angle */
#define FADE_OUT_STEP 0.1f /* blend weight lost per call while fading out */
#define FADE_IN_STEP 1.0f  /* blend weight gained per call while active */
#define YAW_PITCH 2        /* angles limited per axis (yaw, pitch) */

extern float DAT_002d2a9c;
extern float DAT_002d2aa0;
extern float DAT_002d2aa4[2][2];
extern float DAT_002d2ab4[2];
extern float DAT_002d2abc[2];

template <class T> inline const T &Max(const T &a, const T &b) { return (a < b) ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return (b < a) ? b : a; }

inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }
inline float Lerp(float a, float b, float t) { return a + t * (b - a); }
inline int Sign(const float &v) { return v < 0.0f ? -1 : 1; }

inline int FindNode(Obj *o, int name)
{
    Model *m = o->skel->model;
    return m ? FUN_0002fe80(m, name) : -1;
}

inline float Length(const Vec4 &v) { return FUN_00022e44(FUN_000224d8(&v, &v)); }

inline Vec4 Scale(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

/* Per-frame update of a node look-at controller on obj. */
extern "C" void FUN_00094978(LookAt *ctl, Obj *obj)
{
    Vec3 ang;
    Vec3 cur;

    if (ctl->pos.w == 0.0f || obj == 0 || obj->skel == 0)
        return;
    int node = FindNode(obj, ctl->node);
    HST_ASSERT(node >= 0, "nodeIndex >= 0", 1745);
    int parent = FindNode(obj, ctl->parent);
    HST_ASSERT(parent >= 0, "parentIndex >= 0", 1747);
    if (ctl->pos.w == -1.0f) {
        ctl->t = Max(DAT_002d2a9c, ctl->t - FADE_OUT_STEP);
        if (ctl->t <= 0.0f)
            ctl->pos.w = 0.0f;
    } else {
        ctl->t = Min(DAT_002d2aa0, ctl->t + FADE_IN_STEP);
        Mat4 pm;
        FUN_00055240(&pm, obj, parent);
        Mat4 inv = FUN_0004d268(pm);
        Vec4 dir;
        FUN_00022548(&dir, &inv, &ctl->pos);
        FUN_00094690(ctl, &ang, &dir, Vec4(0.0f, 1.0f, 0.0f, 0.0f));
        for (int i = 0; i < YAW_PITCH; i++) {
            (&ang.x)[i] *= ANGLE_DAMP;
            if (fabsf((&ang.x)[i]) < DAT_002d2ab4[i]) {
                (&ang.x)[i] = Clamp((&ang.x)[i], DAT_002d2aa4[i][0], DAT_002d2aa4[i][1]);
                float s = Sign((&ang.x)[i] - (&ctl->ang.x)[i]);
                (&ctl->ang.x)[i] += s * DAT_002d2abc[i];
                if (s > 0.0f)
                    (&ctl->ang.x)[i] = (&ctl->ang.x)[i] > (&ang.x)[i] ? (&ang.x)[i] : (&ctl->ang.x)[i];
                else
                    (&ctl->ang.x)[i] = (&ctl->ang.x)[i] < (&ang.x)[i] ? (&ang.x)[i] : (&ctl->ang.x)[i];
            } else {
                float s = Sign((&ctl->ang.x)[i]);
                (&ctl->ang.x)[i] = Clamp((&ctl->ang.x)[i] + s * DAT_002d2abc[i], DAT_002d2aa4[i][0], DAT_002d2aa4[i][1]);
            }
        }
        ctl->ang.z *= ROLL_DAMP;
    }
    Mat4 m = obj->bones[node];
    FUN_00094690(ctl, &cur, &m.r2, m.r1);
    cur.x = Lerp(cur.x, ctl->ang.x, ctl->t);
    cur.y = Lerp(cur.y, ctl->ang.y, ctl->t);
    cur.z = Lerp(cur.z, ctl->ang.z, ctl->t);
    Mat4 rot;
    FUN_000947d4(&rot, ctl, &cur);
    float s0 = Length(m.r0);
    float s1 = Length(m.r1);
    float s2 = Length(m.r2);
    m.r0 = Scale(rot.r0, s0);
    m.r1 = Scale(rot.r1, s1);
    m.r2 = Scale(rot.r2, s2);
    obj->bones[node] = m;
    FUN_0005922c(obj);
}
