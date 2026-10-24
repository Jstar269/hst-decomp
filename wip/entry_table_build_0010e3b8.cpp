/* HSTMATCH module=EBOOT.BIN start=0x0010e3b8 end=0x0010e5b8 symbol=FUN_0010e3b8 lang=c++ */

struct Obj;

struct Vtbl {
    char pad0[0x18];
    short (*getA)(Obj *self, int id);   /* 0x18 */
    short (*getB)(Obj *self, int id);   /* 0x1c */
};

struct Obj {
    Vtbl *vt;                           /* 0x00 */
};

struct Entry {
    int f00;                            /* 0x00 */
    int f04;                            /* 0x04 */
    int f08;                            /* 0x08 */
    int f0c;                            /* 0x0c */
    short f10;                          /* 0x10 */
    short f12;                          /* 0x12 */
    short f14;                          /* 0x14 */
    short f16;                          /* 0x16 */
    short f18;                          /* 0x18 */
    short f1a;                          /* 0x1a */
    int f1c;                            /* 0x1c */
    void *f20;                          /* 0x20 */
};

struct Mgr {
    char pad0[4];
    Obj **table;                        /* 0x04 */
    char pad8[8];
    Obj **items;                        /* 0x10 */
    char pad14[0x4c];
    float f60;                          /* 0x60 */
    float f64;                          /* 0x64 */
};

extern "C" {
extern char DAT_002d9210;
extern void FUN_000ffca4(Obj *o);
extern void FUN_00101630(Mgr *m, Entry *e, int n);
extern void FUN_0010e5b8(Mgr *m, int a, int b, int c, int d, int e, int f,
                          int n);
extern void FUN_0010ea04(Mgr *m, int a, int b, int c, int d, int e, int f,
                          int n);
}

extern "C" void FUN_0010e3b8(Mgr *m, Entry *t, int n, char flag)
{
    Entry buf[9];
    Entry *e = buf;
    int i;
    int dx = t->f14 - t->f10;
    int dy = t->f16 - t->f12;
    short w = t->f18;

    m->f60 = (float)t->f10;
    m->f64 = (float)t->f12;
    for (i = 0; i < n; i++) {
        int idx = t->f08;
        int id = t->f0c + i;
        Obj *o = m->table[idx];
        short a = o->vt->getA(o, id);
        o = m->table[idx];
        short b = o->vt->getB(o, id);

        e->f00 = t->f00;
        e->f04 = 0;
        e->f08 = idx;
        e->f0c = id;
        e->f10 = 0;
        e->f12 = 0;
        e->f14 = a + e->f10;
        e->f16 = b + e->f12;
        e->f18 = w;
        e->f1c = t->f1c;
        e->f20 = &DAT_002d9210;
        e++;
    }
    FUN_00101630(m, buf, n);
    for (i = 0; i < n; i++)
        FUN_000ffca4(m->items[i]);
    if (flag == 0)
        FUN_0010e5b8(m, 0, 0, dx, dy, 0, 0, n);
    else
        FUN_0010ea04(m, 0, 0, dx, dy, 0, 0, n);
}
// NEAR 130/128 words, 115 differ. Same frame (400), same Entry layout
// (0x24 stride), same calls; the loop body, the seh on both virtual-call
// results, the reload of m->items inside the second loop and the
// FUN_00101630(m, buf, n) call all match.
// Blocked on two things:
//  * retail keeps dx/dy in HALFWORD stack slots (a7a20044 sh v0,68(sp)) and
//    loads them straight into the arg regs (lh a3,68(sp)); mwccpsp 219 gives a
//    plain `short` local a WORD slot plus a seh (seh v0,v0; sw v0,68(sp)).
//    Tried: short dx=expr; separate short dx; short dx,dy; declaration order.
//  * register trio e/i/id: retail s0/s2/s1, ours s2/s1/s0 (decl order tried).
// Flag branch used both senses (==0 e5b8 first is what pseudo says; retail
// branches beqzl to the e5b8 path) - word count unchanged either way.
// near miss from lane fm7 (unreviewed)
