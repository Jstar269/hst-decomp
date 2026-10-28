/* HSTMATCH module=EBOOT.BIN start=0x0025cba0 end=0x0025ccb4 symbol=FUN_0025cba0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

extern int DAT_002cfc8c;
extern Dat3386c8 *DAT_003386c8;
extern unsigned char DAT_003417be;

extern "C" void FUN_00103540(AdhocMenu *, float);
extern "C" void FUN_001037c8(AdhocMenu *, int);
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_00103628(AdhocMenu *, int);
extern "C" void FUN_00280830(void *, int, int);
extern "C" void FUN_0025ccfc(AdhocMenu *, int);
extern "C" Res *FUN_0008d994(Dat3386c8 *);

/* Resets the menu to its initial state: releases its widget, sets the first-frame flags and clears two global state bytes. */
extern "C" void FUN_0025cba0(AdhocMenu *self)
{
    FUN_00103540(self, 1010.0f);
    FUN_001037c8(self, -1);
    FUN_0001dfe8(DAT_002cfc8c, 0x2000);
    FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
    if (self->unk58) {
        ((SubObj *)self->unk58)->v10();
    }
    self->unk54 = 1;
    self->unk55 = 0;
    FUN_00103628(self, 0);
    ((MenuVt *)self)->s2();
    FUN_00103540(self, 99990.0f);
    FUN_001037c8(self, -1);
    FUN_00280830(self->unk5c, 0, 1);
    DAT_003386c8->f44 = 0;
    DAT_003417be = 0;
    FUN_0025ccfc(self, 0);
    Res *res = FUN_0008d994(DAT_003386c8);
    res->v1();
    self->unk3c8 = 0;
}
