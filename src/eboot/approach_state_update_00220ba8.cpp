/* HSTMATCH module=EBOOT.BIN start=0x00220ba8 end=0x00220ed8 symbol=FUN_00220ba8 lang=c++ */
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
extern float DAT_002f0bbc;
extern float DAT_002f0bc0;
extern float DAT_0034a230;
extern Vec DAT_0034a210[];
float FUN_000ede98(float v, float target, float rate, float eps);
void FUN_00103480(Obj *o);
void FUN_00103128(Obj *o);
}

extern "C" void FUN_00220ba8(Obj *self)
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
                a = FUN_000ede98(a, 0.0f, DAT_002f0bbc, 1.0f);
                b = FUN_000ede98(b, 0.0f, DAT_002f0bbc, 1.0f);
                c = FUN_000ede98(c, 1.0f, DAT_002f0bbc, 0.01f);
                d = FUN_000ede98(d, 1.0f, DAT_002f0bbc, 0.01f);
                break;
            }
        } else {
            switch (self->mode) {
            case 0:
                a = FUN_000ede98(a, DAT_0034a210[self->mode].x, DAT_002f0bbc * 0.5f, 1.0f);
                b = FUN_000ede98(b, DAT_0034a210[self->mode].y, DAT_002f0bbc * 0.5f, 1.0f);
                d = FUN_000ede98(d, DAT_002f0bc0, 0.1f, 0.01f);
                break;
            case 1:
                c = FUN_000ede98(c, DAT_0034a230, DAT_002f0bbc, 0.01f);
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
        FUN_00103480(self);
        self->count = self->count + 1;
    }
    FUN_00103128(self);
}
