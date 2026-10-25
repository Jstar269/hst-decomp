/* HSTMATCH module=EBOOT.BIN start=0x00247810 end=0x00247a7c symbol=FUN_00247810 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern Mgr *DAT_003386b0;
extern void *DAT_00340284;
extern char DAT_0034179c[];
extern char DAT_002fb264[];
extern float DAT_002faf14[];
extern float DAT_002faeb8[];

extern "C" {
void FUN_00022498(float s, Vec4 *out, const Vec4 *in);
double FUN_0000b16c(double);
void FUN_001b28f0(char *a, char *b);
void FUN_0013076c(void *g, void *a, int state, void *b, int f);
}

inline Vec4 Mul(float s, const Vec4 &d)
{
    Vec4 r;
    FUN_00022498(s, &r, &d);
    return r;
}

extern "C" void FUN_00247810(Self *self, Vec4 dir)
{
switch (self->state) {
    default:
        if ((self->state == 0x71 || self->state == 0x72 || self->state == 0x73 || self->state == 0x66)) {
 if (self->started == 0) {
            self->started = 1;
            self->time = DAT_003386b0->clock->now;
            self->SetMode(3);
            self->SetMode(1);
            if (self->state == 0x66)
                FUN_001b28f0(DAT_0034179c, DAT_002fb264);
            FUN_0013076c(DAT_00340284, self->f40, self->state, self->f290, 0);
            break;
        }}
        self->SetMode(3);
        self->time = DAT_003386b0->clock->now;
        break;
    case 0x97:
    case 0x96:
        self->SetMode(2);
        self->time = DAT_003386b0->clock->now;
        self->vel = Mul(DAT_002faf14[self->kind], dir);
        {float a = (float)FUN_0000b16c((double)DAT_002faeb8[self->kind]);
        float b = (float)FUN_0000b16c((double)self->vel.y);
        if (a > b)
            self->vel.y = DAT_002faeb8[self->kind];
        else
            self->vel.y = -self->vel.y;}
        break;
    }
}
