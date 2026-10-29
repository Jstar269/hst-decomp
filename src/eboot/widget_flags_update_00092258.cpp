/* HSTMATCH module=EBOOT.BIN start=0x00092258 end=0x00092630 symbol=FUN_00092258 lang=c++ data=0x002d2908 */
/* Hand-written reconstruction from the disassembly (restructured from the hstgen.py tag a3 candidate); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d2908-0x002d292e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Matching idioms: the four state flags are `bool`s read from signed 4-bit field bits (`e->hi62 & 1`, `& 2`) and the second accumulates with `b2 |= e->hi62 & 1` (a `||` short-circuits); `if (b4 || (b1 && b3))` is one shared block; the loop counts go through an inline `Count(c)` ternary in a `while` condition (rotated test with entry jump); the per-index value is `v9 != 0 && !(flags & 2)` (the `^ 1` and bool-variable spellings add an extra sltu/andi); `(v9 != 0) ^ 1` is kept for the later call (sltu;xori). Names provisional. */
#include "hst/char_model.h"

/* Bone-entry record: the signed 4-bit fields carry the state flags. */
struct Ent {
    char pad0[0x62];
    signed char lo62 : 4;
    signed char hi62 : 4;
    char pad63;
    signed char lo64 : 4;
};
struct Reg;
extern "C" {
extern Reg *DAT_00338b08;
Ent *FUN_000d8c24(Reg *, int, unsigned);
unsigned FUN_0002fe08(struct List *);
int FUN_0002fe80(struct List *, char *);
void FUN_00054464(ModelCtrl *, int, int, int, int);
}
static inline int Count(ModelCtrl *c)
{
    return c->list == 0 ? 0 : FUN_0002fe08(c->list);
}
static inline int Find(struct List *l, char *name)
{
    if (l != 0)
        return FUN_0002fe80(l, name);
    return -1;
}
/* Rebuilds the character's flag bits from the entry-table records of items 1..4, and shows or hides
   the hat bones ("Bip01Head9for_hat" / "Bip01Head9for_org") of items 0 and 1 to match. */
extern "C" void FUN_00092258(CharModel *self)
{
    bool item1_on = false;
    bool item34_on = false;
    bool item2_on = false;
    bool item2_alt = false;
    self->flags = self->flags & 0x20;
    if (self->item[1] != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 1, self->item[1]->id);
        if (e != 0)
            item1_on = e->hi62 & 1;
    }
    if (self->item[3] != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 3, self->item[3]->id);
        if (e != 0)
            item34_on = e->hi62 & 1;
    }
    if (self->item[4] != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 4, self->item[4]->id);
        if (e != 0)
            item34_on |= e->hi62 & 1;
    }
    if (self->item[2] != 0) {
        Ent *e = FUN_000d8c24(DAT_00338b08, 2, self->item[2]->id);
        if (e != 0) {
            item2_on = e->hi62 & 1;
            item2_alt = e->hi62 & 2;
        }
    }
    if (item2_alt || (item1_on && item2_on)) {
        item1_on = false;
        self->flags |= 2;
    }
    if (item1_on || item2_on) {
        if (item34_on)
            self->flags |= 8;
    }
    if (self->item[0] != 0 && self->item[0]->ctrl != 0 && self->item[1] != 0 && self->item[1]->ctrl != 0) {
        unsigned show = self->unk75;
        Ent *e = FUN_000d8c24(DAT_00338b08, 1, self->item[1]->id);
        if (e != 0) {
            if (e->lo64 != 1)
                show = 0;
        }
        int bone = Find(self->item[0]->ctrl->list, "Bip01Head9for_hat");
        if (bone >= 0) {
            if (show != 0 && item34_on) {
                item34_on = false;
                ModelCtrl *c = self->item[0]->ctrl;
                int i = 0;
                while (i < Count(c)) {
                    FUN_00054464(c, -1, i, i == bone, 0);
                    i++;
                }
            } else {
                ModelCtrl *c = self->item[0]->ctrl;
                int i = 0;
                while (i < Count(c)) {
                    int v = 1;
                    if (i == bone)
                        v = show != 0 && !(self->flags & 2);
                    FUN_00054464(c, -1, i, v, 0);
                    i++;
                }
            }
        }
        bone = Find(self->item[1]->ctrl->list, "Bip01Head9for_hat");
        if (bone >= 0)
            FUN_00054464(self->item[1]->ctrl, -1, bone, (show != 0) ^ 1, 0);
        bone = Find(self->item[1]->ctrl->list, "Bip01Head9for_org");
        if (bone >= 0)
            FUN_00054464(self->item[1]->ctrl, -1, bone, show, 0);
    }
    if (item1_on || item34_on || item2_on)
        self->flags |= 1;
}
