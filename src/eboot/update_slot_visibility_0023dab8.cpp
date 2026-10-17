/* HSTMATCH module=EBOOT.BIN start=0x0023dab8 end=0x0023dda4 symbol=FUN_0023dab8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: switch (mode) with case 0 before case 1 (retail tests 1 first); `Slot *cur = &self->cur` declared before the switch (hoisted into s0); entries read through an inline accessor taking `unsigned` (a plain `entries[i]` or `int` index strength-reduces i*8); Widget::SetFrame stores m24 then m28 (a chained `a = b = v` stores in the other order). The five slot groups are slots[9 + 15*k + i] of one 20-byte-stride array at +0x2c. */
struct VC {
    virtual void s0();
    virtual void s1(int);
};
struct Widget {
    char pad0[0x24];
    int m24;
    int m28;
    void SetFrame(int v) { m24 = v; m28 = v; }
};
struct Slot {
    Widget *w;
    int base;
    int pad[3];
};
struct Info {
    unsigned char kind;
    char pad[3];
    float f4;
};
struct Entry {
    Info *info;
    int extra;
};
struct Game {
    char pad[0x1818];
    Entry *entries;
    Entry *Get(unsigned i) { return &entries[i]; }
};
struct Self {
    char pad0[0xc];
    VC *w0c;
    VC *w10;
    char pad1[0x2c - 0x14];
    Slot slots[84];
    char pad2[0x384];
    Slot cur;
};
extern int DAT_0034a77c;
extern "C" Game *FUN_00238d58();
extern "C" int FUN_0024dd40(int, float);
extern "C" void FUN_000ffb3c(Widget *, int);
extern "C" void FUN_0023d714(Self *);

extern "C" void FUN_0023dab8(Self *self, int mode) {
    Slot *cur = &self->cur;
    switch (mode) {
    case 0:
        self->w0c->s1(0);
        self->w10->s1(1);
        cur->w->m24 = cur->w->m28;
        for (int i = 0; i < 15; i++) {
            Slot *a = &self->slots[i + 9];
            Slot *b = &self->slots[i + 24];
            Slot *c = &self->slots[i + 39];
            Slot *d = &self->slots[i + 54];
            Slot *e = &self->slots[i + 69];
            Entry *g = FUN_00238d58()->Get(i);
            if (g->info) {
                if ((unsigned)(g->info->kind - 4) < 2) {
                    int n = FUN_0024dd40(DAT_0034a77c, g->info->f4);
                    if (n >= 9) {
                        FUN_000ffb3c(a->w, 1);
                        FUN_000ffb3c(b->w, 0);
                        FUN_000ffb3c(c->w, 0);
                        c->w->SetFrame(c->base + 1);
                    } else {
                        FUN_000ffb3c(a->w, 0);
                        a->w->SetFrame(a->base + n);
                        FUN_000ffb3c(b->w, 1);
                        FUN_000ffb3c(c->w, 0);
                        if (n == 0) c->w->SetFrame(c->base);
                        else c->w->SetFrame(c->base + 1);
                    }
                    FUN_000ffb3c(d->w, 0);
                    d->w->SetFrame(d->base + g->extra);
                    FUN_000ffb3c(e->w, 0);
                } else {
                    FUN_000ffb3c(a->w, 1);
                    FUN_000ffb3c(b->w, 1);
                    FUN_000ffb3c(c->w, 1);
                    FUN_000ffb3c(d->w, 1);
                    FUN_000ffb3c(e->w, 0);
                }
            } else {
                FUN_000ffb3c(a->w, 1);
                FUN_000ffb3c(b->w, 1);
                FUN_000ffb3c(c->w, 1);
                FUN_000ffb3c(d->w, 1);
                FUN_000ffb3c(e->w, 1);
            }
        }
        break;
    case 1:
        self->w0c->s1(1);
        self->w10->s1(0);
        cur->w->m24 = cur->w->m28 + 1;
        FUN_0023d714(self);
        break;
    }
}
