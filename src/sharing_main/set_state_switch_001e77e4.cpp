/* HSTMATCH module=hstp_trans_main.prx start=0x001e77e4 end=0x001e7ab0 symbol=FUN_001e77e4 lang=c++ rodata=0x002d6f9c */
/* Clone of src/eboot/set_state_switch_001d0624.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
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

extern char DAT_003eaad8;
extern int DAT_003751d4;
extern int DAT_003f3458;
extern int DAT_003f3994;
extern "C" void FUN_00108dac(Self *);
extern "C" void FUN_00105470(Widget *, int);
extern "C" void FUN_001bfc3c(void *, int);
extern "C" void FUN_0001dc34(int, int);
extern "C" void FUN_0001de88(int, int, int);
extern "C" void FUN_002b3c08(Sub *);
extern "C" void FUN_002b3c70(Sub *);
extern "C" void FUN_002b3d2c(Sub *);
extern "C" void FUN_002b1740(Sub *);
extern "C" void FUN_002b0e70(Sub *, int);
extern "C" void FUN_001e7d1c(int);
extern "C" void FUN_00242fc4(int);
extern "C" int FUN_0023bc90();

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

extern "C" void FUN_001e77e4(Self *self, int state)
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
        FUN_00108dac(self);
        return;
    }
    case 2:
        self->panel->SetVisible(0);
        self->flag55 = 0;
        for (unsigned i = 0; i < 2; i++) {
            FUN_00105470(self->w[i], 0);
        }
        self->panel->SetVisible(0);
        self->outer->inner->f60 = 0.0f;
        FUN_00108dac(self);
        break;
    case 3:
        FUN_001bfc3c(&DAT_003eaad8, 3);
        FUN_0001dc34(DAT_003751d4, 0x2000);
        FUN_0001de88(DAT_003751d4, 0x2000, 1);
        FUN_002b3c08(self->sub);
        break;
    case 5:
        FUN_0001dc34(DAT_003751d4, 0x2000);
        FUN_0001de88(DAT_003751d4, 0x2000, 1);
        FUN_002b3c70(self->sub);
        break;
    case 4:
        FUN_001bfc3c(&DAT_003eaad8, 3);
    case 6:
        self->flag55 = 1;
        self->f60 = 0;
        FUN_001e7d1c(DAT_003f3458);
        if (self->sub->f1c0 != 1) {
            FUN_002b0e70(self->sub, 0x18);
        }
        if (self->state == 6) {
            self->panel->SetVisible(1);
            for (unsigned i = 0; i < 2; i++) {
                FUN_00105470(self->w[i], i != 0);
            }
        }
        break;
    case 7:
        FUN_0001dc34(DAT_003751d4, 0x2000);
        FUN_0001de88(DAT_003751d4, 0x2000, 1);
        self->flag55 = 1;
        FUN_00242fc4(DAT_003f3994);
        if (FUN_0023bc90() == 0) {
            FUN_002b3d2c(self->sub);
        }
        break;
    case 8:
        FUN_002b1740(self->sub);
        break;
    }
}
