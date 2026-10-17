/* HSTMATCH module=hstp_trans_main.prx start=0x001b7810 end=0x001b7870 symbol=FUN_001b7810 lang=c++ */
/* Hand-written reconstruction from the disassembly; 6 words differ (a0/a1 register swap on state vs &o->link); names and types await human review. */

struct Link {
    char pad[0x24];
    int f24;
    int f28;
};

struct Obj {
    char pad[0xc0];
    Link *link;
};

struct Ctx {
    char pad[0x2f4];
    int f2f4;
};

extern "C" Ctx *FUN_001aa91c(void);

extern "C" void FUN_001b7810(Obj *o)
{
    Ctx *ctx = FUN_001aa91c();
    Link **pp = &o->link;
    switch (ctx->f2f4) {
    case 0:
        (*pp)->f24 = (*pp)->f28;
        break;
    case 1:
        (*pp)->f24 = (*pp)->f28 + 1;
        break;
    }
}
// Near miss: 6 words differ.
// In retail, state is loaded into a1 and &o->link is hoisted into a0 (delay slot of beq a1, v1).
// In ours, state is loaded into a0 and &o->link is in a1.
// Control flow, delay slots, and case bodies match retail identically.
// near miss from lane u1r5-3 (unreviewed)
