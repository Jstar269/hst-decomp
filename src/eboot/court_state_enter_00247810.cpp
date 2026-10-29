/* HSTMATCH module=EBOOT.BIN start=0x00247810 end=0x00247a7c symbol=FUN_00247810 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/posed_obj.h"

typedef ObjVec4 Vec4;

inline void SetMode(PosedObj *self, int m)
{
    if (self->mode != m) {
        self->mode = m;
        self->dirty = 1;
    }
}

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

/* Enter a state: 0x66 and 0x71-0x73 start once (mode 1, record the time, call the start hook); other states set mode 3; 0x96 and 0x97 set mode 2, scale the direction by a per-kind factor, then set the vertical component to the per-kind value when its magnitude is below that value, else negate it. */
extern "C" void FUN_00247810(PosedObj *self, Vec4 dir)
{
switch (self->state) {
    default:
        if ((self->state == 0x71 || self->state == 0x72 || self->state == 0x73 || self->state == 0x66)) {
 if (self->started == 0) {
            self->started = 1;
            self->time = DAT_003386b0->clock->now;
            SetMode(self, 3);
            SetMode(self, 1);
            if (self->state == 0x66)
                FUN_001b28f0(DAT_0034179c, DAT_002fb264);
            FUN_0013076c(DAT_00340284, self->pos, self->state, self->sub_290, 0);
            break;
        }}
        SetMode(self, 3);
        self->time = DAT_003386b0->clock->now;
        break;
    case 0x97:
    case 0x96:
        SetMode(self, 2);
        self->time = DAT_003386b0->clock->now;
        self->vel = Mul(DAT_002faf14[self->kind], dir);
        {float limit = (float)FUN_0000b16c((double)DAT_002faeb8[self->kind]);
        float speed = (float)FUN_0000b16c((double)self->vel.y);
        if (limit > speed)
            self->vel.y = DAT_002faeb8[self->kind];
        else
            self->vel.y = -self->vel.y;}
        break;
    }
}
