/* HSTMATCH module=EBOOT.BIN start=0x00151f24 end=0x0015216c symbol=FUN_00151f24 lang=c++ */
struct Ctx {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    float f18;
    unsigned char f1c;
    unsigned char f1d;
};

struct VC {
    virtual void d0();
    virtual int m1(float, void *);
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void m14(float);
    virtual void m15(unsigned char);
};

struct Sub {
    void *vt;
    int a;
    int b;
};

extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc440[];
extern char DAT_002dc624[];
extern char DAT_002dc654[];
extern char DAT_002dc628[];
extern int DAT_0034a114;
extern int DAT_0034a118;
extern unsigned char DAT_003083cc;
extern unsigned char DAT_00308c3c;
extern int FUN_00000bcc(int);
extern double FUN_00020f5c(float);
extern void FUN_0014d044(void *);
extern void FUN_0014fd94(char *, int, int, int, char *, double, char *);
extern int FUN_001c6f70(int, int, int);
extern int FUN_001c70c0(int);
extern void FUN_00287de4(void *, int, int, int);
}

extern "C" void *FUN_00151f24(float x, Ctx *ctx, char *prm)
{
    void *obj;
    Sub *p;
    int route;

    if (DAT_003402f0 != 0) {
        char *a;

        FUN_0014d044(prm);
        a = ctx->f1d ? DAT_002dc624 : DAT_002dc440;
        FUN_0014fd94(DAT_002dc628, ctx->f8, ctx->fc, ctx->f10,
                     ctx->f1c ? DAT_002dc654 : DAT_002dc440,
                     FUN_00020f5c(ctx->f18), a);
    }
    route = ctx->f8;
    obj = *(void **)(prm + 0xc);
    if (route == -1) {
        obj = (void *)DAT_0034a118;
        if (DAT_0034a118 != 0) {
            obj = (void *)((char *)DAT_0034a118 + 0xe0);
        }
    } else if (route >= 0) {
        if (route < 100) {
            obj = *(void **)(*(int *)(DAT_0034a114 + 0x4c) + route * 4);
        } else if (route < 1000) {
            obj = (void *)FUN_001c6f70(DAT_0034a114, route, 0);
        } else {
            obj = (void *)FUN_001c70c0(DAT_0034a114);
        }
    }
    if (obj == 0) {
        return 0;
    }
    ((VC *)obj)->m14(ctx->f18);
    ((VC *)obj)->m15(ctx->f1d);
    FUN_00287de4(obj, ctx->fc, ctx->f10, ctx->f14);
    if (ctx->f1c == 0) {
        return 0;
    }
    p = (Sub *)FUN_00000bcc(0xc);
    if (p != 0) {
        p->vt = (void *)&DAT_003083cc;
        p->vt = (void *)&DAT_00308c3c;
        p->a = ctx->f8;
        p->b = ctx->f14;
    }
    if (((VC *)p)->m1(x, prm) != 0) {
        if (p != 0) {
            delete ((VC *)p);
        }
        p = 0;
    }
    return p;
}
// NEAR (134/146 words). Real signature is (float x, Ctx *ctx, Arg *prm): a0=ctx, a1=prm, f12=x
// (`mov.s $f20,$f12`); Ghidra's param_1 is the float, not the a0 int.
// The debug print is FUN_0014fd94(fmt, ctx->f8, ctx->fc, ctx->f10, f1c_str, FUN_00020f5c(ctx->f18),
// f1d_str): the 6th parameter is a DOUBLE, so o32 skips t1 and puts it in t2:t3 - that is why Ghidra
// shows a phantom `in_t1` and the 7th string lands on the stack.
// Still off: (a) frame is 64 not 48 with an extra s3 - the f1d string gets a callee-saved reg in
// addition to the one s0 used for obj, and the f1c string is evaluated BEFORE the 0x20f5c call
// instead of after it (retail computes it straight into t0); (b) the alloc block needs the `new`
// shape `beqz v0,join; move s0,v0` (retail), not `move s0,v0; beqzl s0,..` (the plain
// `(T*)FUN_00000bcc(n); if (p)` form) - i.e. `Sub *p = new Sub(a,b)` with an inline ctor, which needs
// the class vtables at 0x003083cc/0x00308c3c, not reproducible from a fresh class (only
// __vt__4Base = 0x003083cc is in symbols). The two vptr stores are written out explicitly here.
// Virtual slots: +0x08 = deleting dtor, +0x0c = slot 1 (int m1(float,void*)), +0x40 = slot 14,
// +0x44 = slot 15 - so VC needs 16 declared virtuals.
// near miss from lane fm8 (unreviewed)
