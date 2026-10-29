/* HSTMATCH module=EBOOT.BIN start=0x0015070c end=0x00150808 symbol=FUN_0015070c lang=c++ data=0x002dc3f8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: FUN_0014d044 takes a second int in a1 that it ignores; FUN_0014d044(param_2, param_2) keeps a1 live at the first call, which moves param_2's home copy into the beqz delay slot. Data: its string literals (1 strings, 0x002dc3f8-0x002dc40c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern unsigned char DAT_003403f4; /* when set the command creates nothing */
extern int DAT_0034a114;
extern int DAT_003083cc;
extern int DAT_00308ee0;
extern void FUN_0014d044(ScriptCtx *, ScriptCtx *);
extern void FUN_0014fd94(char *, int, int);
extern void FUN_001cbedc(int, ScriptActor *, int, int);
extern int FUN_00000bcc(int);
}

struct VC_3 {
    virtual void reset(int);
    virtual int run(float, ScriptCtx *);
};

/* Script command "EventText": create the event-text object and run it; returns it, or 0 when it finished at once. */
extern "C" VC_3 *FUN_0015070c(ScriptCmd *cmd, ScriptCtx *ctx, float progress)
{
    VC_3 *obj;
    int failed;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx, ctx);
        FUN_0014fd94("EventText [%d, %s]\n", cmd->arg1, cmd->arg0);
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cbedc(DAT_0034a114, ctx->actor, cmd->arg1, cmd->arg0);
    if ((obj = (VC_3 *)FUN_00000bcc(4)) != 0) {
        *(int *)obj = (int)&DAT_003083cc;
        *(int *)obj = (int)&DAT_00308ee0;
    }
    failed = obj->run(progress, ctx);
    if (failed != 0) {
        if (obj != 0 && obj != 0) obj->reset(1);
        return 0;
    }
    return obj;
}
