/* HSTMATCH module=hstp_trans_main.prx start=0x0006a894 end=0x0006b16c symbol=FUN_0006a894 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Particle emitter update (effect_particle.cpp, per the Sharing twin's assert strings): run the base update
   (0x68850), advance the attached model, look its emitter data up in the effect manager's map by type number,
   and while the model's animation is still running spawn one particle per emit entry whose phase
   fmodf(t + i % period, period) falls inside this frame: take the entry's joint matrix, orthonormalise it,
   fill a ParticleParam (velocity along the z row, gravity, random spin, sizes) and insert the particle into
   the sorted particle list (lower_bound 0x6c298, insert 0x6c96c). When the animation is done, loop it or
   finish once the list is empty; finally update every particle and erase the dead ones.
   Shape notes: the loop bound of the track scan is read through an inline getter (re-read every iteration,
   not CSE'd with the guard); the entry vector is indexed through an inline operator[] (no strength
   reduction); the by-value ParticleParam copy for the out-of-line particle constructor (0x6b16c) sits at the
   frame bottom only when it is made four inline levels down (Particle -> Init -> Init2 -> Init3).
   Sharing twin of EBOOT 0x693cc: same source; the map lookup keeps its debug assert
   (`mmmap.find(typeNo) != mmmap.end()`, effect_particle.cpp line 182, print stub 0x6a70c + endless loop),
   which adds the second find and the end() temporary. Names provisional. */
#pragma inline_depth(8)

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    void SetTranslation(const Vec4 &t) { r3.x = t.x; r3.y = t.y; r3.z = t.z; r3.w = 1.0f; }
};

extern "C" {
Vec4 *FUN_000224c0(Vec4 *out, const Vec4 *v, float s);           /* VFPU scale */
float FUN_00022500(const Vec4 *a, const Vec4 *b);                 /* VFPU dot3 */
Vec4 *FUN_00022540(Vec4 *out, const Vec4 *v);                     /* VFPU normalize3 */
Vec4 *FUN_00022520(Vec4 *out, const Vec4 *a, const Vec4 *b);      /* VFPU cross */
float FUN_0000c9dc(float x, float y);                             /* fmodf */
}

inline Vec4 operator*(const Vec4 &v, float s)
{
    Vec4 r;
    FUN_000224c0(&r, &v, s);
    return r;
}
inline Vec4 operator-(const Vec4 &v) { return Vec4(-v.x, -v.y, -v.z, -v.w); }

struct MotionData { char pad0[8]; float length; };
struct Motion { MotionData *data; };
struct Track {
    Motion *motion;
    char pad4[0x10 - 0x4];
    float frame;
    char pad14[0x34 - 0x14];
    float Length() const { return motion ? motion->data->length : 0.0f; }
};

struct EffectModel;
extern "C" {
void FUN_00059ba8(EffectModel *, float, int);
void FUN_00059d68(EffectModel *, int);
void FUN_00059e58(EffectModel *);
void FUN_0005fec8(EffectModel *);
void FUN_00059c1c(EffectModel *, float, int);
void FUN_0005ff00(EffectModel *, float);
Mat4 FUN_00055d60(EffectModel *, int);
}

struct EffectModel {
    char pad0[0xc4];
    float speed;
    char padc8[0xd0 - 0xc8];
    float speed2;
    char padd4[0xf4 - 0xd4];
    Track tracks[1];
    char pad128[0x158 - 0x128];
    int firstTrack;
    int lastTrack;
    int LastTrack() const { return lastTrack; }
    bool IsEnd()
    {
        for (int i = firstTrack; i <= LastTrack(); i++) {
            if (tracks[i].frame < tracks[i].Length())
                return false;
        }
        return true;
    }
};

struct EmitEntry {
    short joint;    /* 0x00 */
    short texNo;    /* 0x02 */
    short c04;      /* 0x04 */
    short period;   /* 0x06 */
    short life;     /* 0x08 */
    short c0a;      /* 0x0a */
    short spin;     /* 0x0c */
    short s0e;
    short speed;    /* 0x10 */
    short c12;      /* 0x12 */
    short size0;    /* 0x14 */
    short size1;    /* 0x16 */
    short c18;      /* 0x18 */
    short size2;    /* 0x1a */
    short size3;    /* 0x1c */
    short c1e;      /* 0x1e */
    short i20;      /* 0x20 */
    short speed2;   /* 0x22 */
    short gravity;  /* 0x24 */
    short s26;      /* 0x26 */
};

struct EmitEntryVec {
    EmitEntry *data_;
    unsigned size_;
    unsigned cap_;
    unsigned size() const { return size_; }
    EmitEntry &operator[](unsigned n) { return data_[n]; }
};

struct EmitterData {
    char pad0[8];
    EmitEntryVec entries;
    char pad14[0x28 - 0x14];
    bool loop;
};

struct DataNode { DataNode *left, *right, *parent; int key; EmitterData value; };
struct DataIt {
    DataNode *n;
    DataIt(DataNode *p) : n(p) {}
};
inline bool operator!=(const DataIt &a, const DataIt &b) { return a.n != b.n; }
struct DataMap {
    int size;
    DataNode *header[4];
    DataIt end() { return DataIt((DataNode *)header); }
};
/* assertion "%s" failed: file "%s", line %d / mmmap.find(typeNo) != mmmap.end() / effect_particle.cpp */
extern char DAT_003771f4[], DAT_00377220[], DAT_00377244[];
extern "C" void FUN_0006a70c(...);   /* debug print stub */
extern "C" DataIt FUN_0006c774(DataMap *m, const int &key);     /* map::find */

struct EffectMgr {
    DataMap mmmap;
    EmitterData &Get(int typeNo)
    {
        if (!(FUN_0006c774(&mmmap, typeNo) != mmmap.end())) {
            FUN_0006a70c(DAT_003771f4, DAT_00377220, DAT_00377244, 182);
            for (;;) {
            }
        }
        return FUN_0006c774(&mmmap, typeNo).n->value;
    }
};
extern EffectMgr *DAT_003daf68;
extern unsigned DAT_003daf60;     /* random seed */
extern Vec4 DAT_002cc270;         /* unit up vector */

struct ParticleParam;
extern "C" ParticleParam *FUN_0006b7b8(ParticleParam *);

struct ParticleParam {
    Mat4 mtx;
    Vec4 vel;
    Vec4 acc;
    float life;
    float maxLife;
    float scale;
    int texNo;
    int i70;
    float spin;
    float angle;
    float size0;
    float size1;
    float size2;
    float size3;
    float f8c;
    float f90;
    unsigned char c94, c95, c96, c97, c98;
    ParticleParam() { FUN_0006b7b8(this); }
    ParticleParam(const ParticleParam &o)
        : mtx(o.mtx), vel(o.vel), acc(o.acc), life(o.life), maxLife(o.maxLife), scale(o.scale), texNo(o.texNo),
          i70(o.i70), spin(o.spin), angle(o.angle), size0(o.size0), size1(o.size1), size2(o.size2),
          size3(o.size3), f8c(o.f8c), f90(o.f90), c94(o.c94), c95(o.c95), c96(o.c96), c97(o.c97), c98(o.c98) {}
};

struct Texture;
struct Particle;
extern "C" Particle *FUN_0006b16c(Particle *p, const Texture *const &tex, const ParticleParam &prm);
extern "C" const Texture *FUN_0006b76c(int texNo);

struct Particle {
    const Texture *tex;
    char pad4[0xb0 - 4];
    Particle(const Texture *tex, const ParticleParam &prm) { Init(tex, prm); }
    void Init(const Texture *t, const ParticleParam &prm) { Init2(t, prm); }
    void Init2(const Texture *const &t, const ParticleParam &prm) { Init3(t, prm); }
    void Init3(const Texture *const &t, ParticleParam prm) { FUN_0006b16c(this, t, prm); }
} __attribute__((aligned(16)));

struct ListNode { ListNode *prev; ListNode *next; };
struct ListIt {
    ListNode *n;
    ListIt(ListNode *p) : n(p) {}
    ListIt(const ListIt &o) : n(o.n) {}
};
struct ParticleList {
    int size;
    ListNode head;
    ListIt begin() { return ListIt(head.next); }
    ListIt end() { return ListIt(&head); }
};
struct ParticleLess {};

extern "C" {
ListIt FUN_0006c298(ListIt first, ListIt last, const Particle &v, ParticleLess c);  /* lower_bound */
ListIt FUN_0006c96c(ParticleList *l, ListIt pos, const Particle &v);               /* insert */
ListIt FUN_0006c8fc(ParticleList *l, ListIt pos);                                  /* erase */
int FUN_0006b7c0(void *body, float dt);                                            /* particle update */
}
inline ListIt Insert(ParticleList *l, ListIt pos, const Particle &v) { return FUN_0006c96c(l, pos, v); }

struct ParticleEmitter;
extern "C" {
void FUN_00068850(ParticleEmitter *, float);   /* base update */
void FUN_000688a8(ParticleEmitter *);          /* finish */
}

struct ParticleEmitter {
    void *vtbl;
    char pad4[0x14 - 0x4];
    EffectModel *model;
    int typeNo;
    float scale;
    char pad20[0x24 - 0x20];
    bool hold;
    char pad25[0x28 - 0x25];
    ParticleList particles;
};

extern "C" void FUN_0006a894(ParticleEmitter *self, float dt)
{
    FUN_00068850(self, dt);
    if (self->model == 0)
        return;
    {
        EffectModel *o = self->model;
        FUN_00059ba8(o, dt, -1);
        o->speed = dt;
    }
    {
        EffectModel *o = self->model;
        FUN_00059d68(o, -1);
        o->speed2 = o->speed;
    }
    {
        EffectModel *o = self->model;
        FUN_00059e58(o);
        FUN_0005fec8(o);
    }
    EmitterData &data = DAT_003daf68->Get(self->typeNo);
    float t = self->model->tracks[0].frame;
    if (!self->model->IsEnd()) {
        for (int i = 0; i < data.entries.size(); i++) {
            EmitEntry &e = data.entries[i];
            int n = e.period > 1 ? e.period : 1;
            float ph = FUN_0000c9dc(t + (float)(i % n), (float)n);
            if (0.0f <= ph && ph < dt) {
                Mat4 m = FUN_00055d60(self->model, e.joint);
                if (!(FUN_00022500(&m.r2, &m.r2) < 0.0001f * 0.0001f)) {
                    m.r1 = -m.r1;
                    FUN_00022540(&m.r2, &m.r2);
                    m.r2.w = 0.0f;
                    FUN_00022520(&m.r0, &m.r1, &m.r2);
                    FUN_00022540(&m.r0, &m.r0);
                    m.r0.w = 0.0f;
                    FUN_00022520(&m.r1, &m.r2, &m.r0);
                    m.SetTranslation(m.r3);
                    ParticleParam prm;
                    prm.mtx = m;
                    float life = (float)e.life;
                    prm.life = life;
                    prm.maxLife = life;
                    float speed;
                    if ((float)e.speed2 == 0.0f)
                        speed = (float)e.speed * 0.01f / prm.life;
                    else
                        speed = (float)e.speed2 * 0.01f;
                    prm.vel = m.r2 * speed;
                    prm.acc = (-DAT_002cc270 * (float)e.gravity) * 0.001f;
                    prm.scale = self->scale;
                    prm.texNo = e.texNo;
                    prm.i70 = e.i20;
                    float spin;
                    if (e.spin == 0) {
                        spin = 0.0f;
                    } else {
                        DAT_003daf60 = DAT_003daf60 * 0x343fd + 0x269ec3;
                        spin = (float)((DAT_003daf60 >> 16) & 0x7fff) * (1.0f / 32768.0f) * 3.1415927f;
                    }
                    prm.spin = spin;
                    prm.angle = spin + (float)e.spin * 0.017453292f;
                    prm.size0 = (float)e.size0 * 0.01f * self->scale;
                    prm.size1 = (float)e.size1 * 0.01f * self->scale;
                    prm.size2 = (float)e.size2 * 0.01f * self->scale;
                    prm.size3 = (float)e.size3 * 0.01f * self->scale;
                    prm.c94 = e.c0a;
                    prm.c95 = e.c12;
                    prm.c96 = e.c18;
                    prm.c97 = e.c1e;
                    prm.f8c = (float)e.s26 * 0.01f;
                    prm.c98 = e.c04;
                    Particle p(FUN_0006b76c(prm.texNo), prm);
                    ListIt pos = FUN_0006c298(self->particles.begin(), self->particles.end(), p, ParticleLess());
                    Insert(&self->particles, pos, p);
                }
            }
        }
    }
    if (self->model->IsEnd()) {
        if (data.loop && !self->hold) {
            EffectModel *o = self->model;
            FUN_00059c1c(o, 0.0f, -1);
            FUN_0005ff00(o, 0.0f);
        } else if (self->particles.size == 0) {
            FUN_000688a8(self);
        }
    }
    ListIt it = self->particles.begin();
    ListNode *end = &self->particles.head;
    while (it.n != end) {
        if (FUN_0006b7c0((char *)it.n + 32, dt))
            it = FUN_0006c8fc(&self->particles, it);
        else
            it.n = it.n->next;
    }
}
