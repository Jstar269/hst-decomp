/* HSTMATCH module=EBOOT.BIN start=0x00286db0 end=0x00286e08 symbol=FUN_00286db0 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

/* Virtual interface of the actor (the vtable pointer is CmdActor.vtbl). */
class CmdActorV {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
};

extern "C" {
extern void *DAT_0034a114;
extern void FUN_001cc880(void *);
extern void FUN_001cd3d8(void *);
}

/* Stores the enabled flag, tells the system object, and calls virtual slot 16. */
extern "C" void FUN_00286db0(CmdActor *self, int on)
{
    self->enabled = on;
    FUN_001cc880(DAT_0034a114);
    if (self->enabled != 0)
        FUN_001cd3d8(DAT_0034a114);
    ((CmdActorV *)self)->v16();
}
