/* HSTMATCH module=EBOOT.BIN start=0x00048548 end=0x000487bc symbol=FUN_00048548 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane fm11 near miss reworked by lane wf20261026-e01-03: record copy is the implicit memberwise assignment of a non-POD sub-struct with array-member Vec2/Vec4, the control block at 0x311060 is one struct, the dropped callee arguments are the tested globals); exact match verified; names and types await human review. */
struct Vec2 { float v[2]; };
struct Vec4 { float v[4]; };

struct Sub {
    int q[16];
    int f80;
    int f84;
    Vec2 v88;
    Vec4 v90;
    Vec4 va0;
    Vec4 vb0;
    Sub() {}
};

struct State {
    unsigned char b0;
    int i4;
    unsigned char b8;
    int ic;
    char pad0[0x30];
    Sub sub;
};

struct Ctl {
    int on;
    int pending;
    char inited;
    int reg;
};

extern State *DAT_002cfc8c;
extern State DAT_00311080;
extern Ctl DAT_00311060;
extern int DAT_00310fd0;
extern int DAT_003386b0;
extern int DAT_00338c20;

extern "C" void FUN_0001dc7c(void *);
extern "C" void FUN_00000f74(void *, void *, void *);
extern "C" void FUN_0001dce4(void);
extern "C" int FUN_000487c8(void);
extern "C" int FUN_000fb5f4(int);
extern "C" int FUN_000889ec(int);
extern "C" int FUN_000fb734(int);

extern "C" void FUN_00048548(void)
{
    State *s;

    if (DAT_00311060.inited == 0) {
        FUN_0001dc7c(&DAT_00311080);
        FUN_00000f74(&DAT_00311080, (void *)FUN_0001dce4, &DAT_00311060.reg);
        DAT_00311060.inited = 1;
    }
    if (FUN_000487c8() == 0) {
        s = DAT_002cfc8c;
        DAT_00311080.b0 = s->b0;
        DAT_00311080.i4 = s->i4;
        DAT_00311080.b8 = s->b8;
        DAT_00311080.ic = s->ic;
        DAT_00311080.sub = s->sub;
    }
    if (DAT_00311060.on != 0) {
        if (DAT_00338c20 != 0 && FUN_000fb5f4(DAT_00338c20) != 0)
            DAT_00311060.on = 0;
    } else {
        if (DAT_00338c20 != 0)
            FUN_000fb5f4(DAT_00338c20);
    }
    s = DAT_002cfc8c;
    if ((*(signed char *)&s->sub.v88 << 0x18) >> 0x1e == 0 && DAT_00310fd0 == 1 &&
        DAT_003386b0 != 0 && FUN_000889ec(DAT_003386b0) != 0 &&
        (DAT_00338c20 == 0 || FUN_000fb734(DAT_00338c20) != 0)) {
        DAT_00311060.on = (unsigned char)((DAT_00311060.on != 0) ^ 1);
        DAT_00311060.pending = 0;
    }
}
