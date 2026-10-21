/* HSTMATCH module=EBOOT.BIN start=0x001821b0 end=0x00182480 symbol=FUN_001821b0 lang=c++ */
#pragma opt_strength_reduction off
struct Ctl {
    virtual void v0();
    virtual void SetEnabled(int on);
};

struct Item {
    char pad[0x24];
    int a;
    int b;
};

struct Row {
    Item *item;
    int base;
    char pad[12];
};

struct Info {
    char pad0[0xf8];
    int f_f8;
    char pad1[0x138 - 0xf8 - 4];
    int f138;
};

struct Game {
    char pad0[0x584];
    int mode584;
    char pad1[0x5bc - 0x588];
    int mode5bc;
    int *tbl5c0;
};

struct Screen {
    char pad00[0x4];
    void * f4;
    char pad01[0x4];
    unsigned char f0c;
    unsigned char f0d;
    char pad02[0x2];
    void * f10;
    char pad03[0x1f31];
    unsigned char f1f45;
    char pad04[0x2];
    void * layout;
    Ctl * c1f4c;
    char pad05[0xc];
    Ctl * c1f5c;
    Ctl * c1f60;
    Ctl * c1f64;
    Ctl * c1f68;
    Ctl * c1f6c;
    Ctl * c1f70;
    char pad06[0x424];
    Row rows[5];
    char pad07[0x468];
    void * names;
    char pad08[0x8];
    Info * info;
};

extern "C" {
void FUN_00103540(float, void *);
void FUN_001037c8(void *, int);
void FUN_00103628(void *, int);
int FUN_001fea10(int, int, int);
void FUN_0010d4a8(Info *);
Game *FUN_0016bc70(void);
void FUN_000ffb3c(Item *, int);
void FUN_00186378(Screen *, int);
void FUN_001813a0(Screen *);
}

extern "C" void FUN_001821b0(Screen *self, int param_2)
{
    if (self->f4 != 0) {
        FUN_00103540(100000.0f, self->f4);
        FUN_001037c8(self->f4, -1);
    }
    FUN_00103628(self->f10, 1);
    if (self->layout != 0) {
        FUN_00103628(self->layout, 0);
        FUN_00103628(self->names, 0);
    }
    self->f0c = 0;
    self->f0d = 0;
    self->f1f45 = 1;
    self->c1f4c->SetEnabled(0);
    self->c1f5c->SetEnabled(1);
    self->c1f60->SetEnabled(0);
    self->c1f70->SetEnabled(0);
    Info *info = self->info;
    info->f_f8 = FUN_001fea10(12, 0, param_2);
    info->f138 = 0;
    FUN_0010d4a8(info);
    int i = 0;
    int off = 0;
    do {
        Row *row = (Row *)((unsigned int)self + off + 0x2398);
        int v = FUN_0016bc70()->tbl5c0[i];
        if (v == 0x7fffffff) {
            FUN_000ffb3c(row->item, 1);
        } else {
            FUN_000ffb3c(row->item, 0);
            if (v == 2) {
                if (FUN_0016bc70()->mode5bc == 5) {
                    int n = row->base + i;
                    row->item->a = n;
                    row->item->b = n;
                } else {
                    int n = row->base + 4;
                    row->item->a = n;
                    row->item->b = n;
                }
            } else if (v == 4) {
                int n = row->base + 5;
                row->item->a = n;
                row->item->b = n;
            } else {
                int n = row->base + i;
                row->item->a = n;
                row->item->b = n;
            }
        }
        i++;
        off += 0x14;
    } while (i < 5);
    self->c1f64->SetEnabled(1);
    self->c1f68->SetEnabled(1);
    self->c1f6c->SetEnabled(1);
    switch (FUN_0016bc70()->mode584) {
    case 1:
        self->c1f64->SetEnabled(0);
        break;
    case 2:
        self->c1f68->SetEnabled(0);
        break;
    case 3:
        self->c1f6c->SetEnabled(0);
        break;
    }
    FUN_00186378(self, param_2);
    FUN_001813a0(self);
}
// Near miss (sn5; 182 vs 180 words, all instructions and branch shapes right, saved-register numbering and 2 extra words wrong).
// Retail: self=s5, i=s4, off=s3, param_2=s2, v=s1, row=s0; ours: self=s5, param_2=s4, i=s3, off=s2, row=s1, v=s0 (declaration order from the top),
// and the case dispatch at the end has two words more (the retail `b`/`nop` pairs after the first two bodies).
// Idioms found: `#pragma opt_strength_reduction off` + explicit `i`/`off += 0x14` with `(Row *)((unsigned int)self + off + 0x2398)` (retail keeps the byte offset as its own
// IV and recomputes sll for the table index); `if (layout != 0) {..}; f0c = 0;` (not an else) for the duplicated store; the final dispatch is `switch (G->mode584)` with
// cases 1, 2, 3 in source order (tests come out 3, 2, 1 as beql); the first test loads f4 into a0 and passes it to FUN_00103540(float, f4).
// Ruled out for the numbering: declaring i/off first, `int arg = param_2` copy, v before row, row/v outside the loop.
// near miss from lane sn5 (unreviewed)
