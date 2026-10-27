/* HSTMATCH module=hstp_trans_main.prx start=0x00257a18 end=0x00257c84 symbol=FUN_00257a18 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/court_state_enter_00247810.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Self {
    char pad0[0x3c];
    int mode;
    char f40[0x250];
    char f290[0x1c4];
    int state;
    int kind;
    int time;
    int pad460;
    unsigned char dirty;
    char pad465[0xb];
    Vec4 vel;
    char pad480[0x60];
    int started;

    void SetMode(int m)
    {
        if (mode != m) {
            mode = m;
            dirty = 1;
        }
    }
};

struct Clock {
    char pad[0x58];
    int now;
};
struct Mgr {
    char pad[0x9c];
    Clock *clock;
};

extern Mgr *DAT_003e19f0;
extern void *DAT_003e95c4;
extern char DAT_003eaad8[];
extern char DAT_003a3c3c[];
extern float DAT_003a38ec[];
extern float DAT_003a3890[];

extern "C" {
void FUN_000224c0(float s, Vec4 *out, const Vec4 *in);
double FUN_0000b184(double);
void FUN_001c0984(char *a, char *b);
void FUN_0013bd24(void *g, void *a, int state, void *b, int f);
}

inline Vec4 Mul(float s, const Vec4 &d)
{
    Vec4 r;
    FUN_000224c0(s, &r, &d);
    return r;
}

extern "C" void FUN_00257a18(Self *self, Vec4 dir)
{
switch (self->state) {
    default:
        if ((self->state == 0x71 || self->state == 0x72 || self->state == 0x73 || self->state == 0x66)) {
 if (self->started == 0) {
            self->started = 1;
            self->time = DAT_003e19f0->clock->now;
            self->SetMode(3);
            self->SetMode(1);
            if (self->state == 0x66)
                FUN_001c0984(DAT_003eaad8, DAT_003a3c3c);
            FUN_0013bd24(DAT_003e95c4, self->f40, self->state, self->f290, 0);
            break;
        }}
        self->SetMode(3);
        self->time = DAT_003e19f0->clock->now;
        break;
    case 0x97:
    case 0x96:
        self->SetMode(2);
        self->time = DAT_003e19f0->clock->now;
        self->vel = Mul(DAT_003a38ec[self->kind], dir);
        {float a = (float)FUN_0000b184((double)DAT_003a3890[self->kind]);
        float b = (float)FUN_0000b184((double)self->vel.y);
        if (a > b)
            self->vel.y = DAT_003a3890[self->kind];
        else
            self->vel.y = -self->vel.y;}
        break;
    }
}
