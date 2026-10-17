/* HSTMATCH module=EBOOT.BIN start=0x001d0624 end=0x001d08f0 symbol=FUN_001d0624 lang=c++ rodata=0x002c6510 */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: const Width() getter plus MoveX computing the delta from w->x before the store, so the two x loads are not CSE-d); names and types await human review. */
struct Widget {
    char pad0[4];
    short x;
    short pad6;
    short x2;
};
struct Inner {
    char pad[0x60];
    float f60;
};
struct Outer {
    Inner *inner;
};
struct Sub {
    char pad[0x1c0];
    int f1c0;
};
struct Panel {
    virtual void v0();
    virtual void SetVisible(int);
};
struct Self {
    char pad0[4];
    Outer *outer;
    char pad8[0x55 - 8];
    unsigned char flag55;
    char pad56[2];
    Panel *panel;
    int state;
    int f60;
    char pad64[0x6c - 0x64];
    Widget *w[2];
    char pad74[0x84 - 0x74];
    Sub *sub;
};

extern char DAT_0034179c;
extern int DAT_002cfc8c;
extern int DAT_0034a120;
extern int DAT_0034a664;
extern "C" void FUN_00103480(Self *);
extern "C" void FUN_000ffb3c(Widget *, int);
extern "C" void FUN_001b1c44(void *, int);
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_002a44f0(Sub *);
extern "C" void FUN_002a4558(Sub *);
extern "C" void FUN_002a45d8(Sub *);
extern "C" void FUN_002a23a8(Sub *);
extern "C" void FUN_002a1a64(Sub *, int);
extern "C" void FUN_001d9c64(int);
extern "C" void FUN_00232ec4(int);
extern "C" int FUN_0022c1dc();

static inline short Width(const Widget *w)
{
    return w->x2 - w->x;
}

static inline void MoveX(Widget *w, short x)
{
    short d = x - w->x;
    w->x = x;
    w->x2 = w->x2 + d;
}

extern "C" void FUN_001d0624(Self *self, int state)
{
    self->state = state;
    switch (state) {
    case 0: {
        self->panel->SetVisible(1);
        Widget *mid = self->w[0];
        Widget *mv = self->w[1];
        short center = (mid->x + mid->x2) / 2;
        int width = Width(mv);
        MoveX(mv, center - width / 2);
        self->outer->inner->f60 = -480.0f;
        FUN_00103480(self);
        return;
    }
    case 2:
        self->panel->SetVisible(0);
        self->flag55 = 0;
        for (unsigned i = 0; i < 2; i++) {
            FUN_000ffb3c(self->w[i], 0);
        }
        self->panel->SetVisible(0);
        self->outer->inner->f60 = 0.0f;
        FUN_00103480(self);
        break;
    case 3:
        FUN_001b1c44(&DAT_0034179c, 3);
        FUN_0001dfe8(DAT_002cfc8c, 0x2000);
        FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
        FUN_002a44f0(self->sub);
        break;
    case 5:
        FUN_0001dfe8(DAT_002cfc8c, 0x2000);
        FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
        FUN_002a4558(self->sub);
        break;
    case 4:
        FUN_001b1c44(&DAT_0034179c, 3);
    case 6:
        self->flag55 = 1;
        self->f60 = 0;
        FUN_001d9c64(DAT_0034a120);
        if (self->sub->f1c0 != 1) {
            FUN_002a1a64(self->sub, 0x18);
        }
        if (self->state == 6) {
            self->panel->SetVisible(1);
            for (unsigned i = 0; i < 2; i++) {
                FUN_000ffb3c(self->w[i], i != 0);
            }
        }
        break;
    case 7:
        FUN_0001dfe8(DAT_002cfc8c, 0x2000);
        FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
        self->flag55 = 1;
        FUN_00232ec4(DAT_0034a664);
        if (FUN_0022c1dc() == 0) {
            FUN_002a45d8(self->sub);
        }
        break;
    case 8:
        FUN_002a23a8(self->sub);
        break;
    }
}
