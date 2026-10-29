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

struct Ctl {
    virtual ~Ctl();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Reset();
    char pad04[0xe0 - 0x04];
    float level;          /* 0xe0 */
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

/* Start a shot's effects: reset the control and lamp objects, set the sound parameters from BallDistSq(), and play the sound effects. */
extern "C" void FUN_000d13e4(Shot *self, int player_index, int type, int sfx, int side, Vec4 from, Vec4 to, int play)
{
    float ratio = (float)DAT_003386b0->players[player_index]->power / DAT_00341314;
    float dist;  /* BallDistSq(), tested against 225.0f */

    if (self->m40) { delete self->m40; self->m40 = 0; }
    if (self->m44) { delete self->m44; self->m44 = 0; }

    FUN_000513a0(self->handles->h0, 0);
    FUN_00051398(self->handles->h0, 4000.0f);
    FUN_000513a0(self->handles->h1, 1);
    FUN_00051398(self->handles->h1, 4000.0f);

    self->type = type;
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
                float level;
                if (r <= 0.0f)
                    level = 0.0f;
                else
                    level = 96.0f - 874.0f / r;
                if (level < 0.0f) level = 0.0f;
                self->ctl->level = level;
            }
            {
                float limited = Min(dist, DAT_002d6658);
                short extent = (short)(limited * 0.25f);
                self->params.b = extent;
                self->params.a = extent;
            }
            self->params.gain *= 1.5f;
            if (DAT_003386b0->players[player_index]->flag == 0)
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
                int color_index = 0;
                Vec4 color;
                if (side == 0) color_index = 2;
                if (side == 1) color_index = 1;
                if (side == 2) color_index = 0;
                color.x = DAT_002c0440[color_index].x;
                color.y = DAT_002c0440[color_index].y;
                color.z = DAT_002c0440[color_index].z;
                color.w = DAT_002c0440[color_index].w;
                color.w = color.w * 0.75f;
                self->lamp->SetColor(&color);
            }
            if (self->m188) { delete self->m188; self->m188 = 0; }
            self->m1c0 = 0;
            DAT_00338b04 = 0;
            if ((FUN_00130654(DAT_00340284) && (type == 5 || type == 4)) ||
                (FUN_00130654(DAT_00340284) && DAT_003386b0->rally->HasRoom() &&
                 BallDistSq() >= 376.36f)) {
                Effect *effect;
                FUN_00057b58(self->effect, 0.0f, 0, 0);
                effect = self->effect;
                FUN_00058ec4(effect, 1.0f, -1);
                effect->speed = 1.0f;
                FUN_00059084(self->effect, -1);
                effect = self->effect;
                FUN_00058f38(effect, 0.0f, -1);
                FUN_0005f110(effect, 0.0f);
                self->m198 = 1;
            }
        } else {
            self->ctl->Reset();
            FUN_000e7198(self->ctl, 1);
            FUN_000e6fc4(self->ctl, self->m130);
            {
                float r = FUN_00022e44(BallDistSq());
                float level;
                if (r <= 0.0f)
                    level = 0.0f;
                else
                    level = 96.0f - 874.0f / r;
                if (level < 0.0f) level = 0.0f;
                self->ctl->level = level;
            }
            {
                float limited = Min(dist, DAT_002d665c);
                short extent = (short)(limited * 0.25f);
                self->params.b = extent;
                self->params.a = extent;
            }
            self->params.gain *= 1.5f;
            if (DAT_003386b0->players[player_index]->flag == 0)
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
                int color_index = 0;
                Vec4 color;
                if (side == 0) color_index = 2;
                if (side == 1) color_index = 1;
                if (side == 2) color_index = 0;
                color.x = DAT_002c0440[color_index].x;
                color.y = DAT_002c0440[color_index].y;
                color.z = DAT_002c0440[color_index].z;
                color.w = DAT_002c0440[color_index].w;
                color.w = color.w * 0.75f;
                self->lamp->SetColor(&color);
            }
            if (self->m188) { delete self->m188; self->m188 = 0; }
        }
    }
    if (play) {
        Sfx64 fx = DAT_002bc410;
        fx.pos = from;
        FUN_000ce754(DAT_003386b0->hud->id, &fx, sfx, 3500.0f, 1.0f, 1, 0.0f);
    }
    if (sfx == 14) {
        Sfx64 fx = DAT_002bc410;
        fx.pos = from;
        FUN_000ce754(DAT_003386b0->hud->id, &fx, 1, 3500.0f, 1.0f, 1, 0.0f);
    }
}
