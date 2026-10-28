/* HSTMATCH module=hstp_trans_main.prx start=0x0026d050 end=0x0026d164 symbol=FUN_0026d050 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/reset_state_0025cba0.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
#include "hst/adhoc_menu.h"

/* Virtual slots of the menu object (slot 2 is called here). */
struct MenuVt {
    virtual void s0();
    virtual void s1();
    virtual void s2();
};

/* Virtual slots of the widget at AdhocMenu.unk58 (slot 10 is called here). */
struct SubObj {
    virtual void v0();
    virtual void v1(int);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

struct Res {
    virtual void v0();
    virtual void v1();
};

struct Dat3386c8 {
    char pad[0x44];
    unsigned char f44;
};

extern int DAT_003751d4;
extern Dat3386c8 *DAT_003e1a08;
extern unsigned char DAT_003eaaf6;

extern "C" void FUN_00108e6c(AdhocMenu *, float);
extern "C" void FUN_001090f4(AdhocMenu *, int);
extern "C" void FUN_0001dc34(int, int);
extern "C" void FUN_0001de88(int, int, int);
extern "C" void FUN_00108f54(AdhocMenu *, int);
extern "C" void FUN_00291b78(void *, int, int);
extern "C" void FUN_0026d1ac(AdhocMenu *, int);
extern "C" Res *FUN_0008f170(Dat3386c8 *);

/* Resets the menu to its initial state: releases its widget, sets the first-frame flags and clears two global state bytes. */
extern "C" void FUN_0026d050(AdhocMenu *self)
{
    FUN_00108e6c(self, 1010.0f);
    FUN_001090f4(self, -1);
    FUN_0001dc34(DAT_003751d4, 0x2000);
    FUN_0001de88(DAT_003751d4, 0x2000, 1);
    if (self->unk58) {
        ((SubObj *)self->unk58)->v10();
    }
    self->unk54 = 1;
    self->unk55 = 0;
    FUN_00108f54(self, 0);
    ((MenuVt *)self)->s2();
    FUN_00108e6c(self, 99990.0f);
    FUN_001090f4(self, -1);
    FUN_00291b78(self->unk5c, 0, 1);
    DAT_003e1a08->f44 = 0;
    DAT_003eaaf6 = 0;
    FUN_0026d1ac(self, 0);
    Res *res = FUN_0008f170(DAT_003e1a08);
    res->v1();
    self->unk3c8 = 0;
}
