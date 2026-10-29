/* HSTMATCH module=EBOOT.BIN start=0x0015371c end=0x00153818 symbol=FUN_0015371c lang=c++ data=0x002dc7ac */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: FUN_0014d044 takes a second int in a1 that it ignores; FUN_0014d044(param_2, param_2) keeps a1 live at the first call, which moves param_2's home copy into the beqz delay slot. Data: its string literals (1 strings, 0x002dc7ac-0x002dc7c8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern unsigned char DAT_003403f4;
extern int DAT_0034a114;
extern int DAT_003083cc;
extern int DAT_00308a20;
extern void FUN_0014d044(ScriptCtx *, ScriptCtx *);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_001cc190(int, ScriptActor *, int, int);
extern int FUN_00000bcc(int);
}

/* The command object created by the factory: virtual destroy (slot 0) and init (slot 1). */
struct CmdObject {
    virtual void Destroy(int);
    virtual int Init(float, ScriptCtx *);
};

/* Script command "EventTextNpcIndex": arg0/arg1 identify the NPC text; returns the new command object or 0. */
extern "C" CmdObject *FUN_0015371c(ScriptCmd *cmd, ScriptCtx *ctx, float t)
{
    CmdObject *obj;
    int failed;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx, ctx);
        FUN_0014fd94("EventTextNpcIndex [%d, %d]\n", cmd->arg0, cmd->arg1);
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cc190(DAT_0034a114, ctx->actor, cmd->arg1, cmd->arg0);
    if ((obj = (CmdObject *)FUN_00000bcc(4)) != 0) {
        *(int *)obj = (int)&DAT_003083cc;  /* base class vtable */
        *(int *)obj = (int)&DAT_00308a20;  /* derived class vtable */
    }
    failed = obj->Init(t, ctx);
    if (failed != 0) {
        if (obj != 0 && obj != 0) obj->Destroy(1);
        return 0;
    }
    return obj;
}
