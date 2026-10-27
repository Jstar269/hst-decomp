/* HSTMATCH module=hstp_trans_main.prx start=0x000486d8 end=0x0004894c symbol=FUN_000486d8 lang=c++ */
/* Clone of src/eboot/state_copy_00048548.cpp (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane fm11 near miss reworked by lane wf20261026-e01-03: record copy is the implicit memberwise assignment of a non-POD sub-struct with array-member Vec2/Vec4, the control block at 0x3ba388 is one struct, the dropped callee arguments are the tested globals); exact match verified; names and types await human review. */
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

extern State *DAT_003751d4;
extern State DAT_003ba3c0;
extern Ctl DAT_003ba388;
extern int DAT_003ba2d0;
extern int DAT_003e19f0;
extern int DAT_003e1f60;

extern "C" void FUN_0001d8c8(void *);
extern "C" void FUN_00000f74(void *, void *, void *);
extern "C" void FUN_0001d930(void);
extern "C" int FUN_00048958(void);
extern "C" int FUN_00100d30(int);
extern "C" int FUN_0008a144(int);
extern "C" int FUN_00100e70(int);

extern "C" void FUN_000486d8(void)
{
    State *s;

    if (DAT_003ba388.inited == 0) {
        FUN_0001d8c8(&DAT_003ba3c0);
        FUN_00000f74(&DAT_003ba3c0, (void *)FUN_0001d930, &DAT_003ba388.reg);
        DAT_003ba388.inited = 1;
    }
    if (FUN_00048958() == 0) {
        s = DAT_003751d4;
        DAT_003ba3c0.b0 = s->b0;
        DAT_003ba3c0.i4 = s->i4;
        DAT_003ba3c0.b8 = s->b8;
        DAT_003ba3c0.ic = s->ic;
        DAT_003ba3c0.sub = s->sub;
    }
    if (DAT_003ba388.on != 0) {
        if (DAT_003e1f60 != 0 && FUN_00100d30(DAT_003e1f60) != 0)
            DAT_003ba388.on = 0;
    } else {
        if (DAT_003e1f60 != 0)
            FUN_00100d30(DAT_003e1f60);
    }
    s = DAT_003751d4;
    if ((*(signed char *)&s->sub.v88 << 0x18) >> 0x1e == 0 && DAT_003ba2d0 == 1 &&
        DAT_003e19f0 != 0 && FUN_0008a144(DAT_003e19f0) != 0 &&
        (DAT_003e1f60 == 0 || FUN_00100e70(DAT_003e1f60) != 0)) {
        DAT_003ba388.on = (unsigned char)((DAT_003ba388.on != 0) ^ 1);
        DAT_003ba388.pending = 0;
    }
}
