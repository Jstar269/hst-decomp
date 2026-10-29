/* HSTMATCH module=hstp_trans_main.prx start=0x0020e58c end=0x0020e710 symbol=FUN_0020e58c lang=c++ */
/* Clone of src/eboot/ctor_menu_regulation_001ffdbc.cpp (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/regulation_menu.h"

extern "C" char DAT_003971b8;
extern "C" char DAT_003971e8;
extern "C" char DAT_00397190;
extern "C" char DAT_002d95e0;
extern "C" char DAT_002d97f4;
extern "C" char DAT_002d9790;
extern "C" void *DAT_003f347c;

extern "C" void *FUN_00000bcc(int);
extern "C" void *FUN_0010873c(void *);
extern "C" void FUN_002262f8(void *, void *, int);
extern "C" void FUN_00109a44(void *, void *, int);
extern "C" void FUN_00108e6c(void *, float);
extern "C" void FUN_001090f4(void *, int);
extern "C" void FUN_00225e94(void *, void *, void *, int);
extern "C" void FUN_00225f18(void *, void *, void *, int);
extern "C" void FUN_00225fb4(void *, void *, void *, int);
extern "C" void FUN_0022618c(void *, void *, void *);
extern "C" void FUN_00226050(void *, void *, void *, int);
extern "C" void FUN_00105570(void *, int);
extern "C" void FUN_002267ac(void *, void *);
extern "C" void FUN_002266bc(void *, void *);

/* Build the regulation menu: load the unit list and the layout, create the panes and widgets, set up the animators. */
extern "C" void FUN_0020e58c(RegulationMenu *self) {
    void *layout = FUN_00000bcc(0x54);
    if (layout != 0) {
        layout = FUN_0010873c(layout);
    }
    self->layout = layout;
    FUN_002262f8(&DAT_003f347c, &DAT_003971b8, REGULATION_UNIT_COUNT);
    FUN_00109a44(self->layout, &DAT_003971e8, 0);
    FUN_00108e6c(self->layout, 2250.0f);
    FUN_001090f4(self->layout, -16);
    FUN_00225e94(self->panes, self->layout, &DAT_00397190, REGULATION_PANE_COUNT);
    FUN_00225f18(self->list30, self->panes, DAT_003f347c, REGULATION_UNIT_COUNT);
    FUN_00225fb4(self->widget648, self->panes, &DAT_002d95e0, 13);
    FUN_0022618c(&self->obj708, self->panes, &DAT_002d97f4);
    FUN_00226050(self->widget6e4, self->panes, &DAT_002d9790, 3);
    ResultObj *obj = self->obj708;
    obj->unkd8 = 0;
    obj->unk114 = 1;
    FUN_00105570(self->unk634, -4096);
    FUN_002267ac(&self->anims[0], self->panes[0]);
    FUN_002267ac(&self->anims[1], self->panes[6]);
    FUN_002267ac(&self->anims[2], self->panes[8]);
    FUN_002267ac(&self->anims[3], self->panes[2]);
    FUN_002267ac(&self->anims[4], self->panes[3]);
    FUN_002267ac(&self->anims[5], self->panes[4]);
    FUN_002267ac(&self->anims[6], self->panes[5]);
    FUN_002266bc(&self->anims[7], self->unk56c);
    FUN_002266bc(&self->anims[8], self->unk634);
}
