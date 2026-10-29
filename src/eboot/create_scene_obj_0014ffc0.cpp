/* HSTMATCH module=EBOOT.BIN start=0x0014ffc0 end=0x001500b8 symbol=FUN_0014ffc0 lang=c++ data=0x002dc394 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc394-0x002dc3a2) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"
#include "hst/vtable_obj.h"

extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern unsigned char DAT_003403f4; /* script commands suppressed */
extern int DAT_0034a114;
extern int DAT_003083cc;
extern int DAT_00308f98;
extern void FUN_0014d044(ScriptCtx *, ScriptCtx *);
extern void FUN_0014fd94(char *, int);
extern void FUN_001cbccc(int, ScriptActor *, int, int);
extern int FUN_00000bcc(int);
}

/* Task object created by the command (its vtable is only written here). */
struct TaskObj {
    virtual void reset(int);
    virtual int run(float, ScriptCtx *);
};

/* Script command "TextOut": show a text, then create and start a task object for it. Returns the task when it
   keeps running, 0 when it finished immediately or the commands are suppressed. */
extern "C" TaskObj *FUN_0014ffc0(ScriptCmd *cmd, ScriptCtx *ctx, float time)
{
    TaskObj *task;
    int finished;

    if (DAT_003402f0 != 0) {
        FUN_0014d044(ctx, ctx);
        FUN_0014fd94("TextOut [%s]\n", cmd->arg0);
    }
    if (DAT_003403f4 != 0) {
        return 0;
    }
    FUN_001cbccc(DAT_0034a114, ctx->actor, cmd->arg0, 0xffffffff);
    if ((task = (TaskObj *)FUN_00000bcc(4)) != 0) {
        ((VtableObj *)task)->vtable = &DAT_003083cc;
        ((VtableObj *)task)->vtable = &DAT_00308f98;
    }
    finished = task->run(time, ctx);
    if (finished != 0) {
        if (task != 0 && task != 0) task->reset(1);
        return 0;
    }
    return task;
}
// Virtual calls remain necessary; a virtual destructor shifts the method slots.
