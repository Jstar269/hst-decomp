/* HSTMATCH module=hstp_trans_main.prx start=0x0023011c end=0x0023044c symbol=FUN_0023011c lang=c++ */
/* Clone of src/eboot/approach_state_update_00220ba8.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: both mode tests are switches (a combined case 0/1 group, then case 0 before case 1 in the 100+ branch, because MWCC emits the compare chain in reverse source order), the five stores through self->sub come BEFORE the two float scalings (e = d*64, g = c*128) so the scheduler keeps the retail interleave; names and types await human review. */
struct Vec { float x, y, z, w; };

struct Sub {
    char pad0[0x60];
    float f60;
    float f64;
    char pad68[4];
    float f6c;
    char pad70[8];
    float f78;
};

struct Quad {
    unsigned int color;
    short s4;
    short s6;
    short s8;
    short s10;
};

struct Obj {
    char pad0[0x60];
    int mode;
    int count;
    float f68;
    Sub *sub;
    Quad *q1;
    Quad *q2;
};

extern "C" {
extern float DAT_00398f88;
extern float DAT_00398f8c;
extern float DAT_003f3560;
extern Vec DAT_003f3540[];
float FUN_000f3560(float v, float target, float rate, float eps);
void FUN_00108dac(Obj *o);
void FUN_00108a2c(Obj *o);
}

extern "C" void FUN_0023011c(Obj *self)
{
    if (self->count >= 0) {
        Sub *o = self->sub;
        float a = o->f60;
        float b = o->f64;
        float c = o->f78;
        float d = self->f68;
        if (self->count < 100) {
            switch (self->mode) {
            case 0:
            case 1:
                a = FUN_000f3560(a, 0.0f, DAT_00398f88, 1.0f);
                b = FUN_000f3560(b, 0.0f, DAT_00398f88, 1.0f);
                c = FUN_000f3560(c, 1.0f, DAT_00398f88, 0.01f);
                d = FUN_000f3560(d, 1.0f, DAT_00398f88, 0.01f);
                break;
            }
        } else {
            switch (self->mode) {
            case 0:
                a = FUN_000f3560(a, DAT_003f3540[self->mode].x, DAT_00398f88 * 0.5f, 1.0f);
                b = FUN_000f3560(b, DAT_003f3540[self->mode].y, DAT_00398f88 * 0.5f, 1.0f);
                d = FUN_000f3560(d, DAT_00398f8c, 0.1f, 0.01f);
                break;
            case 1:
                c = FUN_000f3560(c, DAT_003f3560, DAT_00398f88, 0.01f);
                break;
            }
        }
        self->sub->f60 = a;
        self->sub->f64 = b;
        self->sub->f6c = 1.0f;
        self->sub->f78 = c;
        self->f68 = d;
        float e = d * 64.0f;
        float g = c * 128.0f;
        self->q1->s8 = (short)(int)((float)self->q1->s4 + e);
        self->q1->s10 = (short)(int)((float)self->q1->s6 + e);
        self->q2->s8 = (short)(int)((float)self->q2->s4 + e);
        self->q2->s10 = (short)(int)((float)self->q2->s6 + e);
        unsigned int alpha = (unsigned char)(unsigned int)g;
        self->q1->color = (self->q1->color & 0xffffff) | (alpha << 24);
        FUN_00108dac(self);
        self->count = self->count + 1;
    }
    FUN_00108a2c(self);
}
