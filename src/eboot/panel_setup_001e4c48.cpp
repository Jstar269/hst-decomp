/* HSTMATCH module=EBOOT.BIN start=0x001e4c48 end=0x001e4d64 symbol=FUN_001e4c48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the table row is read through a local `Row *r = &DAT_003417b8[idx]` (a direct `DAT_003417b8[idx].s18` folds the +0x18 into the lui/addiu base); the float parameter is declared before the int that is forwarded to 0x1e4d64 (callee prototyped (UiPanel *, float, int)); `&o->slot[0].item` / `&o->slot[1].item` are held in locals (retail keeps both addresses in s4/s3 across the getter call). Names provisional. */
#include "hst/ui_panel.h"

/* Virtual interface of the object at unk1f8. */
struct VC {
    virtual void s0();
    virtual void s1(int);
};
struct Row {
    char pad[0x18];
    short s18;
    char pad2[0x120 - 0x1a];
};
struct Ctx {
    char pad[0x3cc];
    int f3cc;
};
extern "C" {
extern Row DAT_003417b8[];
void FUN_0016b21c(int);
void FUN_001e2694(UiPanel *);
void FUN_00103628(void *, int);
void FUN_000ffb3c(void *, int);
Ctx *FUN_001ee200(void);
void FUN_001e4d64(UiPanel *, float, int);
void FUN_001e4c48(UiPanel *o, int idx, float f, int a);
}
/* Shows or hides the panel's items for row idx (the first two items swap depending on whether idx is the context's current index), then runs the layout update. */
void FUN_001e4c48(UiPanel *o, int idx, float f, int a)
{
    Row *r = &DAT_003417b8[idx];
    FUN_0016b21c(r->s18);
    FUN_001e2694(o);
    FUN_00103628(o->unk1f4, 0);
    FUN_000ffb3c(o->slot[2].item, 1);
    ((VC *)o->unk1f8)->s1(1);
    UiItem **p248 = &o->slot[0].item;
    UiItem **p25c = &o->slot[1].item;
    if (idx == FUN_001ee200()->f3cc) {
        FUN_000ffb3c(*p248, 0);
        FUN_000ffb3c(*p25c, 1);
    } else {
        FUN_000ffb3c(*p248, 1);
        FUN_000ffb3c(*p25c, 0);
    }
    FUN_000ffb3c(o->slot[13].item, 1);
    FUN_000ffb3c(o->slot[12].item, 1);
    FUN_001e4d64(o, f, a);
}
