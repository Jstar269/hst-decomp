/* HSTMATCH module=EBOOT.BIN start=0x00153418 end=0x00153500 symbol=FUN_00153418 lang=c++ data=0x002dc74c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc74c-0x002dc75d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/script_cmd.h"

struct Mgr_00153418;
extern "C" {
extern unsigned char DAT_003402f0; /* script trace flag */
extern Mgr_00153418 *DAT_0034a114;
void FUN_0014d044(ScriptCtx *ctx);
void FUN_0014fd94(char *fmt, ...);
void FUN_0022c890(int id);
void FUN_001cc77c(Mgr_00153418 *mgr, int id);
}

class C_0014c8cc {
public:
  virtual ~C_0014c8cc();
  virtual int Init(float amount, ScriptCtx *ctx) = 0;
};

class C_00153418 : public C_0014c8cc {
public:
  virtual ~C_00153418();
  virtual int Init(float amount, ScriptCtx *ctx);
};

/* Script command "StageUnlock": arg0 is the 1-based stage id; builds the command object and runs its init. */
extern "C" C_0014c8cc *FUN_00153418(ScriptCmd *cmd, float amount, ScriptCtx *ctx)
{
  if (DAT_003402f0) {
    FUN_0014d044(ctx);
    FUN_0014fd94("StageUnlock[%d]\n", cmd->arg0);
  }
  FUN_0022c890(cmd->arg0 - 1);
  FUN_001cc77c(DAT_0034a114, cmd->arg0);
  C_0014c8cc *action = new C_00153418;
  if (action->Init(amount, ctx)) {
    if (action)
      delete action;
    return 0;
  }
  return action;
}
