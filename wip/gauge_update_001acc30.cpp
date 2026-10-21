/* HSTMATCH module=EBOOT.BIN start=0x001acc30 end=0x001acf64 symbol=FUN_001acc30 lang=c++ */
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
Ctx *FUN_0019d474();
int FUN_0016b070(int);
int FUN_0016b0c0(int);
void FUN_000ffb3c(int *, int);
void FUN_0010b980(W *, int, int);
}

extern "C" void FUN_001acc30(Obj *o, unsigned char flag)
{
    Ctx *ctx = FUN_0019d474();
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
            int t = FUN_0016b070(a);
            sC->p[9] = sC->p[10] + t;
            break;
        }
        case 1: {
            int t = FUN_0016b0c0(b);
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
                    if (a < 1) { FUN_000ffb3c(sA->p, 0); FUN_000ffb3c(sB->p, 1); }
                    else if (a >= 2) { FUN_000ffb3c(sA->p, 1); FUN_000ffb3c(sB->p, 0); }
                    else { FUN_000ffb3c(sA->p, 0); FUN_000ffb3c(sB->p, 0); }
                    break;
                case 1:
                    if (b < 1) { FUN_000ffb3c(sA->p, 0); FUN_000ffb3c(sB->p, 1); }
                    else if (b >= 2) { FUN_000ffb3c(sA->p, 1); FUN_000ffb3c(sB->p, 0); }
                    else { FUN_000ffb3c(sA->p, 0); FUN_000ffb3c(sB->p, 0); }
                    break;
                case 2:
                    if (c < 1) { FUN_000ffb3c(sA->p, 0); FUN_000ffb3c(sB->p, 1); }
                    else if (c >= 1) { FUN_000ffb3c(sA->p, 1); FUN_000ffb3c(sB->p, 0); }
                    else { FUN_000ffb3c(sA->p, 0); FUN_000ffb3c(sB->p, 0); }
                    break;
                }
            } else {
                FUN_000ffb3c(sA->p, 1);
                FUN_000ffb3c(sB->p, 1);
            }
        } else {
            FUN_000ffb3c(sA->p, 1);
            FUN_000ffb3c(sB->p, 1);
        }
    }
    if (flag) {
        o->w914->v1(0);
        FUN_0010b980(o->w914, sel, 0);
    }
}

// NEAR MISS (lane sn6, EBOOT twin of the Sharing wip gauge_update_001ba298.cpp; the two bodies are byte-identical apart from addresses): 11 words differ,
// all stack-slot displacements of the three spilled values (flag sits at 60+3 in both).
//   retail: off (i*20 byte offset) = sp+48, sel = sp+52, c = sp+56;  ours: c = sp+48, off = sp+52, sel = sp+56.
// Slot order tracks some per-value cost (ascending slot = ascending cost): removing the final use of sel gives [c, sel, off]; ANY number of extra stores that use
// c inside case 2 (1, 2 or 3 more) gives [off, c, sel] and never passes sel (c would have to outrank sel). Retail's order needs cost(off) < cost(sel) < cost(c).
// Ruled out here too: the redundant second c test spelled `c < 1` or `c <= 0` instead of `c >= 1` (14 words, worse); the Sharing lane's 24 declaration orders of sel/a/b/c.
// near miss from lane sn6 (unreviewed)
