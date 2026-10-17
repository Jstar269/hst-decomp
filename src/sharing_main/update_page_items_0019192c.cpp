/* HSTMATCH module=hstp_trans_main.prx start=0x0019192c end=0x00191efc symbol=FUN_0019192c lang=c++ */
/* Hand-written reconstruction from the disassembly (restructured from the Ghidra pseudocode, hstgen.py tag sh2); exact match verified; names and types await human review. */
/* Per-page slot update (loops over 20 slots from page * 4; calls FUN_00191efc / FUN_001916f8 at the end, see toggle_page_items_00191efc.cpp): per slot it calls FUN_00105470(widget, 0), sets the widget's two int fields at +0x24/+0x28 to the slot value (plus 1 / 2 for the first slot of the first page in modes 0-1 / 2-3), passes a packed ARGB colour built from FUN_00177eb4 to FUN_001055a4 for the slot at (rem, quo) = (p9 % 4, p9 / 4) and the stored colour for the others, and updates the per-mode flag tables. Matching idioms: `switch (mode)` in the prologue (cases 0, 1, 2+3, 4 written ascending) and again in the loop (case labels 0/1 and 2/3 keep four separate compares; an `if (mode == 3 || mode == 2)` chain folds them into range tests and changes the register allocation); the packed colour is `(a & 0xff) | ((((d & 0xff) << 16) | 0x80000000) | ((b & 0xff) << 8))` with ushort locals a, b; #pragma opt_strength_reduction off keeps idx * 20 recomputed; the selected-slot widget is written as the same address expression three times (a local pointer changes the load order). */
#pragma opt_strength_reduction off
struct Widget { char pad[0x24]; int f24; int f28; };
struct Item { Widget *w; int v; int p8; int pc; int p10; };
struct Lst {
    virtual void s0();
    virtual void s1(int);
    char pad[0x100];
    int f104;
};
struct Ent { unsigned cnt; int p4, p8, pc, p10; };
struct Ctx {
    char pad0[0x5b8];
    int f5b8;
    char pad1[0x5dc - 0x5bc];
    Ent ents[1];
};
struct Tbl { int **rows; };
struct ColCtx { char pad[0x60]; int f60; int f64; int f68; };
struct Obj {
    char pad0[0x2878];
    Lst *f2878;
    Item *f287c;
    Lst *f2880;
    Item *f2884;
    Lst *f2888;
    char pad288c[4];
    Item *f2890;
    Lst *f2894;
    char pad2898[4];
    Item *f289c;
    Lst *f28a0;
    Item *f28a4;
    Lst *f28a8;
};
extern unsigned char *DAT_003ea858;
extern "C" {
extern void FUN_00105470(Widget *, int);
extern void FUN_001055a4(Widget *, unsigned);
extern unsigned char *FUN_00177d4c(void);
extern Ctx *FUN_00177e98(void);
extern ColCtx *FUN_00177eb4(void);
extern void FUN_001916f8(Obj *, int, int);
extern void FUN_00191efc(Obj *, int, int);
extern void FUN_001939ec(Obj *);
extern int FUN_00225dec(int);
extern void FUN_0019192c(Obj *self, int mode, int a2, int a3, int page, int p6, int p7, unsigned color, int p9);
}

void FUN_0019192c(Obj *self, int mode, int a2, int a3, int page, int p6, int p7, unsigned color, int p9)
{
    int page0 = page - 1;
    Lst *sel = 0;
    Item *selItems = 0;
    unsigned char *flagsA = 0;
    unsigned char *flagsB = 0;
    Tbl *tab = 0;
    if (page0 < 0)
        page0 = 0;
    int rem9 = p9 % 4;
    int quo9 = p9 / 4;
    self->f2878->s1(1);
    self->f2880->s1(1);
    switch (mode) {
    case 0:
        self->f2888->s1(1);
        self->f2894->s1(1);
        self->f28a0->s1(1);
        sel = self->f2888;
        selItems = self->f2890;
        flagsA = DAT_003ea858 + 0x63b;
        flagsB = FUN_00177d4c() + 0x84c;
        tab = (Tbl *)((char *)FUN_00177e98() + 0x1e4);
        break;
    case 1:
        self->f28a8->s1(1);
        self->f2888->s1(1);
        self->f2894->s1(1);
        self->f28a0->s1(1);
        sel = self->f2894;
        selItems = self->f289c;
        flagsA = DAT_003ea858 + 0x8bb;
        flagsB = FUN_00177d4c() + 0xacc;
        tab = (Tbl *)((char *)FUN_00177e98() + 0x1fc);
        break;
    case 2:
    case 3:
        self->f28a8->s1(1);
        self->f2888->s1(1);
        self->f2894->s1(1);
        self->f28a0->s1(1);
        sel = self->f28a0;
        selItems = self->f28a4;
        flagsA = DAT_003ea858 + 0xb3b;
        flagsB = FUN_00177d4c() + 0xd4c;
        tab = (Tbl *)((char *)FUN_00177e98() + 0x208);
        break;
    case 4:
        break;
    }
    FUN_001939ec(self);
    int i = 0;
    int idx = page0 << 2;
    do {
        int off = idx * 20;
        Item *pB = (Item *)((char *)self->f2884 + off);
        if (self->f2878->f104 <= idx)
            break;
        Item *p = (Item *)((char *)self->f287c + off);
        int r4 = i % 4;
        int q4 = page0 + i / 4;
        bool b1 = false;
        FUN_00105470(p->w, 0);
        switch (mode) {
        case 0:
        case 1:
            if (page0 == 0 && i == 0) {
                int v = p->v;
                b1 = true;
                Widget *w = p->w;
                w->f24 = v + 1;
                w->f28 = v + 1;
            } else {
                int v = p->v;
                Widget *w = p->w;
                w->f24 = v;
                w->f28 = v;
            }
            break;
        case 2:
        case 3:
            if (page0 == 0 && i == 0) {
                int v = p->v;
                b1 = true;
                Widget *w = p->w;
                w->f24 = v + 2;
                w->f28 = v + 2;
            } else {
                int v = p->v;
                Widget *w = p->w;
                w->f24 = v;
                w->f28 = v;
            }
            break;
        }
        if (r4 == rem9 && q4 == quo9) {
            ColCtx *c = FUN_00177eb4();
            unsigned short a = FUN_00225dec(c->f60);
            unsigned short b = FUN_00225dec(c->f64);
            int d = FUN_00225dec(c->f68);
            FUN_001055a4(p->w, (a & 0xff) | ((((d & 0xff) << 16) | 0x80000000) | ((b & 0xff) << 8)));
        } else {
            FUN_001055a4(p->w, color);
        }
        if (sel != 0) {
            if (idx < sel->f104 && ((Item *)((char *)selItems + off))->w != 0) {
                if (page0 == 0 && i == 0)
                    FUN_00105470(((Item *)((char *)selItems + off))->w, 1);
                else
                    FUN_00105470(((Item *)((char *)selItems + off))->w, 0);
            }
            Ctx *cx = FUN_00177e98();
            if ((unsigned)idx < cx->ents[cx->f5b8].cnt && page <= q4 && q4 < page + 3) {
                int k = *tab->rows[idx];
                unsigned char *pc = flagsA + k;
                if (*pc == 4)
                    *pc = 5;
                if (flagsB[k] == 4 && !b1 && pB->w != 0)
                    FUN_00105470(pB->w, 0);
            }
        }
        i++;
        idx++;
    } while (i < 20);
    FUN_00191efc(self, mode, page);
    FUN_001916f8(self, mode, p6);
}
