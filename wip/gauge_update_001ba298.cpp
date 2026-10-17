/* HSTMATCH module=hstp_trans_main.prx start=0x001ba298 end=0x001ba5cc symbol=FUN_001ba298 lang=c++ */
struct W {
    virtual void v0();
    virtual void v1(int);
};

struct Slot {
    int *p;
    int pad[4];
};

struct Ctx {
    char pad[0x2e0];
    int sel;
    int a;
    int pad2;
    int b;
    int pad3;
    int c;
};

struct Obj {
    char pad[0x24];
    Slot slot[0x40];
    char pad1[0x914 - 0x24 - 0x40 * 20];
    W *w914;
};

extern "C" {
Ctx *FUN_001aa91c();
int FUN_00177234(int);
int FUN_00177284(int);
void FUN_00105470(int *, int);
void FUN_00111b58(W *, int, int);
}

extern "C" void FUN_001ba298(Obj *o, unsigned char flag)
{
    Ctx *ctx = FUN_001aa91c();
    int sel = ctx->sel;
    int a = ctx->a;
    int b = ctx->b;
    int c = ctx->c;
    for (int i = 0; i < 3; i++) {
        Slot *sA = &o->slot[14 + i * 2];
        Slot *sB = &o->slot[15 + i * 2];
        Slot *sC = &o->slot[20 + i];
        switch (i) {
        case 0: {
            int t = FUN_00177234(a);
            sC->p[9] = sC->p[10] + t;
            break;
        }
        case 1: {
            int t = FUN_00177284(b);
            sC->p[9] = sC->p[10] + t;
            break;
        }
        case 2:
            sC->p[9] = sC->p[10] + c;
            break;
        }
        if (flag) {
            if (sel == i) {
                switch (i) {
                case 0:
                    if (a < 1) { FUN_00105470(sA->p, 0); FUN_00105470(sB->p, 1); }
                    else if (a >= 2) { FUN_00105470(sA->p, 1); FUN_00105470(sB->p, 0); }
                    else { FUN_00105470(sA->p, 0); FUN_00105470(sB->p, 0); }
                    break;
                case 1:
                    if (b < 1) { FUN_00105470(sA->p, 0); FUN_00105470(sB->p, 1); }
                    else if (b >= 2) { FUN_00105470(sA->p, 1); FUN_00105470(sB->p, 0); }
                    else { FUN_00105470(sA->p, 0); FUN_00105470(sB->p, 0); }
                    break;
                case 2:
                    if (c < 1) { FUN_00105470(sA->p, 0); FUN_00105470(sB->p, 1); }
                    else if (c >= 1) { FUN_00105470(sA->p, 1); FUN_00105470(sB->p, 0); }
                    else { FUN_00105470(sA->p, 0); FUN_00105470(sB->p, 0); }
                    break;
                }
            } else {
                FUN_00105470(sA->p, 1);
                FUN_00105470(sB->p, 1);
            }
        } else {
            FUN_00105470(sA->p, 1);
            FUN_00105470(sB->p, 1);
        }
    }
    if (flag) {
        o->w914->v1(0);
        FUN_00111b58(o->w914, sel, 0);
    }
}

// NEAR MISS (agent snS5-00): 11 words differ, ALL of them stack-slot displacements of the three spilled values.
// Everything else (registers, branch layout, likely slots, both switches, tail) matches retail.
// retail: off (the i*20 byte offset, strength-reduced) = sp+48, sel = sp+52, c = sp+56;
// ours:   c = sp+48, off = sp+52, sel = sp+56 (same cyclic order, rotated by one slot).
// Ruled out: permuting the declaration order of sel/a/b/c (24 orders; c-first or a-after-b change the s7/s8 registers),
// i declared outside the loop / unsigned i / do-while, o->w914 through a cast (that one only caches the address in s0).
// Probe: adding extra loop uses of c moves c up one slot (sel=56, c=52, off=48), i.e. retail wants c to rank above sel.
// Needed polarity: nested chain is `if (x < 1) A; else if (x >= 2) C; else B;` (c: `x >= 1`), retail lays C out as fallthrough.
