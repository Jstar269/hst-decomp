/* HSTMATCH module=EBOOT.BIN start=0x001ffdbc end=0x001fff40 symbol=FUN_001ffdbc lang=c++ */
/* Regulation_LoadLayoutAndUnitList: regulation_unitlist.txt; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/regulation_menu.h"

extern "C" char DAT_002ef130;
extern "C" char DAT_002ef160;
extern "C" char DAT_002ef108;
extern "C" char DAT_002c9148;
extern "C" char DAT_002c935c;
extern "C" char DAT_002c92f8;
extern "C" void *DAT_0034a144;

extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_00102e38(void *);
extern "C" void FUN_002172f4(void *, void *, int);
extern "C" void FUN_00104118(void *, void *, int);
extern "C" void FUN_00103540(void *, float);
extern "C" void FUN_001037c8(void *, int);
extern "C" void FUN_00216e90(void *, void *, void *, int);
extern "C" void FUN_00216f14(void *, void *, void *, int);
extern "C" void FUN_00216fb0(void *, void *, void *, int);
extern "C" void FUN_00217188(void *, void *, void *);
extern "C" void FUN_0021704c(void *, void *, void *, int);
extern "C" void FUN_000ffc3c(void *, int);
extern "C" void FUN_00217704(void *, void *);
extern "C" void FUN_00217614(void *, void *);

/* Build the regulation menu: load the unit list and the layout, create the panes and widgets, set up the animators. */
extern "C" void FUN_001ffdbc(RegulationMenu *self) {
    void *layout = FUN_00000bcc(0x54);
    if (layout != 0) {
        layout = FUN_00102e38(layout);
    }
    self->layout = layout;
    FUN_002172f4(&DAT_0034a144, &DAT_002ef130, REGULATION_UNIT_COUNT);
    FUN_00104118(self->layout, &DAT_002ef160, 0);
    FUN_00103540(self->layout, 2250.0f);
    FUN_001037c8(self->layout, -16);
    FUN_00216e90(self->panes, self->layout, &DAT_002ef108, REGULATION_PANE_COUNT);
    FUN_00216f14(self->list30, self->panes, DAT_0034a144, REGULATION_UNIT_COUNT);
    FUN_00216fb0(self->widget648, self->panes, &DAT_002c9148, 13);
    FUN_00217188(&self->obj708, self->panes, &DAT_002c935c);
    FUN_0021704c(self->widget6e4, self->panes, &DAT_002c92f8, 3);
    ResultObj *obj = self->obj708;
    obj->unkd8 = 0;
    obj->unk114 = 1;
    FUN_000ffc3c(self->unk634, -4096);
    FUN_00217704(&self->anims[0], self->panes[0]);
    FUN_00217704(&self->anims[1], self->panes[6]);
    FUN_00217704(&self->anims[2], self->panes[8]);
    FUN_00217704(&self->anims[3], self->panes[2]);
    FUN_00217704(&self->anims[4], self->panes[3]);
    FUN_00217704(&self->anims[5], self->panes[4]);
    FUN_00217704(&self->anims[6], self->panes[5]);
    FUN_00217614(&self->anims[7], self->unk56c);
    FUN_00217614(&self->anims[8], self->unk634);
}
