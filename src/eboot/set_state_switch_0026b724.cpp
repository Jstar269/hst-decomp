/* HSTMATCH module=EBOOT.BIN start=0x0026b724 end=0x0026b850 symbol=FUN_0026b724 lang=c++ */
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

extern char DAT_0034179c;
extern int DAT_0034a120;
extern int DAT_0034b328;
extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_0001f21c(int, void *);
extern "C" void FUN_0010b6d4(SharingWidget *, int, int);
extern "C" void FUN_001b3ea4(float, void *);
extern "C" void *FUN_0029a8bc(void *);
extern "C" void FUN_0029dfdc(int);

/* Switches the sharing pane to a new state and runs the state's entry action. */
extern "C" void FUN_0026b724(SharingPane *pane, int state)
{
    void *p;
    pane->state = state;
    switch (state) {
    case 0:
        pane->unk55 = 0;
        pane->page1->v1(0);
        pane->page2->v1(1);
        pane->key->v1(0);
        pane->key->v10();
        FUN_0010b6d4(pane->key, 0, 1);
        pane->key->v6(3001.0f);
        pane->unk68 = 0;
        break;
    case 1:
        pane->key->v1(1);
        FUN_001b3ea4(0.5f, &DAT_0034179c);
        pane->unk6c = 0;
        break;
    case 2:
        p = FUN_00000bcc(0x40);
        if (p) {
            p = FUN_0029a8bc(p);
        }
        FUN_0001f21c(DAT_0034a120, p);
        FUN_0029dfdc(DAT_0034b328);
        break;
    }
}
