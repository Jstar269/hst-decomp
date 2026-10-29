/* HSTMATCH module=EBOOT.BIN start=0x0027bad0 end=0x0027be20 symbol=FUN_0027bad0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed C++ structs, the neg-position path as the else arm of `prev >= 0.0f`, repeated mode calls as written (the 4/1/2 tests are one || chain, bodies of the duplicated float-call arms spelled out twice), the 1.0f step in a non-const local (value-first add.s / shared $f3), table entries indexed `tab[o->cur].unk34` (index-first); 0x477eff00 is 65279.0f; readability pass; exact match verified; names and types await human review. */
#include "hst/table_player.h"

struct Iface {
    virtual void v0();
    virtual void v1(int);
};
extern "C" {
extern TableRec *DAT_0034a7e4;
extern int DAT_00331b84;
extern int DAT_003313c4;
extern Iface *FUN_0027c75c(TablePlayer *);
extern void FUN_0027cb40(Iface *);
extern int FUN_0027c8a0(TablePlayer *);
extern int FUN_0027c8d0(TablePlayer *, int);
extern int FUN_0027c774(TablePlayer *, int);
extern void FUN_0027c908(TablePlayer *, int);
extern void FUN_0027c018(TablePlayer *);
extern void FUN_0027dc90(int, int *);
extern void FUN_00063d08(float, float, int, int);
}

/* Per-frame step of the table player: advance its clock and, when the clock passes the limit,
   move on to the next record chosen by the current kind. */
extern "C" void FUN_0027bad0(TablePlayer *self)
{
    if (self->active == 0) {
        return;
    }
    float prev = self->pos;
    if (prev >= 0.0f) {
        float step = 1.0f;
        float now = self->time;
        self->time = now + step;
        self->pos = now - (float)self->offset;
        if (self->unk5c <= 0.0f && DAT_0034a7e4[self->cur].unk34 != 0x3c) {
            float limit_value = self->limit;
            if (self->pos == limit_value - step) {
                if (FUN_0027c8a0(self) == 5) {
                    FUN_00063d08(65279.0f, -1.0f, DAT_00331b84, 6);
                } else if (FUN_0027c8a0(self) == 3) {
                    FUN_00063d08(65279.0f, -1.0f, DAT_00331b84, 6);
                }
            } else if (prev < limit_value && self->pos >= limit_value) {
                if (FUN_0027c8a0(self) == 5) {
                    int a;
                    self->pos = 0.0f;
                    FUN_0027dc90(self->sub->key, &a);
                    a = FUN_0027c774(self, a);
                    self->cur = -1;
                    self->offset = (int)((float)self->offset + self->limit);
                    FUN_0027c908(self, a);
                } else if (FUN_0027c8a0(self) == 4 || FUN_0027c8a0(self) == 1 || FUN_0027c8a0(self) == 2) {
                    int b;
                    FUN_0027dc90(self->sub->key, &b);
                    b = FUN_0027c774(self, b);
                    if (DAT_0034a7e4[b].unk24 != 0) {
                        self->pos = 0.0f;
                        self->cur = -1;
                        self->offset = (int)((float)self->offset + self->limit);
                        FUN_0027c908(self, b);
                    }
                } else if (FUN_0027c8a0(self) == 3 && FUN_0027c8d0(self, 1) != 999) {
                    int c;
                    self->pos = 0.0f;
                    FUN_0027dc90(DAT_0034a7e4[self->cur].key, &c);
                    c = FUN_0027c774(self, c);
                    self->cur = -1;
                    self->offset = (int)((float)self->offset + self->limit);
                    FUN_0027c908(self, c);
                }
            }
        }
        FUN_0027c018(self);
    } else {
        FUN_0027cb40(FUN_0027c75c(self));
        FUN_0027c75c(self)->v1(DAT_003313c4);
    }
}
