/* HSTMATCH module=hstp_trans_main.prx start=0x001b7540 end=0x001b7798 symbol=FUN_001b7540 lang=c++ */
/* Clone of src/eboot/panel_update_001a9f74.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (starting from the Ghidra draft, lane fm9); exact match verified; names and types await human review. */
struct Widget {
    char pad[0x24];
    int cur;
    int base;
};

struct Row {
    Widget *w;
    int pad[4];
};

struct IntVec {
    int *data;
    unsigned size;
    unsigned cap;
    int &operator[](unsigned i) { return data[i]; }
};

struct Mgr {
    char pad[0x2bc];
    unsigned sel;
    char pad2c0[0x88];
    IntVec levels;
    IntVec flags;
};

struct Panel {
    char pad[0x20];
    Row e[49];
    char pad3f8[8];
    void *f3fc;
};

extern "C" {
Mgr *FUN_001aa91c(void);
void FUN_00105470(Widget *, int);
void FUN_00111b58(void *, unsigned, int);
}

extern "C" void FUN_001b7540(Panel *self)
{
    unsigned sel = FUN_001aa91c()->sel;
    IntVec *flags = &FUN_001aa91c()->flags;
    IntVec *levels = &FUN_001aa91c()->levels;
    int i;
    for (i = 0; i < 3; i++) {
        Row *r340 = &self->e[40 + i];
        Row *r2c8 = &self->e[34 + i];
        Row *r304 = &self->e[37 + i];
        Row *r37c = &self->e[43 + i];
        if ((unsigned)i < flags->size) {
            FUN_00105470(r304->w, 0);
            FUN_00105470(r37c->w, 0);
            switch ((*levels)[i]) {
            case 1:
                r304->w->cur = r304->w->base;
                r37c->w->cur = r37c->w->base + 1;
                break;
            case 2:
                r304->w->cur = r304->w->base + 1;
                r37c->w->cur = r37c->w->base + 1;
                break;
            case 3:
                r304->w->cur = r304->w->base + 2;
                r37c->w->cur = r37c->w->base;
                break;
            }
            if ((*flags)[i] != 0) {
                if ((unsigned)i == sel) {
                    if ((*levels)[i] == 3)
                        r340->w->cur = r340->w->base;
                    else
                        r340->w->cur = r340->w->base + 1;
                    FUN_00105470(r340->w, 0);
                } else {
                    FUN_00105470(r340->w, 1);
                }
                FUN_00105470(r2c8->w, 1);
            } else {
                FUN_00105470(r340->w, 1);
                FUN_00105470(r2c8->w, 0);
            }
        } else {
            FUN_00105470(r340->w, 1);
            FUN_00105470(r2c8->w, 1);
            FUN_00105470(r304->w, 1);
            FUN_00105470(r37c->w, 1);
        }
    }
    FUN_00111b58(self->f3fc, sel, 0);
}

// matching idiom: the three loop-top element addresses are `Row *r = &self->e[K + i]` locals (retail keeps (off+K*20)+self+0x20 in s-regs instead of folding the offsets into the loads);
// the two int vectors are read through an inline `operator[](unsigned)`, which keeps `i*4` recomputed (no extra induction register); the sel/else tail `show(r2c8, 1)` is shared after the if/else.
