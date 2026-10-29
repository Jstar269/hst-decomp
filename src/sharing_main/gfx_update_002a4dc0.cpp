/* HSTMATCH module=hstp_trans_main.prx start=0x002a4dc0 end=0x002a4f98 symbol=FUN_002a4dc0 lang=c++ */
/* Clone of src/eboot/gfx_update_002937b4.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
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
void FUN_00055b64(Gfx *, Mat4 *);
void FUN_00058090(Gfx *, int, int, int);
int FUN_000584d0(Cfg *, int);
void FUN_000587ac(float, Gfx *, int, int);
void FUN_00058b84(Gfx *, int);
void FUN_00059ba8(float, Gfx *, int);
void FUN_00059c1c(float, Gfx *, int);
void FUN_00059d68(Gfx *, int);
void FUN_0005ff00(Gfx *, float);
Mat4 *FUN_0009573c(Ent *);
Ent *FUN_0029a220(Mon *);
}

extern "C" void FUN_002a4dc0(Obj *self, int arg)
{
    Mon *m = self->mon;
    if (m != 0) {
        bool ok = m->state() == 2;
        if (!ok)
            ok = m->state() == 3;
        if (ok) {
            Ent *e = FUN_0029a220(self->mon);
            Cfg *cfg = e->cfg;
            Mat4 mat = *FUN_0009573c(e);
            int id = cfg->f_f4 != 0 ? *cfg->f_f4 : 0;
            int n = cfg->f_110;
            if (n >= 0)
                id = FUN_000584d0(cfg, n);
            FUN_00058b84(self->gfx, 0);
            FUN_00055b64(self->gfx, &mat);
            FUN_00058090(self->gfx, arg, id, 0);
            FUN_000587ac(0.0f, self->gfx, 0, arg);
            Gfx *g = self->gfx;
            FUN_00059c1c(0.0f, g, -1);
            FUN_0005ff00(g, 0.0f);
            g = self->gfx;
            FUN_00059ba8(1.0f, g, -1);
            g->f_c4 = 1.0f;
            g = self->gfx;
            FUN_00059d68(g, -1);
            g->f_d0 = g->f_c4;
        }
    }
}

// matching idiom: FUN_000584d0 is declared (Cfg *, int) and called with the just-tested value (`n = cfg->f_110; if (n >= 0) id = F(cfg, n)`), retail keeps it in a1; the null-guarded id is the
// ternary `p != 0 ? *p : 0` (beqzl + move zero in the slot); the 64-byte matrix copy is a memberwise-copy-ctor Mat4 of four Vec4 (unscheduled lwc1/swc1 pairs).
