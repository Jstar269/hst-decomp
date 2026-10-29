/* HSTMATCH module=EBOOT.BIN start=0x002937b4 end=0x0029398c symbol=FUN_002937b4 lang=c++ */
/* Hand-written reconstruction from the disassembly (starting from the Ghidra draft, lane fm9); exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
};

struct Mon {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int state();
};

struct Gfx {
    char pad[0xc4];
    float f_c4;
    char pad_c8[8];
    float f_d0;
};

struct Cfg {
    char pad[0xf4];
    int *f_f4;
    char pad_f8[0x18];
    int f_110;
};

struct Ent {
    char pad[0x58];
    Cfg *cfg;
};

struct Obj {
    char pad[0x78];
    Gfx *gfx;
    Mon *mon;
};

extern "C" {
void FUN_00055044(Gfx *, Mat4 *);
void FUN_0005743c(Gfx *, int, int, int);
int FUN_0005787c(Cfg *, int);
void FUN_00057b58(float, Gfx *, int, int);
void FUN_00057f30(Gfx *, int);
void FUN_00058ec4(float, Gfx *, int);
void FUN_00058f38(float, Gfx *, int);
void FUN_00059084(Gfx *, int);
void FUN_0005f110(Gfx *, float);
Mat4 *FUN_00093818(Ent *);
Ent *FUN_00288a84(Mon *);
}

extern "C" void FUN_002937b4(Obj *self, int arg)
{
    Mon *m = self->mon;
    if (m != 0) {
        bool ok = m->state() == 2;
        if (!ok)
            ok = m->state() == 3;
        if (ok) {
            Ent *e = FUN_00288a84(self->mon);
            Cfg *cfg = e->cfg;
            Mat4 mat = *FUN_00093818(e);
            int id = cfg->f_f4 != 0 ? *cfg->f_f4 : 0;
            int n = cfg->f_110;
            if (n >= 0)
                id = FUN_0005787c(cfg, n);
            FUN_00057f30(self->gfx, 0);
            FUN_00055044(self->gfx, &mat);
            FUN_0005743c(self->gfx, arg, id, 0);
            FUN_00057b58(0.0f, self->gfx, 0, arg);
            Gfx *g = self->gfx;
            FUN_00058f38(0.0f, g, -1);
            FUN_0005f110(g, 0.0f);
            g = self->gfx;
            FUN_00058ec4(1.0f, g, -1);
            g->f_c4 = 1.0f;
            g = self->gfx;
            FUN_00059084(g, -1);
            g->f_d0 = g->f_c4;
        }
    }
}

// matching idiom: FUN_0005787c is declared (Cfg *, int) and called with the just-tested value (`n = cfg->f_110; if (n >= 0) id = F(cfg, n)`), retail keeps it in a1; the null-guarded id is the
// ternary `p != 0 ? *p : 0` (beqzl + move zero in the slot); the 64-byte matrix copy is a memberwise-copy-ctor Mat4 of four Vec4 (unscheduled lwc1/swc1 pairs).
