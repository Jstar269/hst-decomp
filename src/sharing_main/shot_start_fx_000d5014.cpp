/* HSTMATCH module=hstp_trans_main.prx start=0x000d5014 end=0x000d5b6c symbol=FUN_000d5014 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));

struct SoundParams {
    unsigned char kind;   /* 0x00 */
    short a;              /* 0x02 */
    float f04;
    float f08;
    float f0c;
    float gain;           /* 0x10 */
    float pitch;          /* 0x14 */
    short b;              /* 0x18 */
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    int i30;
    short s34;
    int i38;
};

struct Sfx64 { Vec4 a; Vec4 b; Vec4 c; Vec4 pos; };

struct Deletable { virtual ~Deletable(); };

struct Ctl {   /* +0xe0: float level */
    virtual ~Ctl();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Reset();
};

struct Lamp {
    virtual ~Lamp();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetColor(Vec4 *c);
};

struct Handles { int h0; int h1; int h2; int h3; };

struct CVec {
    float x, y, z, w;
    CVec() {}
    CVec(const CVec &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

struct Ball { char pad0[0x20]; CVec pos; char pad30[0x2f8 - 0x30]; float spin; };
struct Player { char pad0[0x41c]; int power; char pad420[0x4d8 - 0x420]; unsigned char flag; };
struct Hud { char pad0[0x44]; int id; };
struct Rally { char pad0[0x58]; int max; bool HasRoom(); };

struct Game {
    char pad0[0x3c];
    int mode;
    char pad40[0x70 - 0x40];
    Player *players[6];
    Ball *ball;
    char pad8c[4];
    Hud *hud;
    char pad94[0x9c - 0x94];
    Rally *rally;
};

struct Effect { char pad0[0xc4]; float speed; };

extern Game *DAT_003e19f0;
extern float DAT_003ea654;
extern const SoundParams DAT_002d06cc;
extern float DAT_0037d138;
extern float DAT_0037d13c;
extern Vec4 DAT_002d0670[];
extern unsigned char DAT_003e1e44;
extern int DAT_003e95c4;
extern Sfx64 DAT_002cc260;

extern "C" {
void FUN_00051d40(int, int);
void FUN_00051d38(int, float);
float FUN_00022500(const CVec *, const CVec *);
float FUN_00022e6c(float);
void FUN_000ec194(Ctl *, int);
void FUN_000ebfc0(Ctl *, void *);
int FUN_0013bc0c(int);
int FUN_00123394(Rally *);
void FUN_000587ac(Effect *, float, int, int);
void FUN_00059ba8(Effect *, float, int);
void FUN_00059d68(Effect *, int);
void FUN_00059c1c(Effect *, float, int);
void FUN_0005ff00(Effect *, float);
void FUN_000d2350(int, Sfx64 *, int, float, float, int, float);
}

inline bool Rally::HasRoom() { return max > FUN_00123394(this); }

static inline float BallDistSq()
{
    CVec p = DAT_003e19f0->ball->pos;
    return FUN_00022500(&p, &p);
}

static inline const float &Min(const float &a, const float &b) { return a < b ? a : b; }

struct Shot {
    virtual ~Shot();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Setup(Vec4 *from, Vec4 *to, int h, SoundParams *p);
    virtual void Link(int a, int b, int c);

    char pad04[0x40 - 0x04];
    Deletable *m40;
    Deletable *m44;
    Lamp *lamp;
    char pad4c[0x84 - 0x4c];
    SoundParams params;
    char padc0[0xc4 - 0xc0];
    int type;
    Handles *handles;
    char padcc[0x130 - 0xcc];
    char m130[0x180 - 0x130];
    Ctl *ctl;
    char pad184[0x188 - 0x184];
    Deletable *m188;
    char pad18c[0x194 - 0x18c];
    Effect *effect;
    unsigned char m198;
    char pad199[0x19c - 0x199];
    int m19c;
    float m1a0;
    int m1a4;
    char pad1a8[0x1c0 - 0x1a8];
    unsigned char m1c0;

};

extern "C" void FUN_000d5014(Shot *self, int idx, int type_, int sfx, int side, Vec4 from, Vec4 to, int play)
{
    float ratio = (float)DAT_003e19f0->players[idx]->power / DAT_003ea654;
    float dist;

    if (self->m40) { delete self->m40; self->m40 = 0; }
    if (self->m44) { delete self->m44; self->m44 = 0; }

    FUN_00051d40(self->handles->h0, 0);
    FUN_00051d38(self->handles->h0, 4000.0f);
    FUN_00051d40(self->handles->h1, 1);
    FUN_00051d38(self->handles->h1, 4000.0f);

    self->type = type_;
    self->params = DAT_002d06cc;

    self->m19c = 0;
    self->m1a0 = DAT_003e19f0->ball->spin;
    self->m1a4 = 0;

    dist = BallDistSq();
    if (dist >= 225.0f) {
        if (DAT_003e19f0->mode == 7) {
            self->ctl->Reset();
            FUN_000ec194(self->ctl, 1);
            FUN_000ebfc0(self->ctl, self->m130);
            {
                float r = FUN_00022e6c(BallDistSq());
                float f;
                if (r <= 0.0f)
                    f = 0.0f;
                else
                    f = 96.0f - 874.0f / r;
                if (f < 0.0f) f = 0.0f;
                *(float *)((char *)self->ctl + 0xe0) = f;
            }
            {
                float m = Min(dist, DAT_0037d138);
                short s = (short)(m * 0.25f);
                self->params.b = s;
                self->params.a = s;
            }
            self->params.gain *= 1.5f;
            if (DAT_003e19f0->players[idx]->flag == 0)
                self->params.pitch = 1.2f;
            else
                self->params.pitch = 2.4f;
            if (ratio < 1.0f) {
                self->Setup(&from, &to, self->handles->h0, &self->params);
            } else {
                self->Setup(&from, &to, self->handles->h0, &self->params);
                self->Link(self->handles->h2, self->handles->h3, 0);
            }
            {
                int i = 0;
                Vec4 c;
                if (side == 0) i = 2;
                if (side == 1) i = 1;
                if (side == 2) i = 0;
                c.x = DAT_002d0670[i].x;
                c.y = DAT_002d0670[i].y;
                c.z = DAT_002d0670[i].z;
                c.w = DAT_002d0670[i].w;
                c.w = c.w * 0.75f;
                self->lamp->SetColor(&c);
            }
            if (self->m188) { delete self->m188; self->m188 = 0; }
            self->m1c0 = 0;
            DAT_003e1e44 = 0;
            if ((FUN_0013bc0c(DAT_003e95c4) && (type_ == 5 || type_ == 4)) ||
                (FUN_0013bc0c(DAT_003e95c4) && DAT_003e19f0->rally->HasRoom() &&
                 BallDistSq() >= 376.36f)) {
                Effect *e;
                FUN_000587ac(self->effect, 0.0f, 0, 0);
                e = self->effect;
                FUN_00059ba8(e, 1.0f, -1);
                e->speed = 1.0f;
                FUN_00059d68(self->effect, -1);
                e = self->effect;
                FUN_00059c1c(e, 0.0f, -1);
                FUN_0005ff00(e, 0.0f);
                self->m198 = 1;
            }
        } else {
            self->ctl->Reset();
            FUN_000ec194(self->ctl, 1);
            FUN_000ebfc0(self->ctl, self->m130);
            {
                float r = FUN_00022e6c(BallDistSq());
                float f;
                if (r <= 0.0f)
                    f = 0.0f;
                else
                    f = 96.0f - 874.0f / r;
                if (f < 0.0f) f = 0.0f;
                *(float *)((char *)self->ctl + 0xe0) = f;
            }
            {
                float m = Min(dist, DAT_0037d13c);
                short s = (short)(m * 0.25f);
                self->params.b = s;
                self->params.a = s;
            }
            self->params.gain *= 1.5f;
            if (DAT_003e19f0->players[idx]->flag == 0)
                self->params.pitch = 1.2f;
            else
                self->params.pitch = 2.4f;
            if (ratio < 1.0f) {
                self->Setup(&from, &to, self->handles->h0, &self->params);
            } else {
                self->Setup(&from, &to, self->handles->h0, &self->params);
                self->Link(self->handles->h2, self->handles->h3, 0);
            }
            {
                int i = 0;
                Vec4 c;
                if (side == 0) i = 2;
                if (side == 1) i = 1;
                if (side == 2) i = 0;
                c.x = DAT_002d0670[i].x;
                c.y = DAT_002d0670[i].y;
                c.z = DAT_002d0670[i].z;
                c.w = DAT_002d0670[i].w;
                c.w = c.w * 0.75f;
                self->lamp->SetColor(&c);
            }
            if (self->m188) { delete self->m188; self->m188 = 0; }
        }
    }
    if (play) {
        Sfx64 s = DAT_002cc260;
        s.pos = from;
        FUN_000d2350(DAT_003e19f0->hud->id, &s, sfx, 3500.0f, 1.0f, 1, 0.0f);
    }
    if (sfx == 14) {
        Sfx64 s = DAT_002cc260;
        s.pos = from;
        FUN_000d2350(DAT_003e19f0->hud->id, &s, 1, 3500.0f, 1.0f, 1, 0.0f);
    }
}
