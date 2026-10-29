/* HSTMATCH module=EBOOT.BIN start=0x00286e08 end=0x00286f00 symbol=FUN_00286e08 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual calls, boolean flag reuse with xori, Vec4 assignment to parameter; readability pass; exact match verified; names and types await human review. */
#include "hst/cmd_actor.h"

extern "C" {
extern void *FUN_00022418(void *out, void *a, void *b);
extern void FUN_001cd3d0(void *p);
extern void FUN_001cd3e4(void *p);
}

struct SysGlobals {
    char pad[0xf9];
    unsigned char flagF9;  // 0xf9
};

extern "C" SysGlobals *DAT_0034a114;

/* Virtual interface of the actor (the vtable pointer is CmdActor.vtbl). */
struct CmdActorV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void *v6();     // returns a vector pointer
    virtual void v7(Vec4 *v); // takes a vector
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual int v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
};

/* Per-frame update: when virtual slot 11 reports 2 or 3, sets the actor position through slot 7. */
extern "C" void FUN_00286e08(CmdActor *self)
{
    Vec4 copy;
    Vec4 r;
    bool slotOk;
    CmdActorV *v = (CmdActorV *)self;

    v->v17();
    if (self->enabled != 0) {
        FUN_001cd3d0(DAT_0034a114);
        FUN_001cd3e4(DAT_0034a114);
    }
    slotOk = v->v11() == 2;
    if (!slotOk) {
        slotOk = v->v11() == 3;
    }
    if (slotOk && DAT_0034a114->flagF9 == 0) {
        FUN_00022418(&r, v->v6(), &self->pos);
        copy = r;
        v->v7(&copy);
    }
}
