/* HSTMATCH module=EBOOT.BIN start=0x002525dc end=0x002528ac symbol=FUN_002525dc lang=c++ */
struct Rect;
struct Sub {
    char pad[0x60];
    float f60;
    float f64;
    char pad1[0x78 - 0x68];
    float f78;
};
struct Hook {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};
struct Self {
    char pad0[0x8c];
    Sub *f8c;
    Sub *f90;
    char pad1[0x1c0 - 0x94];
    Rect *rect0;
    Rect *rects[4];
    char pad2[0x1d8 - 0x1d4];
    Hook *f1d8;
    void *tex[17];
    char pad5[0x2f8 - 0x220];
    int kind;
    char pad6[0x34c - 0x2fc];
    float f34c;
    char pad7[0x35c - 0x350];
    int f35c;
    int f360;
};
extern int DAT_0034a780;
extern int DAT_0034a784;
extern unsigned char DAT_002fbef8;
extern unsigned char DAT_002fbef9;
extern unsigned char DAT_002fbefa;
extern "C" {
void FUN_000edec0(float, float, float, float, float, void *, Rect *, int, int);
float FUN_000ede98(float, float, float, float);
void FUN_001031e8(Self *);
}

static inline bool K(Self *s)
{
    return s->kind == 4 || s->kind == 6;
}
static inline bool Eq(Self *s)
{
    bool e = false;
    if (K(s)) {
        e = s->f35c == s->f360;
    }
    return e;
}
static inline bool Wide(Self *s)
{
    return K(s) && !Eq(s);
}

extern "C" void FUN_002525dc(Self *self)
{
    int idx[2] = {0, 0};
    idx[0] = DAT_0034a780;
    idx[1] = DAT_0034a784;
    if (DAT_002fbef9 != 0) {
        idx[0] = 15;
    }
    if (DAT_002fbefa != 0) {
        idx[1] = 15;
    }
    FUN_000edec0(0.0f, 0.0f, 1.0f, 1.0f, 1.0f, self->tex[16], self->rects[3], 0, 0);
    if (DAT_002fbef8 != 0) {
        Sub *s = self->f8c;
        if (s->f78 > 0.0f) {
            void *t = self->tex[idx[0]];
            FUN_000edec0(s->f60, s->f64, 1.0625f, 1.0f, 1.0f, t, self->rect0, 0, 0);
        }
    } else {
        if (self->f90->f78 > 0.0f) {
            bool b = true;
            if (self->kind != 4 && self->kind != 6) {
                b = false;
            }
            if (b) {
                self->f34c = FUN_000ede98(self->f34c, 0.0f, 0.5f, 0.1f);
            } else {
                self->f34c = FUN_000ede98(self->f34c, 101.0f, 0.5f, 0.1f);
            }
            int i;
            for (i = 0; i < (Wide(self) ? 2 : 1); i++) {
                float add;
                if (i == 0) {
                    add = self->f34c;
                } else {
                    add = 0.0f;
                }
                void *t = self->tex[idx[i]];
                FUN_000edec0(self->f90->f60 + add, self->f90->f64, 1.0625f, 1.0f, 1.0f, t, self->rects[i], 0, 0);
            }
        }
    }
    FUN_001031e8(self);
    if (self->f1d8 != 0) {
        self->f1d8->m3();
    }
}
// NEAR 34 words (of 180). Everything is exact except register choice and load order in the two FUN_000edec0 draw arms:
//  - retail loads idx[i] first (lw v1,0(s0)) then the Sub pointer into a1 (loop body) / a2 (DAT_002fbef8 arm, loaded before the c.ngt test); ours loads the pointer first into v1 and idx into v0.
//  - the 1.0f constant is lui v0 in retail, lui v1 in ours; a2/a3 zero moves and mov.s $f16 sit one slot later in retail.
// Tried, no change: hoisting `void *t = self->tex[idx[i]]` (copy-propagated away), a local Sub *p, an `int k = idx[i]`, an inline Draw1(Sub*,void*,Rect*) helper in all 6 parameter orders, v1..v4 variants of the DAT arm
//  (repeated self->f8c->, x/y float temps, early Rect *r), and all 126 interleavings of the float slots in the FUN_000edec0 prototype (the declared order 5 floats then void*,Rect*,int,int is best).
// Learned (fixed the loop and the Wide() tail, 83 -> 34): a `for (i = 0; i < (Wide(self) ? 2 : 1); i++)` with the bound re-evaluated every pass gives retail's `b cond` entry and bottom test;
//  `self->rects[i]` (array starting at +0x1c4, rect0 is a separate field at +0x1c0) gives s1 = self with disp 452; Wide must be `static inline bool K(s){return kind==4||kind==6;}`, `Eq(s){bool e=false; if (K(s)) e = f35c==f360; return e;}`,
//  `Wide(s){ return K(s) && !Eq(s); }` (an if/return form or `bool b = K(s); if (b)` form turns the outer K into li/beq branches instead of retail's xori/sltiu value form).
// near miss from lane sn6 (unreviewed)
