/* HSTMATCH module=EBOOT.BIN start=0x000dbae0 end=0x000dbc04 symbol=FUN_000dbae0 lang=c++ */
struct Entry {
    char pad[0xe3];
    unsigned char e3;
    char pad2[0x120 - 0xe4];
};
extern Entry DAT_003417b8[2];

struct Obj {
    char pad[0xb8];
    int f_b8[3];
    int f_c4[3];
    int f_d0[3];
};
struct Obj8c {
    char pad[0x8c];
    int f8c;
};

extern "C" int FUN_000def0c(Obj *o);

static inline int Check1(Obj *o)
{
    for (int i = 0; i < 2; i++) {
        if (((Obj8c *)o)->f8c != 0) {
            return 0;
        }
    }
    return 1;
}

static inline int Check2(Obj *o)
{
    for (int i = 0; i < 2; i++) {
        int v = FUN_000def0c(o) ? 0 : DAT_003417b8[i].e3;
        if (o->f_d0[i] != v) {
            return 0;
        }
    }
    return 1;
}

static inline int Check3(Obj *o)
{
    for (int i = 0; i < 2; i++) {
        if (o->f_c4[i] != 0) {
            return 0;
        }
    }
    return 1;
}

static inline int Check4(Obj *o)
{
    for (int i = 0; i < 2; i++) {
        if (o->f_b8[i] != 0) {
            return 0;
        }
    }
    return 1;
}

extern "C" int FUN_000dbae0(Obj *o)
{
    if (Check1(o)) {
        if (Check2(o)) {
            if (Check3(o)) {
                return Check4(o);
            }
        }
    }
    return 0;
}
// NEAR 73/73 words, 48 differ (sy3). Structure decoded from retail: four inline int loops (early `return 0` inside, `return 1` after) called in a
// cascade; Obj fields are int[3] arrays at 0xb8/0xc4/0xd0 (stride 12 between them, only [0..1] used), stage 1 tests the same word 0x8c twice
// (load hoisted by MWCC), stage 2 is `FUN_000def0c(o) ? 0 : DAT_003417b8[i].e3` (entry stride 0x120, byte at +0xe3).
// Left: the call-site polarity. Retail lays each stage test as `bnezl v0,<next>` with the NEXT stage's first insn in the slot and the failure path
// `b <next stage's test>; move v0,zero` right after (a failure jumps to the following stage's test, cascading to the end), ours lays
// `beqzl v0,END; move v0,zero`. Nested ifs (this file), `ok = Check(); if (ok) ok = ...;` (70/73), `&&` chain (77/73), `else ok = 0;` variants
// (optimised away), bool-typed ok (adds andi) were all tried.
// near miss from lane sy3 (unreviewed)
