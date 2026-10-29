/* HSTMATCH module=EBOOT.BIN start=0x001d1c04 end=0x001d1e6c symbol=FUN_001d1c04 lang=c++ */
struct Rect {
    short pad0;
    short pad1;
    short x0;
    short y0;
    short x1;
    short y1;
};

struct Part {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual void fn3();
    virtual void fn4();
    virtual void fn5();
    virtual void fn6();
    virtual void fn7();
    virtual void fn8();
    virtual void fn9();
    virtual void fn10();
    char pad0[0xdc - 4];
    int count;
};

struct Self {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    char pad4[0x50];
    unsigned char f54;
    unsigned char f55;
    char pad56[2];
    Part *f58;
    int f5c;
    char pad60[0xc];
    Rect *rect[2];
    short cx[2];
    short cy[2];
    float scale[2];
};

extern int DAT_002cfc8c;
extern "C" {
void FUN_00103540(float);
void FUN_001037c8(Self *, int);
void FUN_0001dfe8(int, int);
void FUN_0001e23c(int, int, int);
void FUN_00103628(Self *, int);
void FUN_000ffca4(Rect *);
void FUN_001d1bf0(Part *);
int FUN_001d6240(Rect *);
void FUN_001d1f94(Rect *, int);
char *FUN_001d1f80(Self *, int);
void FUN_00103480(Self *);
}

extern "C" void FUN_001d1c04(Self *self)
{
    FUN_00103540(1010.0f);
    FUN_001037c8(self, -1);
    FUN_0001dfe8(DAT_002cfc8c, 0x2000);
    FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
    if (self->f58 != 0) {
        self->f58->fn10();
    }
    self->f54 = 1;
    self->f55 = 0;
    FUN_00103628(self, 0);
    self->fn2();
    int n = self->f58->count;
    int i = 0;
    do {
        FUN_000ffca4(self->rect[i]);
        float s = i == n ? 1.0f : 0.85f;
        self->scale[i] = s;
        Rect *r = self->rect[i];
        r->x0 = (short)(r->x0 * s);
        r->x1 = (short)(r->x1 * s);
        r->y0 = (short)(r->y0 * s);
        r->y1 = (short)(r->y1 * s);
        short ty = self->cy[i];
        Rect *q = self->rect[i];
        short d = q->x1 - q->x0;
        int half = d / 2;
        short ox = self->rect[i]->x0;
        q->x0 = self->cx[i] - half;
        q->x1 = q->x1 + (short)(q->x0 - ox);
        short dy = q->y1 - q->y0;
        int halfy = dy / 2;
        short ny = ty - halfy;
        short ddy = ny - q->y0;
        q->y0 = ny;
        q->y1 = q->y1 + ddy;
        i++;
    } while (i < 2);
    self->f5c = 0;
    FUN_001d1bf0(self->f58);
    int v = FUN_001d6240(self->rect[0]);
    FUN_001d1f94(self->rect[1], v);
    *(float *)(FUN_001d1f80(self, 0) + 0x60) = -480.0f;
    FUN_00103480(self);
}
// lane sx3 NEAR (153/154 words, 46 differ, all in the two re-centre statements): the second rect pointer is its own local `Rect *q = self->rect[i];` declared AFTER `short ty = self->cy[i];` (gives retail's v0 = rect, v1 = ty
// colouring and the x-part registers). Fixed vs the old wip: Self is polymorphic (`self->fn2()` = lw t9,16(t9)), Part slot 10 / Part::count at +0xdc, scale constants 1.0f / 0.85f (0x3f59999a), and
// `*(float *)(FUN_001d1f80(self, 0) + 0x60) = -480.0f;` as ONE statement (the constant is then evaluated first and kept in $f20 across the call, as retail; split into `float off`/`char *p` it is rematerialised).
// Left: retail loads x1 before x0 for the width (`lh a1,8; lh a0,4`), ours x0 first because the old-x0 read `self->rect[i]->x0` is CSE'd with it (extra `seh a0,a1`); retail reloads old x0 after the /2 branch.
// y part: retail stores y0 after the diff (`short ny = ty - halfy; short ddy = ny - q->y0; q->y0 = ny; ...`) and reloads old y0 (`lh v1,6(v0)`) after the branch; ours loads y0 once.
// improved by lane sx3 (unreviewed): 127 -> 46 differing words
