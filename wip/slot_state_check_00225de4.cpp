/* HSTMATCH module=EBOOT.BIN start=0x00225de4 end=0x00225f6c symbol=FUN_00225de4 lang=c++ */
/* Hand-written reconstruction from the disassembly; NOT exact (30 of 98 words differ, register naming only; same instruction count and block layout as retail). */
struct W { char pad[0x78]; float f78; };
struct A {
    char pad[0x64];
    int f64;
    W *f68;
};
struct B {
    char pad[0x55];
    unsigned char f55;
    char pad1[0x60 - 0x56];
    int f60;
    W *f64;
};
struct C {
    char pad[0x60];
    int f60;
    int pad64;
    W *f68;
};
struct D {
    char pad[0x64];
    int f64;
    char pad68[4];
    W *f6c;
};
struct Obj {
    char pad[8];
    A *f8;
    A *fc;
    B *f10;
    char pad14[4];
    C *f18;
    D *f1c;
};
struct Top {
    char pad[0x3c];
    Obj *f3c;
};
extern int DAT_002eff94;
extern "C" bool FUN_00225de4(Top *t);
bool FUN_00225de4(Top *top)
{
    Obj *o = top->f3c;
    int b1, b2, b3, b4, b5;
    bool ok;
    A *a1 = o->f8;
    b1 = a1->f64 < 0;
    if (!b1) {
        b1 = 1;
        if (!(a1->f68->f78 <= 0.0f))
            b1 = 0;
    }
    A *a2 = o->fc;
    ok = (unsigned char)b1;
    b2 = a2->f64 < 0;
    if (!b2) {
        b2 = 1;
        if (!(a2->f68->f78 <= 0.0f))
            b2 = 0;
    }
    B *a3 = o->f10;
    ok = ok & (unsigned char)b2;
    b3 = a3->f60 < 0;
    if (!b3) {
        b3 = 1;
        if (!(a3->f64->f78 <= 0.0f))
            b3 = 0;
    }
    if (b3)
        b3 = (a3->f55 != 0) ^ 1;
    C *a4 = o->f18;
    ok = ok & (unsigned char)b3;
    b4 = a4->f60 < 0;
    if (!b4) {
        b4 = 1;
        if (!(a4->f68->f78 <= 0.0f))
            b4 = 0;
    }
    ok = ok & (unsigned char)b4;
    b5 = true;
    D *a5 = o->f1c;
    int i = a5->f64;
    int b6 = true;
    if (i >= 0 && i <= DAT_002eff94)
        b6 = false;
    if (!b6) {
        if (!(a5->f6c->f78 <= 0.0f))
            b5 = 0;
    }
    return ok & (unsigned char)b5;
}

// Near miss, register colours only: every instruction, branch target and delay slot matches retail (98 words); the five slot checks are
// `b = idx < 0; if (!b) { b = 1; if (!(f78 <= 0.0f)) b = 0; }` (b and the 0/1 materialisation share one register, which needs the
// `b = 1; if (!cond) b = 0` shape; a direct `b = f78 <= 0.0f` materialises into a temp and splits the web), accumulated as
// `ok = ok & (unsigned char)b` into a `bool` (the cast gives retail's andi 0xff before each sltu); the 4th slot adds `(f55 != 0) ^ 1`;
// the 5th is `b5 = true; ... if (!oor) { if (!(f78 <= 0.0f)) b5 = 0; }` (that block matches retail's registers exactly).
// Retail's colours in blocks 1-4: b = a0, obj = a1, ok = a2; ours: ok = a0, obj = a1, b = a2 (this order, with the next object load written
// BEFORE the `ok = ...` update) or obj = a0, ok = a1, b = a2 (object load after the update, perm r1). Ruled out (about 90 compiles):
// all declaration orders of b/ok/pointers, initialised b's, one reused `b`, bool/uchar/int types for b and ok, inline predicate functions
// (return types int/bool/uchar, with and without casts), C (lang=c99) with uchar/int, `||` and && forms (bltz branches instead of slt+bnezl),
// early-initialised ok. The first block's `lw a1,12(v0)` sits in the bnezl delay slot in retail; ours puts the mask there (it follows from the colours).
