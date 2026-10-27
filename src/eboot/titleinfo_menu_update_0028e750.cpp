/* HSTMATCH module=EBOOT.BIN start=0x0028e750 end=0x0028f3fc symbol=FUN_0028e750 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the table-6 entry is read as a byte offset `(char *)data + slot * 4 + 4` to get base-first addressing; table lookups via a static inline GetText with early returns, inline_depth(8)); names and types await human review. */

struct Rect {
    char pad0[4];
    short x0;
    short pad6;
    short x1;
    short padA;
    short padC;
    unsigned short flags;
    char pad10[0x24 - 0x10];
    int f24;
    int f28;

    void SetFrame(int k) { f24 = f28 + k; }
    void SetX(short x)
    {
        short d = x - x0;
        x0 = x;
        x1 += d;
    }
};

struct VW {
    virtual void m0();
    virtual void m1(bool);
};

struct Widget : VW {
    char pad[0xe8 - 4];
    unsigned char fe8;
};

struct Panel : VW {
    char pad[0xf8 - 4];
    const char *text;
    char pad1[0x138 - 0xfc];
    int dirty;
};

struct ItemList : VW {
    char pad[0x10 - 4];
    void **items;
    int count;
    void *At(unsigned i) { return items[i]; }
};

struct Game {
    char pad0[4];
    int f4;
    char pad8[0x18 - 8];
    char f18[0x345 - 0x18];
    char f345[0x36d - 0x345];
    unsigned char f36d;
    char pad36e[0x493 - 0x36e];
    signed char f493;
    char pad494[0x617 - 0x494];
    unsigned char f617;
    char pad618[0x2c08 - 0x618];
    int f2c08;
    int f2c0c;
};

struct Mgr {
    char pad[0x28];
    int state;
};

struct Cfg {
    char pad[0x8b];
    signed char a : 2;
    signed char b : 2;
    signed char c : 2;
};

struct Hdr {
    char pad[8];
    int ncols;
};

struct Col {
    const char **data;
    int size;
    int cap;
};

struct Ent {
    int f0;
    int loaded;
    Hdr *hdr;
    Col *cols;
};

struct Sink {
    virtual void s0();
    virtual void s1();
    virtual void s2();
};

struct Cam {
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5(int);
    virtual void c6(float);
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
};

struct Self {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual int d8();
    char pad4[0x58 - 4];
    Widget *f58;
    char pad5c[0x164 - 0x5c];
    int f164;
    int f168;
    char pad16c[0x51c - 0x16c];
    unsigned char f51c;
    char pad51d[0x640 - 0x51d];
    Game *game;
    char pad644[0x64c - 0x644];
    int f64c;
    char pad650[0x65c - 0x650];
    VW *f65c;
    char pad660[0x6a8 - 0x660];
    void *f6a8;
    char pad6ac[0x1850 - 0x6ac];
    int mode;
    int f1854;
    char pad1858[0x185c - 0x1858];
    Rect *ring;
    int idx;
    void *f1864;
    void *f1868;
    char f186c[0x10];
    char f187c[0x10];
    Panel *f188c;
    Panel *f1890;
    char f1894[0x1a14 - 0x1894];
    char f1a14[0x1b94 - 0x1a14];
    ItemList *f1b94;
    void *f1b98;
    Rect *d0r;
    Rect *d1r;
    Rect *d2r;
    Rect *d3r;
    char pad1bac[2];
    short x1bae;
    char pad1bb0[2];
    short x1bb2;
    void *f1bb4;
};

extern "C" {
extern char DAT_0034a678[];
extern char DAT_0034179c[];
extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
extern char DAT_002fefac[];
extern char DAT_002fefbc[];
extern char DAT_002fefcc[];
extern int DAT_002cabac[];
extern char DAT_00341ab0;
extern char DAT_00341bd0;
extern int DAT_002fefa8;
extern Mgr *DAT_00338ac4;
extern Cfg *DAT_002cfc8c;
extern Cam *DAT_003386c0;
extern void *DAT_003386c8;
extern void *DAT_003415ac;

void FUN_00283c14(Game *);
void FUN_000ffb3c(void *, bool);
void FUN_00103128(Self *);
void FUN_00234158(char *, int);
void FUN_0028e074(Self *, int);
void FUN_0028e5e8(Self *);
void FUN_00049094(int);
void FUN_002a4938(void);
void FUN_00281090(Game *);
int FUN_0011564c(void *);
int FUN_001155c0(void *);
void FUN_001b1c44(char *, int);
int FUN_0010ba20(Widget *, int *, int, int);
void FUN_00258630(Self *, int);
void FUN_00258a68(Self *);
void FUN_0027fef0(void *, float);
void *FUN_001026b8(void *, const char *);
Ent *FUN_0018c9f4(int);
void FUN_0010d4a8(Panel *);
void FUN_000143b0(char *, const char *, ...);
void FUN_0025967c(Self *);
Sink *FUN_0008d994(void *);
void FUN_00110a78(Sink *, const char *, int);
}

#pragma inline_depth(8)
static inline const char *GetText(Ent *e, int col, int row)
{
    if (e->loaded == 0)
        return DAT_002c0e20;
    if (e->hdr->ncols <= col)
        return DAT_002c0e1c;
    if (row < 0 || row >= e->cols[col].size)
        return DAT_002c0e18;
    return e->cols[col].data[row];
}

static inline void SetText(Panel *p, const char *s)
{
    p->text = s;
    p->dirty = 1;
    FUN_0010d4a8(p);
}

static inline void Center(Rect *r)
{
    short w = r->x1 - r->x0;
    short d = -w / 2;
    r->x0 += d;
    r->x1 += d;
}

static inline int Rank(int v)
{
    if (v <= 4)
        return 0;
    if (v <= 9)
        return 1;
    if (v <= 14)
        return 2;
    return 3;
}

static inline int Clamp(int v, const int &lo, const int &hi)
{
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_0028e750(Self *self)
{
    if (self->d8() == 0)
        return;

    FUN_00283c14(self->game);
    int flag = self->game->f617;
    bool hide = !flag;
    self->f58->m1(hide);
    FUN_000ffb3c(self->f6a8, hide);
    FUN_00103128(self);

    int idx = (self->idx + 1) % 32;
    self->idx = idx;
    self->ring->f24 = self->ring->f28 + idx;

    int mode = self->mode;
    if (mode == 4) {
        if (self->game->f4 == 0)
            FUN_00234158(DAT_0034a678, 0x39);
        else
            FUN_00234158(DAT_0034a678, 0x37);
        return;
    }

    int st = 12;
    if (DAT_00338ac4 != 0)
        st = DAT_00338ac4->state;

    if (self->game->f2c0c == 0 && mode == 1) {
        FUN_0028e074(self, 0);
        return;
    }
    if (mode == 5) {
        if (self->f1854 >= 60) {
            FUN_00049094(1);
            FUN_002a4938();
            FUN_00281090(self->game);
            FUN_00234158(DAT_0034a678, 0x1e);
        }
        DAT_003386c0->c6(10.0f);
        DAT_003386c0->c5(5);
        DAT_003386c0->c11();
        self->f1854++;
        return;
    }
    if (st == 8) {
        FUN_0028e074(self, 4);
        return;
    }
    if (st == 6) {
        if (FUN_0011564c(DAT_003415ac) != 0)
            FUN_0028e074(self, 5);
        return;
    }
    if (st == 7) {
        FUN_0028e074(self, 3);
        return;
    }

    if ((self->ring->flags & 3) == 0 && self->f58->fe8 != 0 && self->game->f2c0c > 0) {
        if (st == 5)
            FUN_0028e074(self, 2);
        self->f58->fe8 = 0;
    } else if (mode == 1 && DAT_002cfc8c->a == 0) {
        FUN_001b1c44(DAT_0034179c, 6);
        self->f51c = !self->f51c;
    } else {
        int sel = self->game->f2c08;
        if (FUN_0010ba20(self->f58, &sel, self->game->f2c0c, 0) != 0) {
            FUN_001b1c44(DAT_0034179c, 1);
            self->game->f617 = 0;
        }
        self->game->f2c08 = sel;
    }

    FUN_00258630(self, 0);
    FUN_00258a68(self);
    if (flag == 0) {
        FUN_000ffb3c(self->f1864, 1);
        FUN_000ffb3c(self->f1868, 1);
    } else {
        FUN_000ffb3c(self->f1864, self->game->f2c08 == 0);
        int cnt = self->game->f2c0c;
        bool on = true;
        if (cnt != 0 && self->game->f2c08 != cnt - 1)
            on = false;
        FUN_000ffb3c(self->f1868, on);
    }
    FUN_0027fef0(self->f186c, 0.5f);
    FUN_0027fef0(self->f187c, 0.5f);

    bool single = self->game->f4 == 1;
    int slot = self->game->f493;
    void *w = FUN_001026b8(self->f1b98, DAT_002fefac);
    FUN_000ffb3c(w, !single);
    w = FUN_001026b8(self->f1b98, DAT_002fefbc);
    FUN_000ffb3c(w, single);
    if (single) {
        Ent *e6 = FUN_0018c9f4(6);
        const char *s;
        if (e6->loaded == 0)
            s = DAT_002c0e20;
        else if (e6->hdr->ncols < 1)
            s = DAT_002c0e1c;
        else if (slot + 1 < 0 || slot + 1 >= e6->cols[0].size)
            s = DAT_002c0e18;
        else
            s = *(const char **)((char *)e6->cols[0].data + slot * 4 + 4);
        SetText(self->f1890, s);
        self->f1890->m1(0);
        self->f188c->m1(1);
    } else {
        if (self->game->f36d != 0) {
            SetText(self->f188c, GetText(FUN_0018c9f4(19), 0, 2));
        } else {
            int r0 = Rank(self->f164);
            int r1 = Rank(self->f168);
            DAT_00341ab0 = DAT_002cabac[r0];
            DAT_00341bd0 = DAT_002cabac[r1];
            FUN_000143b0(self->f1a14, GetText(FUN_0018c9f4(19), 14, r0), self->game->f345);
            SetText(self->f188c, self->f1a14);
        }
        self->f188c->m1(0);
        self->f1890->m1(1);
    }
    FUN_0025967c(self);
    self->f65c->m1(1);

    int v = self->game->f2c08 + 1;
    int cnt = self->game->f2c0c;
    int n = Clamp(v, DAT_002fefa8, cnt);
    self->d0r->SetFrame(n / 10);
    FUN_000ffb3c(self->d0r, n / 10 == 0);
    self->d1r->SetFrame(n % 10);
    self->d2r->SetFrame(cnt / 10);
    FUN_000ffb3c(self->d2r, cnt / 10 == 0);
    self->d3r->SetFrame(cnt % 10);
    self->f64c++;

    switch (self->mode) {
    case 0:
        FUN_00110a78(FUN_0008d994(DAT_003386c8), DAT_002fefcc, 0);
        if (self->game->f2c0c > 0) {
            FUN_0028e074(self, 1);
        } else {
            FUN_0028e5e8(self);
            if (FUN_0011564c(DAT_003415ac) != 0) {
                self->d7();
                FUN_00234158(DAT_0034a678, 0x1e);
                return;
            }
        }
        break;
    case 1:
        Ent *e = FUN_0018c9f4(18);
        char *name = self->game->f18;
        FUN_000143b0(self->f1894, GetText(e, 11, 0), name);
        FUN_00110a78(FUN_0008d994(DAT_003386c8), self->f1894, 0);
        if ((DAT_002cfc8c->c != 0) ^ 1) {
            self->d7();
            FUN_00234158(DAT_0034a678, 0x1e);
            return;
        }
        break;
    case 2:
        if (FUN_0011564c(DAT_003415ac) != 0)
            FUN_0028e074(self, 0);
        break;
    case 3:
        if (FUN_001155c0(DAT_003415ac) != 0) {
            FUN_00049094(1);
            FUN_002a4938();
            FUN_00281090(self->game);
            FUN_00234158(DAT_0034a678, 0x1e);
            return;
        }
        break;
    }

    if (single) {
        ItemList *l = self->f1b94;
        for (int i = 0; i < l->count; i++)
            FUN_000ffb3c(l->At(i), i != slot);
    } else {
        self->f1b94->m1(1);
    }

    Ent *e = FUN_0018c9f4(18);
    char *name = self->game->f18;
    FUN_000143b0(self->f1894, GetText(e, 11, 0), name);
    FUN_00110a78(FUN_0008d994(DAT_003386c8), self->f1894, 0);
    FUN_0008d994(DAT_003386c8)->s2();
    DAT_003386c0->c6(10.0f);
    DAT_003386c0->c5(5);
    DAT_003386c0->c11();
    FUN_000ffb3c(self->f1bb4, 0);
    if ((self->d0r->flags & 3) != 0) {
        self->d1r->SetX(self->x1bae);
        Center(self->d1r);
    }
    if ((self->d2r->flags & 3) != 0) {
        self->d3r->SetX(self->x1bb2);
        Center(self->d3r);
    }
}
