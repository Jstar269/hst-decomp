/* HSTMATCH module=EBOOT.BIN start=0x001e6224 end=0x001e6ffc symbol=FUN_001e6224 lang=c++ rodata=0x002c8d24 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Mode switch over the panel widgets. SetTwoWidgetsFlag/ApplyOffsets are inline copies of the same-file functions 0x1e611c/0x1e617c (expanded here). Matching idioms: the int flag parameter is narrowed to an unsigned char local just before the switch (retail keeps the raw t0 in s7) and the inline takes it as bool, and the case-16 test is a bare `if (flag)` (`flag != 0` re-masks with andi); sub-object addresses held in pointer locals (wp) as in 0x1e617c. */
extern "C" {
void FUN_000ffb3c(void *, int);
void FUN_0010d4a8(void *);
void FUN_00103628(void *, int);
void FUN_0021e4cc(void *, int, int);
void FUN_0021dd14(void *);
void FUN_001bfdd0(int, int, int, int);
void FUN_0021869c(int *, int *, int);
void FUN_00218814(int *, int *, int);
void FUN_00218a24(int *, int *, int);
int FUN_001fea10(int, int, int);
extern int DAT_002ec1a8;
extern int DAT_002ec1ac;
}
struct Game { char pad[0x1368]; int f1368; };
extern "C" Game *FUN_001ee200(void);

struct VObj {
    virtual void d0();
    virtual void m(int);
};
struct Obj1 {
    virtual void d0();
    virtual void m(int);
    char pad[0xf8 - 4];
    int f_f8;
    char pad2[0x138 - 0xfc];
    int f_138;
};
struct Rect { char pad[0x24]; int f24; int f28; };
struct Holder {
    Rect *w;
    int pad[4];
    void Set(int v) { FUN_000ffb3c(w, v); }
};
struct ObjHolder { int x; Obj1 *p; int pad[3]; };

struct Self {
    char pad[0x1960];
    VObj *v1960;
    VObj *v1964;
    VObj *v1968;
    Holder w196c;
    Holder w1980;
    Holder w1994;
    Holder w19a8;
    Holder w19bc;
    Holder w19d0;
    Holder w19e4;
    Holder w19f8;
    Holder w1a0c;
    Holder w1a20;
    Holder w1a34;
    Holder w1a48;
    Holder w1a5c;
    Holder w1a70;
    Holder h0;
    Holder h1;
    ObjHolder h;
    char pad2[0x1adc - 0x1ac0];
    void *items[21];
    int mode;
    char pad3[0x1d64 - 0x1b34];
    void *x1d64;
};

extern "C" void FUN_001e5fbc(Self *, int, int, int, int, int, int, int, int, int, unsigned char);

inline void SetTwoWidgetsFlag(Self *o, bool enable)
{
    Holder *a = &o->h0;
    Holder *b = &o->h1;
    if (enable) {
        a->Set(0);
        b->Set(0);
    } else {
        a->Set(1);
        b->Set(1);
    }
}

inline void ApplyOffsets(Self *self, int a, int b, int c)
{
    ObjHolder *hp = &self->h;
    hp->p->m(0);
    Obj1 *o = hp->p;
    o->f_f8 = a;
    o->f_138 = 1;
    FUN_0010d4a8(o);
    Rect *r = self->h0.w;
    r->f24 = r->f28 + b;
    Holder *wp = &self->w1a5c;
    FUN_000ffb3c(wp->w, 0);
    Rect *w = wp->w;
    w->f24 = w->f28 + c;
}

static inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_001e6224(Self *self, int mode, int n, int p4, int flag0)
{
    int i;
    for (i = 0; i < 21; i++) {
        if (self->items[i] != 0)
            FUN_00103628(self->items[i], 1);
    }
    self->v1960->m(1);
    self->v1964->m(1);
    self->v1968->m(1);
    FUN_0021e4cc(self->x1d64, 1, 0);
    int l1 = 0;
    int l2 = 0;
    int a = 0;
    int b = 0;
    if (p4 != 0) {
        a = 1;
        b = a;
    }
    unsigned char flag = flag0;
    switch (mode) {
    case 0:
        break;
    case 1: {
        int g = FUN_001ee200()->f1368;
        FUN_0021dd14(self->x1d64);
        FUN_001bfdd0(g, mode, n, 4);
        FUN_0021e4cc(self->x1d64, 0, 1);
        FUN_0021869c(&l1, &l2, n);
        int r = FUN_001fea10(3, 0, n);
        FUN_001e5fbc(self, n, 1, 4, r, 3, l1, l2, a, b, flag);
        break;
    }
    case 2: {
        int g = FUN_001ee200()->f1368;
        FUN_0021dd14(self->x1d64);
        FUN_001bfdd0(g, mode, n, 4);
        FUN_0021e4cc(self->x1d64, 0, 1);
        FUN_00218814(&l1, &l2, n);
        int r = FUN_001fea10(1, 0, n);
        FUN_001e5fbc(self, n, 0, 4, r, 3, l1, l2, a, b, flag);
        break;
    }
    case 3: {
        FUN_001bfdd0(FUN_001ee200()->f1368, mode, n, 4);
        FUN_0021e4cc(self->x1d64, 0, 1);
        FUN_00218a24(&l1, &l2, n);
        int r = FUN_001fea10(0, 0, n);
        FUN_001e5fbc(self, n, 2, 4, r, 3, l1, l2, a, b, flag);
        break;
    }
    case 4: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w19bc;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n / 10;
        ApplyOffsets(self, FUN_001fea10(13, 0, n), 3, 2);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 6: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w19a8;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(5, 0, n), 3, 1);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 7: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w19d0;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(4, 0, n), 5, 4);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 8: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w19e4;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(4, 1, n), 5, 4);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 9: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w1a20;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(4, 2, n), 5, 4);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 10: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w19f8;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(4, 3, n), 5, 4);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 11: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w1a34;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(4, 4, n), 5, 4);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 12: {
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        Holder *wp = &self->w1a0c;
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + n;
        ApplyOffsets(self, FUN_001fea10(4, 5, n), 5, 4);
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 13:
    case 14:
    case 15:
        break;
    case 5: {
        self->v1960->m(0);
        FUN_000ffb3c(self->h1.w, 0);
        if (self->items[n] != 0)
            FUN_00103628(self->items[n], 0);
        Holder *wp = &self->w196c;
        int v = Clamp(n - 1, DAT_002ec1a8, DAT_002ec1ac);
        FUN_000ffb3c(wp->w, 0);
        wp->w->f24 = wp->w->f28 + v;
        Rect *r = self->h0.w;
        r->f24 = r->f28;
        SetTwoWidgetsFlag(self, flag);
        break;
    }
    case 16:
        self->v1968->m(0);
        FUN_000ffb3c(self->w1a70.w, 0);
        self->w1a70.w->f24 = self->w1a70.w->f28 + a;
        FUN_000ffb3c(self->w1a48.w, 0);
        self->w1a48.w->f24 = self->w1a48.w->f28 + b;
        SetTwoWidgetsFlag(self, flag);
        if (flag) {
            Rect *r = self->h0.w;
            r->f24 = r->f28 + 4;
            Rect *w = self->w1a5c.w;
            w->f24 = w->f28;
        }
        break;
    }
    self->mode = mode;
}
