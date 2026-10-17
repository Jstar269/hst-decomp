/* HSTMATCH module=EBOOT.BIN start=0x001851e0 end=0x001857b0 symbol=FUN_001851e0 lang=c++ */
/* Clone of src/sharing_main/update_page_items_0019192c.cpp (hstclone.py tag c042120): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (restructured from the Ghidra pseudocode, hstgen.py tag sh2); exact match verified; names and types await human review. */
/* Per-page slot update (loops over 20 slots from page * 4; calls FUN_001857b0 / FUN_00184fac at the end, see toggle_page_items_001857b0.cpp): per slot it calls FUN_000ffb3c(widget, 0), sets the widget's two int fields at +0x24/+0x28 to the slot value (plus 1 / 2 for the first slot of the first page in modes 0-1 / 2-3), passes a packed ARGB colour built from FUN_0016bc8c to FUN_000ffc70 for the slot at (rem, quo) = (p9 % 4, p9 / 4) and the stored colour for the others, and updates the per-mode flag tables. Matching idioms: `switch (mode)` in the prologue (cases 0, 1, 2+3, 4 written ascending) and again in the loop (case labels 0/1 and 2/3 keep four separate compares; an `if (mode == 3 || mode == 2)` chain folds them into range tests and changes the register allocation); the packed colour is `(a & 0xff) | ((((d & 0xff) << 16) | 0x80000000) | ((b & 0xff) << 8))` with ushort locals a, b; #pragma opt_strength_reduction off keeps idx * 20 recomputed; the selected-slot widget is written as the same address expression three times (a local pointer changes the load order). */
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
extern unsigned char *DAT_00341518;
extern "C" {
extern void FUN_000ffb3c(Widget *, int);
extern void FUN_000ffc70(Widget *, unsigned);
extern unsigned char *FUN_0016bb88(void);
extern Ctx *FUN_0016bc70(void);
extern ColCtx *FUN_0016bc8c(void);
extern void FUN_00184fac(Obj *, int, int);
extern void FUN_001857b0(Obj *, int, int);
extern void FUN_001872a0(Obj *);
extern int FUN_00216de8(int);
extern void FUN_001851e0(Obj *self, int mode, int a2, int a3, int page, int p6, int p7, unsigned color, int p9);
}

void FUN_001851e0(Obj *self, int mode, int a2, int a3, int page, int p6, int p7, unsigned color, int p9)
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
        flagsA = DAT_00341518 + 0x63b;
        flagsB = FUN_0016bb88() + 0x84c;
        tab = (Tbl *)((char *)FUN_0016bc70() + 0x1e4);
        break;
    case 1:
        self->f28a8->s1(1);
        self->f2888->s1(1);
        self->f2894->s1(1);
        self->f28a0->s1(1);
        sel = self->f2894;
        selItems = self->f289c;
        flagsA = DAT_00341518 + 0x8bb;
        flagsB = FUN_0016bb88() + 0xacc;
        tab = (Tbl *)((char *)FUN_0016bc70() + 0x1fc);
        break;
    case 2:
    case 3:
        self->f28a8->s1(1);
        self->f2888->s1(1);
        self->f2894->s1(1);
        self->f28a0->s1(1);
        sel = self->f28a0;
        selItems = self->f28a4;
        flagsA = DAT_00341518 + 0xb3b;
        flagsB = FUN_0016bb88() + 0xd4c;
        tab = (Tbl *)((char *)FUN_0016bc70() + 0x208);
        break;
    case 4:
        break;
    }
    FUN_001872a0(self);
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
        FUN_000ffb3c(p->w, 0);
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
            ColCtx *c = FUN_0016bc8c();
            unsigned short a = FUN_00216de8(c->f60);
            unsigned short b = FUN_00216de8(c->f64);
            int d = FUN_00216de8(c->f68);
            FUN_000ffc70(p->w, (a & 0xff) | ((((d & 0xff) << 16) | 0x80000000) | ((b & 0xff) << 8)));
        } else {
            FUN_000ffc70(p->w, color);
        }
        if (sel != 0) {
            if (idx < sel->f104 && ((Item *)((char *)selItems + off))->w != 0) {
                if (page0 == 0 && i == 0)
                    FUN_000ffb3c(((Item *)((char *)selItems + off))->w, 1);
                else
                    FUN_000ffb3c(((Item *)((char *)selItems + off))->w, 0);
            }
            Ctx *cx = FUN_0016bc70();
            if ((unsigned)idx < cx->ents[cx->f5b8].cnt && page <= q4 && q4 < page + 3) {
                int k = *tab->rows[idx];
                unsigned char *pc = flagsA + k;
                if (*pc == 4)
                    *pc = 5;
                if (flagsB[k] == 4 && !b1 && pB->w != 0)
                    FUN_000ffb3c(pB->w, 0);
            }
        }
        i++;
        idx++;
    } while (i < 20);
    FUN_001857b0(self, mode, page);
    FUN_00184fac(self, mode, p6);
}
