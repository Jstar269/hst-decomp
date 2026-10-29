/* HSTMATCH module=EBOOT.BIN start=0x0026b674 end=0x0026b724 symbol=FUN_0026b674 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/sharing_screen.h"

/* Layout widget, seen through the virtual calls used by the sharing pane. */
struct SharingWidget {
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

/* The pane's own virtual methods. */
struct SharingVirt {
    virtual void s0();
    virtual void s1();
    virtual void s2();
};

extern int DAT_002cfc8c;
extern "C" void FUN_00103540(SharingPane *, float);
extern "C" void FUN_001037c8(SharingPane *, int);
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_00103628(SharingPane *, int);
extern "C" void FUN_0026b724(SharingPane *, int);

/* Resets the sharing pane and enters its state 0. */
extern "C" void FUN_0026b674(SharingPane *pane)
{
    FUN_00103540(pane, 1010.0f);
    FUN_001037c8(pane, -1);
    FUN_0001dfe8(DAT_002cfc8c, 0x2000);
    FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
    if (pane->key) {
        pane->key->v10();
    }
    pane->unk54 = 1;
    pane->unk55 = 0;
    FUN_00103628(pane, 0);
    ((SharingVirt *)pane)->s2();
    FUN_0026b724(pane, 0);
}
