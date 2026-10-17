/* HSTMATCH module=EBOOT.BIN start=0x000d13e4 end=0x000d1f3c symbol=FUN_000d13e4 lang=c++ */
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

extern Game *DAT_003386b0;
extern float DAT_00341314;
extern const SoundParams DAT_002c049c;
extern float DAT_002d6658;
extern float DAT_002d665c;
extern Vec4 DAT_002c0440[];
extern unsigned char DAT_00338b04;
extern int DAT_00340284;
extern Sfx64 DAT_002bc410;

extern "C" {
void FUN_000513a0(int, int);
void FUN_00051398(int, float);
float FUN_000224d8(const CVec *, const CVec *);
float FUN_00022e44(float);
void FUN_000e7198(Ctl *, int);
void FUN_000e6fc4(Ctl *, void *);
int FUN_00130654(int);
int FUN_001181c0(Rally *);
void FUN_00057b58(Effect *, float, int, int);
void FUN_00058ec4(Effect *, float, int);
void FUN_00059084(Effect *, int);
void FUN_00058f38(Effect *, float, int);
void FUN_0005f110(Effect *, float);
void FUN_000ce754(int, Sfx64 *, int, float, float, int, float);
}

inline bool Rally::HasRoom() { return max > FUN_001181c0(this); }

static inline float BallDistSq()
{
    CVec p = DAT_003386b0->ball->pos;
    return FUN_000224d8(&p, &p);
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

extern "C" void FUN_000d13e4(Shot *self, int idx, int type_, int sfx, int side, Vec4 from, Vec4 to, int play)
{
    float ratio = (float)DAT_003386b0->players[idx]->power / DAT_00341314;
    float dist;

    if (self->m40) { delete self->m40; self->m40 = 0; }
    if (self->m44) { delete self->m44; self->m44 = 0; }

    FUN_000513a0(self->handles->h0, 0);
    FUN_00051398(self->handles->h0, 4000.0f);
    FUN_000513a0(self->handles->h1, 1);
    FUN_00051398(self->handles->h1, 4000.0f);

    self->type = type_;
    self->params = DAT_002c049c;

    self->m19c = 0;
    self->m1a0 = DAT_003386b0->ball->spin;
    self->m1a4 = 0;

    dist = BallDistSq();
    if (dist >= 225.0f) {
        if (DAT_003386b0->mode == 7) {
            self->ctl->Reset();
            FUN_000e7198(self->ctl, 1);
            FUN_000e6fc4(self->ctl, self->m130);
            {
                float r = FUN_00022e44(BallDistSq());
                float f;
                if (r <= 0.0f)
                    f = 0.0f;
                else
                    f = 96.0f - 874.0f / r;
                if (f < 0.0f) f = 0.0f;
                *(float *)((char *)self->ctl + 0xe0) = f;
            }
            {
                float m = Min(dist, DAT_002d6658);
                short s = (short)(m * 0.25f);
                self->params.b = s;
                self->params.a = s;
            }
            self->params.gain *= 1.5f;
            if (DAT_003386b0->players[idx]->flag == 0)
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
                c.x = DAT_002c0440[i].x;
                c.y = DAT_002c0440[i].y;
                c.z = DAT_002c0440[i].z;
                c.w = DAT_002c0440[i].w;
                c.w = c.w * 0.75f;
                self->lamp->SetColor(&c);
            }
            if (self->m188) { delete self->m188; self->m188 = 0; }
            self->m1c0 = 0;
            DAT_00338b04 = 0;
            if ((FUN_00130654(DAT_00340284) && (type_ == 5 || type_ == 4)) ||
                (FUN_00130654(DAT_00340284) && DAT_003386b0->rally->HasRoom() &&
                 BallDistSq() >= 376.36f)) {
                Effect *e;
                FUN_00057b58(self->effect, 0.0f, 0, 0);
                e = self->effect;
                FUN_00058ec4(e, 1.0f, -1);
                e->speed = 1.0f;
                FUN_00059084(self->effect, -1);
                e = self->effect;
                FUN_00058f38(e, 0.0f, -1);
                FUN_0005f110(e, 0.0f);
                self->m198 = 1;
            }
        } else {
            self->ctl->Reset();
            FUN_000e7198(self->ctl, 1);
            FUN_000e6fc4(self->ctl, self->m130);
            {
                float r = FUN_00022e44(BallDistSq());
                float f;
                if (r <= 0.0f)
                    f = 0.0f;
                else
                    f = 96.0f - 874.0f / r;
                if (f < 0.0f) f = 0.0f;
                *(float *)((char *)self->ctl + 0xe0) = f;
            }
            {
                float m = Min(dist, DAT_002d665c);
                short s = (short)(m * 0.25f);
                self->params.b = s;
                self->params.a = s;
            }
            self->params.gain *= 1.5f;
            if (DAT_003386b0->players[idx]->flag == 0)
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
                c.x = DAT_002c0440[i].x;
                c.y = DAT_002c0440[i].y;
                c.z = DAT_002c0440[i].z;
                c.w = DAT_002c0440[i].w;
                c.w = c.w * 0.75f;
                self->lamp->SetColor(&c);
            }
            if (self->m188) { delete self->m188; self->m188 = 0; }
        }
    }
    if (play) {
        Sfx64 s = DAT_002bc410;
        s.pos = from;
        FUN_000ce754(DAT_003386b0->hud->id, &s, sfx, 3500.0f, 1.0f, 1, 0.0f);
    }
    if (sfx == 14) {
        Sfx64 s = DAT_002bc410;
        s.pos = from;
        FUN_000ce754(DAT_003386b0->hud->id, &s, 1, 3500.0f, 1.0f, 1, 0.0f);
    }
}
